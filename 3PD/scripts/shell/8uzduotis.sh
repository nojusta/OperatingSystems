#!/bin/bash
# 8 užduotis: Išveda nurodyto failo turinį tarp pasirinktų eilučių.

if [ "$#" -ne 3 ]; then
    echo "Naudojimas: $0 <failas> <pradzios_eilute> <pabaigos_eilute>"
    exit 1
fi

failas="$1"
start="$2"
end="$3"

# Patikrinam ar failas egzistuoja
if [ ! -f "$failas" ]; then
    echo "Failas \"$failas\" nerastas."
    exit 1
fi

# Patikrinam ar abu argumentai yra skaičiai
if ! [[ "$start" =~ ^[0-9]+$ && "$end" =~ ^[0-9]+$ ]]; then
    echo "Eilučių numeriai turi būti sveiki skaičiai."
    exit 1
fi

# Patikrinam ar pradžios eilutė nėra didesnė už pabaigos
if [ "$start" -gt "$end" ]; then
    echo "Pradžios eilutė negali būti didesnė už pabaigos eilutę."
    exit 1
fi

# Išvedam nurodytą eilučių intervalą
sed -n "${start},${end}p" "$failas"