#!/bin/bash
# 2 užduotis:
# Vienu metu panaudojame komandas date ir who.
# Komanda date išveda datą į ekraną, o who rezultatas nukreipiamas į failą "Stankevicius".

date            # Ši komanda išveda datą į ekraną
who > Stankevicius   # Ši komanda nukreipia prisijungusių vartotojų sąrašą į failą "Stankevicius"
more Stankevicius    # Ši komanda leidžia peržiūrėti failo "Stankevicius" turinį