# Komandinės eilutės scenarijų kūrimas su Bash, PowerShell ir C

## 1. Darbo tikslas
Susipažinti su Linux OS Bash ir Windows OS PowerShell komandinėmis eilutėmis. Išsiaiškinti komandų veikimą, panaudojimo atvejus. Išmokti kurti komandų paleidimo scenarijų failus. Ištirti tokių failų veikimą kompiuteryje.

## 2. Darbo eiga

Visos užduotys atliekamos **tiek UNIX (bash), tiek PowerShell (Windows)** aplinkose. Toliau pateikiama struktūra ir užduočių aprašymai.

---

1. **Naudojant komandą `who` nukreipkite jos įvykdymo rezultatą į failą Nojus.**  
   Paleiskite komandą `more` failo Nojus peržiūrai.

2. **Panaudokite komandas `date` ir `who` vienu metu (vienoje eilutėje):**  
   - `date` išvedimas turi būti matomas ekrane;  
   - `who` rezultatas turi būti nukreiptas į failą "Stankevicius".  
   Patikrinkite failo "Stankevicius" turinį su komanda `more`.

3. **Raskite informaciją apie komandą `sed` ir sukurkite jos panaudojimą taip, kad kiekvienoje eilutėje būtų sukeisti pirmas ir antras žodžiai.**

4. **Sukurkite dvi programas ir pamatuokite jų veikimo laiką naudodami komandą `time`:**
   - **4.1 programa** – Shell (ar PowerShell) scenarijus, išvedantis į ekraną jūsų vardą ir pavardę.
   - **4.2 programa** – C programa, išvedanti jūsų vardą ir pavardę.
    **4.3 programa – C programa su MPI arba OMP biblioteka.**  
   Apskaičiuokite visas galimas funkcijos reikšmes ir pateikite rezultatą – funkcijos optimumą.  
   - Jeigu studento ID **lyginis** – naudoti **f_max(x, y)**  
   - Jeigu studento ID **nelyginis** – naudoti **f_min(x, y)**
   - Mano studento ID – 2314009
    **Funkcija:** f(x, y) = 100*y - x² + (1 - x²)

    **Intervalai:**
    - x ∈ [ - (ID mod 39 + 1) / 39 ; (ID mod 39 + 1) / 39 ]
    - y ∈ [ - (ID mod 35 + 1) / 35 ; (ID mod 65 + 1) / 35 ]

    **Žingsniai:**
    - Δx = 0.0000001  
    - Δy = 0.0000003

    **Papildomai:**
    - Išmatuokite apskaičiavimo greitį su 1, 2, 3, 4 ... MAX (log_CPU_NR) procesoriais.
    - Sudarykite **greitaveikos kreivę**.

---

5. **Sukurkite scenarijų, kuris priima komandinės eilutės argumentą ir pateikia informaciją, kas tai yra:**
- Failo vardas,
- Direktorijos vardas,
- Arba kažkas kita.

6. **Sukurkite scenarijų, kuriam perduodami dviejų ar daugiau failų vardai.**  
Scenarijus turi pervardinti juos į tą patį pavadinimą, tik visos raidės turi būti **didžiosios**, jeigu tokie dar neegzistuoja darbo direktorijoje.

7. **Sukurkite scenarijų, kuris nustato, kiek laiko naudotojas dirba sistemoje.**  
Naudotojo vardas perduodamas kaip parametras.

8. **Sukurkite scenarijų, kuris priima:**
- Failo vardą,
- Pradžios ir pabaigos eilučių numerius,  
Ir išveda į ekraną failo turinį tarp nurodytų eilučių.

9. **Sukurkite scenarijų, trinantį visus failus aplanke, kurie savo turinyje turi žodį perduotą kaip parametras.**

10. **Sukurkite scenarijų, kuriam perduodamas tekstinio failo vardas. Scenarijus turi atlikti šiuos veiksmus:**
 - Apjungti kas dvi eilutes į vieną.
 - Apskaičiuoti naujų eilučių ilgius.
 - Išvesti šią informaciją į ekraną.

---

📝 **Pastaba:**  
Visus žingsnius uždokumentuokite **pridedant komentarus**, net jei kažkas nepavyko – aprašykite kodėl.
