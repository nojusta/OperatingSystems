# 7 užduotis: Nustato, kiek laiko dabartinis naudotojas dirba sistemoje (nuo paskutinio paleidimo)
# Naudojimas: .\7uzduotis.ps1

# Windows Home neturi UNIX 'who', todėl rodoma sistemos veikimo trukmė nuo paskutinio paleidimo

$uptime = (Get-Date) - (Get-CimInstance Win32_OperatingSystem).LastBootUpTime
Write-Host "Dabartinis vartotojas '$(whoami)' sistemoje nuo paskutinio paleidimo:"
Write-Host "$($uptime.Days)d $($uptime.Hours)h $($uptime.Minutes)m $($uptime.Seconds)s"