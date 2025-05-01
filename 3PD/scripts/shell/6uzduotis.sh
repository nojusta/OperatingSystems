#!/bin/bash
# 6 užduotis: Pervadinti failus taip, kad vardas būtų didžiosiomis, o plėtinys liktų mažosiomis.

if [ "$#" -lt 2 ]; then
    echo "Naudojimas: $0 failas1 failas2 [failas3 ...]"
    exit 1
fi

for original in "$@"; do
    if [ ! -f "$original" ]; then
        echo "Failas \"$original\" neegzistuoja, praleidžiam."
        continue
    fi

    filename="$(basename "$original")"
    dirname="$(dirname "$original")"

    if [[ "$filename" == *.* ]]; then
        name="${filename%.*}"
        ext="${filename##*.}"
        upper="$(echo "$name" | tr '[:lower:]' '[:upper:]').$ext"
    else
        upper="$(echo "$filename" | tr '[:lower:]' '[:upper:]')"
    fi

    # Jei jau reikiamu formatu, praleidžiam
    if [ "$filename" = "$upper" ]; then
        echo "Failas \"$original\" jau yra reikiamu formatu, praleidžiam."
        continue
    fi

    # Pervardinimas
    mv "$original" "$dirname/$upper"

    # išvestis: jei dirname yra ".", rodo tik failo vardą
    if [ "$dirname" = "." ]; then
        echo "Pervardintas: \"$original\" → \"$upper\""
    else
        echo "Pervardintas: \"$original\" → \"$dirname/$upper\""
    fi
done