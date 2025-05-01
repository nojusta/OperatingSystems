#!/bin/bash
# 5 užduotis:
# Scenarijus priima vieną argumentą ir nustato, ar tai failas, direktorija ar kažkas kita.

if [ -z "$1" ]; then
    echo "Naudojimas: $0 <kelias>"
    exit 1
fi

input="$1"

if [ -f "$input" ]; then
    echo "\"$input\" yra FAILAS."
elif [ -d "$input" ]; then
    echo "\"$input\" yra DIREKTORIJA."
else
    echo "\"$input\" yra KAŽKAS KITO (galbūt neegzistuoja)."
fi