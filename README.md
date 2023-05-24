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

## Windows

Labai patariu suinstaliuoti MinGW paketų tvarkyklę, kuri leis greitai ir patogiai atsisiųsti tiek make, tiek kompiliatoriui reikalingus failus. Makefile atsisiųsti ir įsidiegti galima pagal šitą [nuorodą](https://linuxhint.com/run-makefile-windows/). Norint sukompiliuoti kodą eiliškumas yra labai panašus į make atsisiuntimą, daugiau apie tai galima rasti [čia](https://www.ics.uci.edu/~pattis/common/handouts/mingweclipse/mingw.html).

Vėliau pagrindinėje direktorijoje pakanka paleisti `make` komandą ir atsiras output failas, kuris ir yra pagrindinis šios programos failas.
Taip pat, norėčiau pridurti, kad projektas taip pat palaiko ir `cmake`, tad galima atsiųsti šiam diegimo procesus reikalingus failus iš [čia](https://github.com/Kitware/CMake/releases/download/v3.26.4/cmake-3.26.4-windows-x86_64.msi) ir tieisog pagrindinėje direktorijoje paleisti `cmake .` komoandos ekvivalentą, norint sukurti paleidžiamą failą.

PATARIMAS: Jeigu įmanoma, patariu susikurti [Windows Ubuntu WSL](https://learn.microsoft.com/en-us/windows/wsl/install)

# Testai

Visi testai atlikti naudojant:

- CPU: AMD EPYC™ 7702
- RAM: 16 GB DDR4 RAM (ECC)
- SSD

## Programos spartos analizė

_Visur yra sugeneruojami 15 namų darbų pažymiai ir vienas egzamino pažymys_

1.000 įrašų:

![image](https://github.com/augustinavicius-vu/obj-prog/assets/101087475/f3d670c9-fba4-4da2-8ef7-f5d20fc5d704)

10.000 įrašų:

![image](https://github.com/augustinavicius-vu/obj-prog/assets/101087475/13b7fee6-0c14-431e-b34b-1177358e115e)

100.000 įrašų:

![image](https://github.com/augustinavicius-vu/obj-prog/assets/101087475/797aadc0-89ec-4e50-a847-43453dbcd21e)

1.000.000 įrašų:

![image](https://github.com/augustinavicius-vu/obj-prog/assets/101087475/adf7df7f-5acf-4789-abd1-dd7a490ee43d)

## Konteinerių spartos analizė

Pagal gautus rezultatus, list'as panašu yra tinkamiausias sprendimas optimizuoti programą. **Svarbu paminėti,** kad deque yra universalesnis skirtingose situacijose.
_Visur yra sugeneruojami 15 namų darbų pažymiai ir vienas egzamino pažymys_

1.000 įrašų:

![image](https://github.com/augustinavicius-vu/obj-prog/assets/101087475/95df444a-3114-4eb0-b215-c43721eb941b)

10.000 įrašų:

![image](https://github.com/augustinavicius-vu/obj-prog/assets/101087475/bc792437-6d09-423c-bcfc-bcc7a3724417)

100.000 įrašų:

![image](https://github.com/augustinavicius-vu/obj-prog/assets/101087475/68c6c380-760d-40a6-a837-6c5d8e204ae9)

1.000.000 įrašų:

![image](https://github.com/augustinavicius-vu/obj-prog/assets/101087475/f56abda7-3595-4a9b-8174-4485d45bea26)

## Įrašų rūšiavimo į dvi kategorijas skirtingų strategijų analizė

Pagal gautus rezultatus, list'as panašu yra tinkamiausias sprendimas optimizuoti programą. **Svarbu paminėti,** kad deque yra universalesnis skirtingose situacijose.

1. Kuriami papildomai du atskiri konteineiriai galvočiams ir vargšiukams.
2. Kuriamas papildomas vienas konteineris galvočiams ir iš originalaus ištrinant galvočių konteineryje esantis studentas

_Visur yra sugeneruojami 15 namų darbų pažymiai ir vienas egzamino pažymys_
**1 strategijos rezultatai:**

1.000 įrašų:

![image](https://github.com/augustinavicius-vu/obj-prog/assets/101087475/fe2bcab6-3d75-4132-a36c-04bef355396f)

10.000 įrašų:

![image](https://github.com/augustinavicius-vu/obj-prog/assets/101087475/586add14-803f-469d-9442-1a77047222bd)

100.000 įrašų:

![image](https://github.com/augustinavicius-vu/obj-prog/assets/101087475/e520a90c-21a3-4dc6-8dc5-1b325db11ee4)

1.000.000 įrašų:

![image](https://github.com/augustinavicius-vu/obj-prog/assets/101087475/478fe4eb-6ceb-418a-abe1-cf48feb0ac8f)

**2 strategijos rezultatai:**

1.000 įrašų:

![image](https://github.com/augustinavicius-vu/obj-prog/assets/101087475/2c2240ce-9f0d-42f5-8544-6f3937ab7fc1)

10.000 įrašų:

![image](https://github.com/augustinavicius-vu/obj-prog/assets/101087475/bca835b7-5554-4015-9ff6-d53e5cffea4a)

100.000 įrašų:

![image](https://github.com/augustinavicius-vu/obj-prog/assets/101087475/165934d1-3c3b-4a1e-b2a3-ad0eaea8ef03)

1.000.000 įrašų: _(Vector konteineris truko apie 14 val., kol kas priežastis nežinoma)_

## class vs struct studentams testai
_Šie testai atlikti su jau optimizuotu kodu, kuris skiriasi nuo pradinių testų._

**100.000 įrašų, 15 namų darbų - vector konteineris, 1 strategija, class Studentas**

_Failo generavimas: (-36%)_
![image](https://github.com/augustinavicius-vu/obj-prog/assets/101087475/776b2bb1-6e75-4114-88b0-c734b584b461)

_Failo nuskaitymas ir įrašymas į atmintį: (+85%)_

![image](https://github.com/augustinavicius-vu/obj-prog-naujas/assets/101087475/bbcf32c8-1bc1-45e1-9ada-1e86f2c3d4d0)

_Studentų rikiavimas: (-95%)_

![image](https://github.com/augustinavicius-vu/obj-prog-naujas/assets/101087475/2e89c02b-11c8-4134-acd0-d515b9ad5b30)

_Studentų rūšiavimas į dvi grupes: (-15%)_

![image](https://github.com/augustinavicius-vu/obj-prog-naujas/assets/101087475/3f4f6a78-eee4-4ee9-a399-139cb6a1d13a)

_Dviejų grupių eksportas į du failus: (+165%)_

![image](https://github.com/augustinavicius-vu/obj-prog-naujas/assets/101087475/8329514d-0390-45b2-ac36-d1cd12d2fc98)

**Bendras laikas struct Studentas: 39s
Bendras laikas class Studentas: 27s**


**1.000.000 įrašų, 15 namų darbų - vector konteineris, 1 strategija, class Studentas**

_Failo generavimas: (-35%)_

![image](https://github.com/augustinavicius-vu/obj-prog-naujas/assets/101087475/54bd3169-5531-41e8-a333-3f0d95b8e5e4)

_Failo nuskaitymas ir įrašymas į atmintį: (+82%)_

![image](https://github.com/augustinavicius-vu/obj-prog-naujas/assets/101087475/9d09a4d6-f2aa-4e58-9847-28bc6c2db8ef)

_Studentų rikiavimas: (-38%)_

![image](https://github.com/augustinavicius-vu/obj-prog-naujas/assets/101087475/010f2d61-16f9-4361-b8fb-a7d29a5c81f9)

_Studentų rūšiavimas į dvi grupes: (-21%)_

![image](https://github.com/augustinavicius-vu/obj-prog-naujas/assets/101087475/1e8c26c4-91d0-46c5-b2f4-d90544cec039)

_Dviejų grupių eksportas į du failus: (+170%)_

![image](https://github.com/augustinavicius-vu/obj-prog-naujas/assets/101087475/e7b714c4-11c5-4a16-a740-b53328c87981)

**Bendras laikas struct Studentas: 394s
Bendras laikas class Studentas: 267s**

**_Programa vidutiniškai veikia 30% geriau_**

## Optimizacijos lygių testai
### O1
**1.000.000 įrašų, 15 namų darbų - vector konteineris, 1 strategija, class Studentas**

_Failo generavimas:_

![image](https://github.com/augustinavicius-vu/obj-prog-naujas/assets/101087475/302ee7d3-fe02-4470-a14c-76749cf5dedb)

_Failo nuskaitymas ir įrašymas į atmintį:_

![image](https://github.com/augustinavicius-vu/obj-prog-naujas/assets/101087475/0858ec26-0bfa-45ae-a372-0e867c092311)

_Studentų rikiavimas:_

![image](https://github.com/augustinavicius-vu/obj-prog-naujas/assets/101087475/6d94bfe5-f6af-4bcf-a460-951a8161ba18)

_Studentų rūšiavimas į dvi grupes:_

![image](https://github.com/augustinavicius-vu/obj-prog-naujas/assets/101087475/531547d6-6c1f-4518-863e-e69762a20eed)

_Dviejų grupių eksportas į du failus:_

![image](https://github.com/augustinavicius-vu/obj-prog-naujas/assets/101087475/9b4e135b-3996-46e2-951a-f9917f72f9d8)

### O2
**1.000.000 įrašų, 15 namų darbų - vector konteineris, 1 strategija, class Studentas**

_Failo generavimas:_

![image](https://github.com/augustinavicius-vu/obj-prog-naujas/assets/101087475/a587de83-6ccb-4aa4-a35d-104d5f192e26)

_Failo nuskaitymas ir įrašymas į atmintį:_

![image](https://github.com/augustinavicius-vu/obj-prog-naujas/assets/101087475/c4046002-d2a4-417f-9429-2a316c4b310d)

_Studentų rikiavimas:_

![image](https://github.com/augustinavicius-vu/obj-prog-naujas/assets/101087475/664ffce5-da0d-4d8f-8608-ee8ad134ea5e)

_Studentų rūšiavimas į dvi grupes:_

![image](https://github.com/augustinavicius-vu/obj-prog-naujas/assets/101087475/5be056b0-abc6-4e73-a5cc-7ce615cca5fd)

_Dviejų grupių eksportas į du failus:_

![image](https://github.com/augustinavicius-vu/obj-prog-naujas/assets/101087475/ceec1f75-bc6e-487c-b982-405e47247ad7)

### O3
**1.000.000 įrašų, 15 namų darbų - vector konteineris, 1 strategija, class Studentas**

_Failo generavimas:_

![image](https://github.com/augustinavicius-vu/obj-prog-naujas/assets/101087475/fbe5f5c5-f33c-437d-86f5-b15593b77e1e)

_Failo nuskaitymas ir įrašymas į atmintį:_

![image](https://github.com/augustinavicius-vu/obj-prog-naujas/assets/101087475/ad6884ba-6738-4a48-9354-275deae419f7)

_Studentų rikiavimas:_

![image](https://github.com/augustinavicius-vu/obj-prog-naujas/assets/101087475/d6f5a357-fe55-4d86-a69b-4916b244f03c)

_Studentų rūšiavimas į dvi grupes:_

![image](https://github.com/augustinavicius-vu/obj-prog-naujas/assets/101087475/8d27d363-3d5f-4661-be99-792184a8f341)

_Dviejų grupių eksportas į du failus:_

![image](https://github.com/augustinavicius-vu/obj-prog-naujas/assets/101087475/d54fec63-24cf-4cef-942f-0449f6a023e2)

# Versijos

Čia nurodyti trumpi versijų aprašymai, daugiau informacijos [releases](https://github.com/augustinavicius-vu/obj-prog/releases) puslapyje.

## Versija 1.1

* Pradėta naudoti `class` vietoj `struct` studentų duomenims laikyti
* Pertvarkytas kodas, kad būtų galima naudoti metodus, skirtus `class` objektui
* Panaikintos nebereikalingos funkcijos

## Versija 1.0

* Atlikta dviejų skirtingų įrašų filtravimų strategija
* Pagal turimus duomenis kodas optimizuotas
* Atsižvelgus į dėstytojo nurodytus metodus, paspartinta vektoriaus konteinerio operacijos
* Pridėtas CMAKE

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
