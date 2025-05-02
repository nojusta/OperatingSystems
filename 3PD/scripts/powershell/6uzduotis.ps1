# 6 uzduotis: Pervadinti failus taip, kad vardas butu DIDZIOSIOMIS, pletinys lieka mazosios.
# Naudojimas: .\6uzduotis.ps1 file1 file2 [file3 ...]

param(
    [Parameter(Mandatory=$true, ValueFromRemainingArguments=$true)]
    [string[]]$failai
)

foreach ($original in $failai) {
    # Gauname pilna kelia ir patikrinam ar tai failas
    try {
        $originalItem = Get-Item -LiteralPath $original -ErrorAction Stop
        if ($originalItem.PSIsContainer) {
            Write-Host "Elementas '$original' yra direktorija, praleidziam."
            continue
        }
        $originalFullPath = $originalItem.FullName
    } catch {
        Write-Host "Failas '$original' neegzistuoja arba ivyko klaida tikrinant: $($_.Exception.Message)"
        continue
    }

    $filename = $originalItem.Name
    $dirname = $originalItem.DirectoryName

    # Sukuriam nauja varda (vardas didziosiomis, pletinys lieka koks buvo)
    if ($filename -match '\.') {
        $namePart = $filename.Substring(0, $filename.LastIndexOf('.'))
        $extensionPart = $filename.Substring($filename.LastIndexOf('.')) # Paimam taska kartu su pletiniu
        $newName = "$($namePart.ToUpper())$extensionPart"
    } else {
        $newName = $filename.ToUpper()
    }

    $targetFullPath = Join-Path $dirname $newName

    # 1. Patikrinam ar vardas jau yra tiksliai toks, kokio norim (su didziosiom raidem)
    if ($filename -ceq $newName) { # -ceq lygina case-sensitive
        Write-Host "Failas '$original' jau yra tinkamo formato, praleidziam."
        continue
    }

    # 2. Patikrinam ar failas tokiu vardu (case-insensitive) jau egzistuoja IR tai NERA tas pats failas
    $targetExists = Test-Path -LiteralPath $targetFullPath -PathType Leaf
    if ($targetExists) {
        try {
            $targetItem = Get-Item -LiteralPath $targetFullPath -ErrorAction Stop
            if ($targetItem.FullName -ne $originalFullPath) {
                Write-Host "Failas '$newName' jau egzistuoja (kitas failas), praleidziam '$original'."
                continue
            }
            # Jei egzistuoja ir tai TAS PATS failas, reiskia skiriasi tik raides - leidziam pervadinti
        } catch {
             Write-Host "Negalima patikrinti '$targetFullPath', praleidziam '$original'."
             continue
        }
    }

    # 3. Bandom pervadinti
    try {
        Rename-Item -LiteralPath $originalFullPath -NewName $newName -ErrorAction Stop
        Write-Host "Pervardinta: '$original' -> '$newName'"
    } catch {
        Write-Host "Nepavyko pervadinti '$original' i '$newName': $($_.Exception.Message)"
    }
}