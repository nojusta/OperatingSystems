#!/bin/bash
# 7 užduotis:
# Scenarijus, kuris nustato, kiek laiko naudotojas dirba sistemoje.
# Naudotojo vardas perduodamas kaip parametras.

if [ -z "$1" ]; then
    echo "Naudojimas: $0 <naudotojo_vardas>"
    exit 1
fi

naudotojas="$1"
rastas=0

while read -r user terminal month day time rest; do
    if [ "$user" = "$naudotojas" ]; then
        rastas=1
        loginlaikas="$month $day $time"
        prisijunges_kaip="$terminal"
        metai=$(date +%Y)
        # Pridedam metus prie datos
        loginlaikas_full="$month $day $metai $time"
        # Konvertuojam į epoch laiką
        prisijunges_epoch=$(date -j -f "%b %d %Y %H:%M" "$loginlaikas_full" +%s 2>/dev/null)
        dabar_epoch=$(date +%s)
        skirtumas=$(( dabar_epoch - prisijunges_epoch ))

        val=$((skirtumas / 3600))
        min=$(( (skirtumas % 3600) / 60 ))
        sek=$((skirtumas % 60 ))

        echo "Naudotojas \"$naudotojas\" sistemoje yra: ${val}h ${min}m ${sek}s (prisijungęs kaip $prisijunges_kaip)"
    fi
done < <(who)

if [ "$rastas" -eq 0 ]; then
    echo "Naudotojas \"$naudotojas\" neprisijungęs arba neegizistuoja."
fi