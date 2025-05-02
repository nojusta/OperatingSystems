# 10 uzduotis: Apjungia kas dvi eilutes i viena, apskaiciuoja nauju eiluciu ilgius ir isveda i ekrana.
# Naudojimas: .\10uzduotis.ps1 <failas>

param(
    [Parameter(Mandatory=$true)]
    [string]$Failas
)

# Patikrinam ar failas egzistuoja
if (-not (Test-Path $Failas -PathType Leaf)) {
    Write-Host "Failas '$Failas' nerastas."
    exit 1
}

$eilutes = Get-Content $Failas
$pirmaEilute = $null

for ($i = 0; $i -lt $eilutes.Count; $i++) {
    if ($i % 2 -eq 0) {
        # Nelyginis indeksas (pirma eilute is poros)
        $pirmaEilute = $eilutes[$i]
    } else {
        # Lyginis indeksas (antra eilute is poros)
        $apjungta = "$pirmaEilute $($eilutes[$i])"
        Write-Host "ilgis: $($apjungta.Length) | turinys: $apjungta"
        $pirmaEilute = $null # Nuresetinam kitai porai
    }
}

# Patikrinam ar neliko neapjungtos paskutines eilutes (jei eiluciu skaicius nelyginis)
if ($null -ne $pirmaEilute) {
    Write-Host "ilgis: $($pirmaEilute.Length) | turinys: $pirmaEilute"
}