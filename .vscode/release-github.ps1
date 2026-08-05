<#
.SYNOPSIS
    Tags, checksums, and publishes the signed SoftStep Editors Windows
    installer as a GitHub Release on Muse-Kinetics/softstep_editor.

.DESCRIPTION
    Reads the release version from SoftStepAdvanced.pro (single source of
    truth, same as make-installer.ps1), locates the installer that script
    produces at win-deploy\SoftStep Editors v<version> Windows Installer.exe,
    verifies it carries a valid Authenticode signature, extracts that
    version's release notes from CHANGELOG.md, writes a .sha256 checksum
    next to the installer, then creates an annotated git tag, pushes it,
    and runs `gh release create` with the installer + checksum attached.

    This does NOT build or sign anything itself - run
    ".vscode\make-installer.ps1" first (without -DisableSigning) so a real
    signed installer exists. Signing requires the office code-signing token,
    so this script is expected to sit unused until then.

.PARAMETER DryRun
    Validate everything (version, installer presence, signature, changelog
    section) and print exactly what would be tagged/published, but do not
    create the git tag, push it, or call `gh release create`. Safe to run
    at any time, including against an unsigned test installer with
    -AllowUnsigned.

.PARAMETER AllowUnsigned
    Skip the Authenticode signature check. Only intended for -DryRun
    mechanics testing - never combine with a real publish.

.EXAMPLE
    .\release-github.ps1 -DryRun -AllowUnsigned
    Sanity-check the script against an unsigned test build without touching
    git or GitHub.

.EXAMPLE
    .\release-github.ps1
    Real publish: requires a signed installer already built. Tags, pushes,
    and creates the public GitHub Release.
#>
param(
    [switch]$DryRun,
    [switch]$AllowUnsigned
)

$ErrorActionPreference = 'Stop'

function Write-Step {
    param([string]$Message)
    Write-Host "`n==> $Message" -ForegroundColor Cyan
}

function Get-VersionFromProFile {
    param([string]$ProFilePath)

    $versionLine = Select-String -Path $ProFilePath -Pattern '^VERSION\s*=\s*(.+)$' | Select-Object -First 1
    if (-not $versionLine) {
        throw "Could not find VERSION in $ProFilePath"
    }

    return $versionLine.Matches[0].Groups[1].Value.Trim()
}

function Get-ChangelogSection {
    param(
        [string]$ChangelogPath,
        [string]$Version
    )

    $lines = Get-Content -LiteralPath $ChangelogPath -Encoding UTF8
    $startIndex = -1
    for ($i = 0; $i -lt $lines.Count; $i++) {
        if ($lines[$i] -match "^### Editor $([regex]::Escape($Version)), ") {
            $startIndex = $i
            break
        }
    }

    if ($startIndex -eq -1) {
        throw "Could not find a '### Editor $Version, ...' section in $ChangelogPath. Add a CHANGELOG entry for this version first."
    }

    $endIndex = $lines.Count - 1
    for ($i = $startIndex + 1; $i -lt $lines.Count; $i++) {
        if ($lines[$i] -match '^### ') {
            $endIndex = $i - 1
            break
        }
    }

    return ($lines[$startIndex..$endIndex] -join "`n").Trim()
}

$workspaceRoot = Split-Path -Parent $PSScriptRoot
$advancedPro = Join-Path $workspaceRoot 'standalone\advanced\SoftStepAdvanced.pro'
$changelogPath = Join-Path $workspaceRoot 'CHANGELOG.md'
$winDeployRoot = Join-Path $workspaceRoot 'win-deploy'

$version = Get-VersionFromProFile -ProFilePath $advancedPro
$tagName = "v$version"
$installerName = "SoftStep Editors v$version Windows Installer.exe"
$installerPath = Join-Path $winDeployRoot $installerName
$checksumPath = "$installerPath.sha256"

Write-Host "Version: $version"
Write-Host "Tag: $tagName"
Write-Host "Installer: $installerPath"
if ($DryRun) {
    Write-Host "Mode: DRY RUN (no tag/push/publish)" -ForegroundColor Yellow
}

if (-not (Test-Path -LiteralPath $installerPath)) {
    throw "Installer not found at '$installerPath'. Run .vscode\make-installer.ps1 first."
}

Write-Step 'Checking Authenticode signature'
$signature = Get-AuthenticodeSignature -LiteralPath $installerPath
if ($signature.Status -ne 'Valid') {
    if ($AllowUnsigned) {
        Write-Host "Installer is not validly signed (status: $($signature.Status)) - continuing because -AllowUnsigned was passed." -ForegroundColor Yellow
    } else {
        throw "Installer is not validly signed (status: $($signature.Status)). Sign it (requires the office code-signing token) before publishing, or pass -AllowUnsigned for a -DryRun mechanics test only."
    }
} else {
    Write-Host "Signed by: $($signature.SignerCertificate.Subject)" -ForegroundColor Green
}

Write-Step 'Extracting release notes from CHANGELOG.md'
$notes = Get-ChangelogSection -ChangelogPath $changelogPath -Version $version
Write-Host $notes

Write-Step 'Computing SHA256 checksum'
$hash = Get-FileHash -Algorithm SHA256 -LiteralPath $installerPath
$hashLine = "$($hash.Hash.ToLower())  $installerName"
Write-Host $hashLine

if ($DryRun) {
    Write-Host "`nDry run complete. Would tag $tagName, push it, write $checksumPath, and run:" -ForegroundColor Yellow
    Write-Host "  gh release create $tagName `"$installerPath`" `"$checksumPath`" --repo Muse-Kinetics/softstep_editor --title `"SoftStep Editors $tagName`" --notes-file <notes>" -ForegroundColor Yellow
    exit 0
}

Set-Content -Path $checksumPath -Value $hashLine -Encoding ascii
Write-Host "Wrote $checksumPath"

Write-Step "Tagging $tagName"
Push-Location $workspaceRoot
try {
    $existingTag = git tag --list $tagName
    if ($existingTag) {
        throw "Tag $tagName already exists locally. Delete it first (git tag -d $tagName) if you intend to re-tag, or bump VERSION if this is a new release."
    }
    git tag -a $tagName -m "SoftStep Editors $tagName"
    if ($LASTEXITCODE -ne 0) { throw "git tag failed." }

    Write-Step "Pushing $tagName to github"
    git push github $tagName
    if ($LASTEXITCODE -ne 0) { throw "git push failed." }
}
finally {
    Pop-Location
}

Write-Step 'Creating GitHub Release'
$notesFile = Join-Path ([System.IO.Path]::GetTempPath()) "softstep-release-notes-$version.md"
Set-Content -Path $notesFile -Value $notes -Encoding utf8

gh release create $tagName "$installerPath" "$checksumPath" `
    --repo Muse-Kinetics/softstep_editor `
    --title "SoftStep Editors $tagName" `
    --notes-file $notesFile

if ($LASTEXITCODE -ne 0) { throw "gh release create failed." }

Remove-Item -Force $notesFile -ErrorAction SilentlyContinue

Write-Host "`nPublished: https://github.com/Muse-Kinetics/softstep_editor/releases/tag/$tagName" -ForegroundColor Green
