# 8 uzduotis: Isveda nurodyto failo turini tarp pasirinktu eiluciu.
# Naudojimas: .\8uzduotis.ps1 <failas> <pradzios_eilute> <pabaigos_eilute>

param(
    [Parameter(Mandatory=$true)]
    [string]$Failas,

    [Parameter(Mandatory=$true)]
    [int]$Pradzia,

    [Parameter(Mandatory=$true)]
    [int]$Pabaiga
)

if (-not (Test-Path $Failas -PathType Leaf)) {
    Write-Host "Failas '$Failas' nerastas."
    exit 1
}

if ($Pradzia -lt 1 -or $Pabaiga -lt 1) {
    Write-Host "Eiluciu numeriai turi buti teigiami skaiciai."
    exit 1
}
if ($Pradzia -gt $Pabaiga) {
    Write-Host "Pradzios eilute negali buti didesne uz pabaigos eilute."
    exit 1
}

$eilutes = Get-Content $Failas
$eiluciuSkaicius = $eilutes.Count

for ($i = $Pradzia; $i -le $Pabaiga; $i++) {
    if ($i -le $eiluciuSkaicius) {
        Write-Host $eilutes[$i - 1]
    }
}