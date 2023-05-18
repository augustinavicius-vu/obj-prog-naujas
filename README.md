# Objektinis programavimas
2022/2023 metų 2 (pavasario) semestro objektinio programavimo dalyko atsiskaitomasis darbas. Šis darbas yra sudarytas iš keletos versijų, kurios, pagal dėstytojo duotus nurodymus, yra vis tobulinamos.

# Kaip sukompiliuoti šią programą?
## Linux
Ši programa naudojasi C++11 (c++0x) programavimo kalba, tad norit ją sukompiliuoti būtina per atsisiųsti reikalingus įrankius kaip g++ ir make (makefile'ui). Šiuos įrankius lengviausiai įmanoma įsidiegti naudojant šią komandą (Ubuntu):

```bash
sudo apt install build-essential  
```

Vėliau pagrindinėje direktorijoje pakanka paleisti `make` komandą ir atsiras output failas, kuris ir yra pagrindinis šios programos failas.

SVARBU: Makefile failas naudoja c++0x, tačiau tai kuriose operacinėse sistemose naudojamas c++11 užrašymas, tad jei kompiliatorius meta klaidą dėl makefile, galimas daiktas, kad reikia pakesiti makefile eilutes kur naudojamas c++0x. Pavyzdžiui:

```bash
g++ -std=c++0x -c main.cpp
```

į:

```bash
g++ -std=c++11 -c main.cpp
```

# Windows
Labai patariu suinstaliuoti MinGW paketų tvarkyklę, kuri leis greitai ir patogiai atsisiųsti tiek make, tiek kompiliatoriui reikalingus failus. Makefile atsisiųsti ir įsidiegti galima pagal šitą [nuorodą](https://linuxhint.com/run-makefile-windows/). Norint sukompiliuoti kodą eiliškumas yra labai panašus į make atsisiuntimą, daugiau apie tai galima rasti [čia](https://www.ics.uci.edu/~pattis/common/handouts/mingweclipse/mingw.html).

Vėliau pagrindinėje direktorijoje pakanka paleisti `make` komandą ir atsiras output failas, kuris ir yra pagrindinis šios programos failas.

PATARIMAS: Jeigu įmanoma, patariu susikurti [Windows Ubuntu WSL](https://learn.microsoft.com/en-us/windows/wsl/install)

# Testai
Visi testai atlikti naudojant:
- CPU: AMD EPYC™ 7702
- RAM: 16 GB DDR4 RAM (ECC)
- SSD

## Programos spartos analizė
_Visur yra sugeneruojami 15 namų darbų pažymiai ir vienas egzamino pažymys_
1.000 įrašų:
![image](https://imgur.com/a/ObEqSQu.jpg)
10.000 įrašų:
![image](https://imgur.com/a/7uPxOqT.jpg)
100.000 įrašų:
![image](https://imgur.com/a/4G19f4d.jpg)
1.000.000 įrašų:
![image](https://imgur.com/a/7AeqX23.jpg)

## Konteinerių spartos analizė
1.000
![image](https://imgur.com/a/PfmJcYK.jpg)
10.000
![image](https://imgur.com/a/vSvU6uf.jpg)
100.000
![image](https://imgur.com/a/chzQscp.jpg)
1.000.000
![image](https://imgur.com/a/Vo2ZGkm.jpg)

# Versijos
Čia nurodyti trumpi versijų aprašymai, daugiau informacijos [releases](https://github.com/augustinavicius-vu/obj-prog/releases) puslapyje.
## Versija 0.5
- Sukurtas naujas meniu punktas „Konteinerių veikimo greičio analizė“
- NaujasStudentas, RikiuotiStudentus, RusiuotiStudentusBalas funkcijos dabar naudoja `template` ir jų dizainas pritaikytas palaikyti vector, list ir deque konteinerius
- Atliktas konteinerių greičio išmatavimas

## Versija 0.4
- Sukurtas naujas meniu punktas „Programos spartos analizė“
- Atskiras meniu punktas su visomis atskiromis funkcijomis sukurti, nuskaityti, surūšiuoti ir išvesti į failą įrašus
- Atliktas bendras ir skirtingų programos etapų spartos išmatavimas

## Versija 0.3
- Reorganizuotas kodas į skirtingus failus

## Versija 0.2
- Programa gali nuskaityti duomenis iš failo
- Studentų išvestis dabar viename puslapyje gali pateikti vidurkį ir medianą

## Versija 0.1
- Studentų satruktūros
- Bazinis meniu naudotojui
- Vidurkio, medianos skaičiavimo funkcijos
- Kodas gali realizuoti masyvus ir vektoriaus konteinerį

# Autorius
- [@augustinavicius-vu](https://www.github.com/augustinavicius-vu)
