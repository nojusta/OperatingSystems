#!/bin/bash
# 3 užduotis:
# Naudojame sed komandą, kad kiekvienoje eilutėje sukeistume pirmą ir antrą žodžius.
# Pavyzdys: "Labas rytas pasauli" -> "rytas Labas pasauli"

# Tikriname, ar nurodytas failas kaip argumentas
if [ $# -ne 1 ]; then
  echo "Naudojimas: $0 <failas>"
  exit 1
fi

# Sukeičiame pirmą ir antrą žodžius kiekvienoje eilutėje ir išvedame rezultatą į ekraną
sed -E 's/^([^\ ]+)\ ([^\ ]+)/\2 \1/' "$1"