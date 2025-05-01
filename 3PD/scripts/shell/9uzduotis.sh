#!/bin/bash
# 9 užduotis: Trina visus failus aplanke, kurių turinyje yra nurodytas žodis.

if [ -z "$1" ]; then
    echo "Naudojimas: $0 <zodis>"
    exit 1
fi

zodis="$1"
rasta=0

# Einame per visus paprastus failus dabartiniame kataloge
for file in *; do
    if [ -f "$file" ] && grep -q "$zodis" "$file"; then
        rm "$file"
        echo "Ištrintas: $file"
        rasta=1
    fi
done

if [ "$rasta" -eq 0 ]; then
    echo "Failų, kurių turinyje yra žodis \"$zodis\", nerasta."
fi