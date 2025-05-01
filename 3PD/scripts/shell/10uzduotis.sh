#!/bin/bash
# 10 užduotis: Apjungia kas dvi eilutes į vieną, apskaičiuoja naujų eilučių ilgius ir išveda į ekraną.

if [ -z "$1" ]; then
    echo "Naudojimas: $0 <failas>"
    exit 1
fi

failas="$1"

if [ ! -f "$failas" ]; then
    echo "Failas \"$failas\" nerastas."
    exit 1
fi

# Apjungia kas dvi eilutes, apskaičiuoja ilgį ir išveda
awk '{
    if (NR % 2 == 1) {
        eilute = $0
    } else {
        eilute = eilute " " $0
        print "ilgis: " length(eilute) " | turinys: " eilute
        eilute = ""
    }
}
END {
    if (eilute != "") {
        print "ilgis: " length(eilute) " | turinys: " eilute
    }
}' "$failas"