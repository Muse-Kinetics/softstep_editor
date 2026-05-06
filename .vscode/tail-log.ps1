param(
    [Parameter(Mandatory = $true)]
    [string]$LogPath
)

if (!(Test-Path $LogPath)) {
    New-Item -ItemType File -Path $LogPath -Force | Out-Null
}

Get-Content -Path $LogPath -Wait -Tail 40