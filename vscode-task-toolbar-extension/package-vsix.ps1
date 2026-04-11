$ErrorActionPreference = 'Stop'

$root = Split-Path -Parent $MyInvocation.MyCommand.Path
$packageJsonPath = Join-Path $root 'package.json'
$packageJson = Get-Content $packageJsonPath -Raw | ConvertFrom-Json

$stageRoot = Join-Path $root '.vsix-stage'
$extensionRoot = Join-Path $stageRoot 'extension'
$vsixName = '{0}-{1}.vsix' -f $packageJson.publisher, $packageJson.name
$zipPath = Join-Path $root ($vsixName + '.zip')
$vsixPath = Join-Path $root $vsixName
$manifestPath = Join-Path $stageRoot 'extension.vsixmanifest'
$contentTypesPath = Join-Path $stageRoot '[Content_Types].xml'

if (Test-Path $stageRoot) {
    Remove-Item $stageRoot -Recurse -Force
}

if (Test-Path $zipPath) {
    Remove-Item $zipPath -Force
}

if (Test-Path $vsixPath) {
    Remove-Item $vsixPath -Force
}

New-Item -ItemType Directory -Path $extensionRoot | Out-Null
Copy-Item (Join-Path $root 'package.json') (Join-Path $extensionRoot 'package.json')
Copy-Item (Join-Path $root 'README.md') (Join-Path $extensionRoot 'README.md')
Copy-Item (Join-Path $root '.vscodeignore') (Join-Path $extensionRoot '.vscodeignore')
Copy-Item (Join-Path $root 'src') (Join-Path $extensionRoot 'src') -Recurse

$description = [System.Security.SecurityElement]::Escape([string]$packageJson.description)
$displayName = [System.Security.SecurityElement]::Escape([string]$packageJson.displayName)
$publisher = [System.Security.SecurityElement]::Escape([string]$packageJson.publisher)
$name = [System.Security.SecurityElement]::Escape([string]$packageJson.name)
$version = [System.Security.SecurityElement]::Escape([string]$packageJson.version)
$engine = [System.Security.SecurityElement]::Escape([string]$packageJson.engines.vscode)

$manifest = @"
<?xml version="1.0" encoding="utf-8"?>
<PackageManifest Version="2.0.0" xmlns="http://schemas.microsoft.com/developer/vsx-schema/2011">
  <Metadata>
    <Identity Language="en-US" Id="$name" Version="$version" Publisher="$publisher" />
    <DisplayName>$displayName</DisplayName>
    <Description xml:space="preserve">$description</Description>
    <Categories>Other</Categories>
    <Properties>
      <Property Id="Microsoft.VisualStudio.Code.Engine" Value="$engine" />
    </Properties>
  </Metadata>
  <Installation>
    <InstallationTarget Id="Microsoft.VisualStudio.Code" />
  </Installation>
  <Dependencies />
  <Assets>
    <Asset Type="Microsoft.VisualStudio.Code.Manifest" Path="extension/package.json" Addressable="true" />
  </Assets>
</PackageManifest>
"@

$contentTypes = @"
<?xml version="1.0" encoding="utf-8"?>
<Types xmlns="http://schemas.openxmlformats.org/package/2006/content-types">
  <Default Extension="json" ContentType="application/json" />
  <Default Extension="js" ContentType="application/javascript" />
  <Default Extension="md" ContentType="text/markdown" />
  <Default Extension="xml" ContentType="text/xml" />
  <Default Extension="vsixmanifest" ContentType="text/xml" />
</Types>
"@

$manifest | Out-File -FilePath $manifestPath -Encoding utf8
$contentTypes | Out-File -LiteralPath $contentTypesPath -Encoding utf8

Compress-Archive -Path (Join-Path $stageRoot '*') -DestinationPath $zipPath -Force
Rename-Item -Path $zipPath -NewName $vsixName
try {
  Remove-Item $stageRoot -Recurse -Force
}
catch {
}

Write-Output $vsixPath