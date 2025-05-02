# 3 užduotis: Sukeičia pirmą ir antrą žodžius kiekvienoje failo eilutėje
# Naudojimas: .\3uzduotis.ps1 <failas>

param(
    [string]$Failas
)

if (-not $Failas) {
    Write-Host "Naudojimas: .\3uzduotis.ps1 <failas>"
    exit 1
}

Get-Content $Failas | ForEach-Object {
    if ($_ -match '^(\S+)\s+(\S+)(.*)') {
        "$($matches[2]) $($matches[1])$($matches[3])"
    } else {
        $_
    }
}