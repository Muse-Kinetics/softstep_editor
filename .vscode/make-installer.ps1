param(
    [switch]$DisableSigning
)

$ErrorActionPreference = 'Stop'

function Write-Step {
    param([string]$Message)
    Write-Host "`n==> $Message"
}

function Get-VersionFromProFile {
    param([string]$ProFilePath)

    $versionLine = Select-String -Path $ProFilePath -Pattern '^VERSION\s*=\s*(.+)$' | Select-Object -First 1
    if (-not $versionLine) {
        throw "Could not find VERSION in $ProFilePath"
    }

    return $versionLine.Matches[0].Groups[1].Value.Trim()
}

function Set-XmlNodeValue {
    param(
        [string]$FilePath,
        [string]$XPath,
        [string]$Value
    )

    if (-not (Test-Path -LiteralPath $FilePath)) {
        throw "Required XML file not found: $FilePath"
    }

    $xml = New-Object System.Xml.XmlDocument
    $xml.PreserveWhitespace = $true
    $xml.Load($FilePath)

    $node = $xml.SelectSingleNode($XPath)
    if (-not $node) {
        throw "Could not find XML node '$XPath' in $FilePath"
    }

    $node.InnerText = $Value
    $xml.Save($FilePath)
}

function Update-InstallerMetadata {
    param(
        [string]$InstallerVersion,
        [string]$ConfigFile,
        [string[]]$PackageFiles
    )

    Write-Step 'Updating installer metadata versions'
    Set-XmlNodeValue -FilePath $ConfigFile -XPath '/Installer/Version' -Value $InstallerVersion

    foreach ($packageFile in $PackageFiles) {
        Set-XmlNodeValue -FilePath $packageFile -XPath '/Package/Version' -Value $InstallerVersion
    }
}

function Ensure-Directory {
    param([string]$Path)

    if (-not (Test-Path -LiteralPath $Path)) {
        New-Item -ItemType Directory -Path $Path -Force | Out-Null
    }
}

function Copy-RequiredFile {
    param(
        [string]$Source,
        [string]$Destination
    )

    if (-not (Test-Path -LiteralPath $Source)) {
        throw "Required file not found: $Source"
    }

    Copy-Item -LiteralPath $Source -Destination $Destination -Force
}

function Invoke-External {
    param(
        [string]$FilePath,
        [string[]]$ArgumentList,
        [string]$WorkingDirectory
    )

    $displayArgs = ($ArgumentList | ForEach-Object {
        if ($_ -match '\s') { '"' + $_ + '"' } else { $_ }
    }) -join ' '
    Write-Host "$FilePath $displayArgs"

    Push-Location -LiteralPath $WorkingDirectory
    try {
        & $FilePath @ArgumentList
        if ($LASTEXITCODE -ne 0) {
            throw "Command failed with exit code ${LASTEXITCODE}: $FilePath"
        }
    }
    finally {
        Pop-Location
    }
}

function Invoke-Signing {
    param(
        [string]$SignTool,
        [string]$TimestampUrl,
        [string]$FileToSign,
        [string]$WorkingDirectory
    )

    if ($DisableSigning) {
        Write-Host "Skipping signing for $FileToSign because -DisableSigning was supplied."
        return
    }

    Invoke-External -FilePath $SignTool -ArgumentList @(
        'sign', '/v', '/debug', '/a',
        '/tr', $TimestampUrl,
        '/td', 'SHA256',
        '/fd', 'certHash',
        $FileToSign
    ) -WorkingDirectory $WorkingDirectory
}

function Copy-EditorPayload {
    param(
        [string]$PackageDir,
        [string]$ReleaseExe,
        [string]$DisplayName,
        [string]$QtDeployTool,
        [string]$SslCrypto,
        [string]$SslTls,
        [string]$SignTool
    )

    Ensure-Directory -Path $PackageDir

    $mainDest = Join-Path $PackageDir "$DisplayName.exe"

    Write-Step "Staging $DisplayName"
    Copy-RequiredFile -Source $ReleaseExe -Destination $mainDest

    Invoke-Signing -SignTool $SignTool -TimestampUrl 'http://timestamp.digicert.com' -FileToSign $mainDest -WorkingDirectory $PackageDir

    Write-Step "Running windeployqt for $DisplayName"
    Invoke-External -FilePath $QtDeployTool -ArgumentList @(
        '--compiler-runtime',
        '--dir', $PackageDir,
        $mainDest
    ) -WorkingDirectory $PackageDir

    Write-Step "Copying SSL runtime for $DisplayName"
    Copy-RequiredFile -Source $SslCrypto -Destination $PackageDir
    Copy-RequiredFile -Source $SslTls -Destination $PackageDir
}

$workspaceRoot = Split-Path -Parent $PSScriptRoot
$standaloneRoot = Join-Path $workspaceRoot 'standalone'
$winDeployRoot = Join-Path $workspaceRoot 'win-deploy'

$basicPro = Join-Path $standaloneRoot 'ezpz\softstepezpz.pro'
$advancedPro = Join-Path $standaloneRoot 'advanced\SoftStepAdvanced.pro'

$installerVersion = Get-VersionFromProFile -ProFilePath $advancedPro
$installerName = "SoftStep Editors v$installerVersion Windows Installer"
$installerFile = "$installerName.exe"

$qtDeployTool = 'C:\Qt6\6.3.2\msvc2019_64\bin\windeployqt.exe'
$binaryCreator = 'C:\Qt6\QtIFW-4.6.0\bin\binarycreator.exe'
$signTool = 'C:\Program Files (x86)\Windows Kits\10\bin\10.0.22000.0\x64\signtool.exe'

$sslCrypto = Join-Path $workspaceRoot 'shared\KMI_MDM\ssl\libcrypto-1_1-x64.dll'
$sslTls = Join-Path $workspaceRoot 'shared\KMI_MDM\ssl\libssl-1_1-x64.dll'

$basicReleaseDir = Join-Path $standaloneRoot 'build-softstepezpz-Desktop_Qt_6_3_2_MSVC2019_64bit-Release\release'
$advancedReleaseDir = Join-Path $standaloneRoot 'build-SoftStepAdvanced-Desktop_Qt_6_3_2_MSVC2019_64bit-Release\release'

$basicPackageDir = Join-Path $winDeployRoot 'packages\com.keithmcmillen.softstepeditors.basic\data\SoftStep Basic Editor'
$advancedPackageDir = Join-Path $winDeployRoot 'packages\com.keithmcmillen.softstepeditors.advanced\data\SoftStep Advanced Editor'
$contentDir = Join-Path $winDeployRoot 'packages\com.keithmcmillen.softstepeditors.content\data\Content'

$basicReleaseExe = Join-Path $basicReleaseDir 'SoftStep Basic Editor.exe'
$advancedReleaseExe = Join-Path $advancedReleaseDir 'SoftStep Advanced Editor.exe'

$contentSource = Join-Path $workspaceRoot 'Content'
$changelogSource = Join-Path $workspaceRoot 'CHANGELOG.md'
$configFile = Join-Path $winDeployRoot 'config\config.xml'
$packagesDir = Join-Path $winDeployRoot 'packages'
$installerOutputPath = Join-Path $winDeployRoot $installerFile
$basicPackageMetaFile = Join-Path $winDeployRoot 'packages\com.keithmcmillen.softstepeditors.basic\meta\package.xml'
$advancedPackageMetaFile = Join-Path $winDeployRoot 'packages\com.keithmcmillen.softstepeditors.advanced\meta\package.xml'
$contentPackageMetaFile = Join-Path $winDeployRoot 'packages\com.keithmcmillen.softstepeditors.content\meta\package.xml'

Write-Host "Installer version: $installerVersion"
if ($DisableSigning) {
    Write-Host 'Signing is disabled for this run.'
}

Update-InstallerMetadata -InstallerVersion $installerVersion -ConfigFile $configFile -PackageFiles @(
    $basicPackageMetaFile,
    $advancedPackageMetaFile,
    $contentPackageMetaFile
)

Copy-EditorPayload -PackageDir $basicPackageDir -ReleaseExe $basicReleaseExe -DisplayName 'SoftStep Basic Editor' -QtDeployTool $qtDeployTool -SslCrypto $sslCrypto -SslTls $sslTls -SignTool $signTool
Copy-EditorPayload -PackageDir $advancedPackageDir -ReleaseExe $advancedReleaseExe -DisplayName 'SoftStep Advanced Editor' -QtDeployTool $qtDeployTool -SslCrypto $sslCrypto -SslTls $sslTls -SignTool $signTool

Write-Step 'Refreshing installer content package'
if (Test-Path -LiteralPath $contentDir) {
    Remove-Item -LiteralPath $contentDir -Recurse -Force
}
Ensure-Directory -Path $contentDir
Copy-Item -LiteralPath (Join-Path $contentSource '*') -Destination $contentDir -Recurse -Force
Copy-RequiredFile -Source $changelogSource -Destination $contentDir

Write-Step 'Creating installer'
if (Test-Path -LiteralPath $installerOutputPath) {
    Remove-Item -LiteralPath $installerOutputPath -Force
}
Invoke-External -FilePath $binaryCreator -ArgumentList @(
    '--verbose',
    '--offline-only',
    '-c', $configFile,
    '-p', $packagesDir,
    $installerName
) -WorkingDirectory $winDeployRoot

Write-Step 'Signing installer'
Invoke-Signing -SignTool $signTool -TimestampUrl 'http://timestamp.globalsign.com/tsa/advanced' -FileToSign $installerOutputPath -WorkingDirectory $winDeployRoot

Write-Host "`nInstaller created at $installerOutputPath"