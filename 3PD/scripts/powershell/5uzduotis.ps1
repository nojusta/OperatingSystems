# 5 užduotis: Nustato ar argumentas yra failas, direktorija ar kažkas kita
# Naudojimas: .\5uzduotis.ps1 <kelias>

param(
    [string]$Kelias
)

if (-not $Kelias) {
    Write-Host "Naudojimas: .\5uzduotis.ps1 <kelias>"
    exit 1
}

if (Test-Path $Kelias -PathType Leaf) {
    Write-Host "`"$Kelias`" yra FAILAS."
} elseif (Test-Path $Kelias -PathType Container) {
    Write-Host "`"$Kelias`" yra DIREKTORIJA."
} else {
    Write-Host "`"$Kelias`" yra KAZKAS KITO (galbut neegzistuoja)."
}