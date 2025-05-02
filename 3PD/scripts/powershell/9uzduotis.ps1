# 9 uzduotis: Trina visus failus dabartiniame aplanke, kuriu turinyje yra nurodytas zodis.
# Naudojimas: .\9uzduotis.ps1 <zodis>

param(
    [Parameter(Mandatory=$true)]
    [string]$Zodis
)

$istrinta = $false

# Einame per visus failus dabartiniame kataloge
Get-ChildItem -File | ForEach-Object {
    $failas = $_
    if (Select-String -Path $failas.FullName -Pattern $Zodis -Quiet) {
        try {
            Remove-Item -Path $failas.FullName -Force -ErrorAction Stop
            Write-Host "Istrintas: $($failas.Name)"
            $istrinta = $true
        } catch {
            Write-Host "Nepavyko istrinti failo '$($failas.Name)': $($_.Exception.Message)"
        }
    }
}
if (-not $istrinta) {
    Write-Host "Failu, kuriu turinyje yra zodis '$Zodis', nerasta."
}