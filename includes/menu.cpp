#include <iostream>
#include <iomanip>
#include <vector>
#include <fstream>

#include "studentas.h"

#include "helpers.h"
#include "calculations.h"

void PasirinkimasNaujasStudentas(int &studentoIndeksas, VStudentas &studentai)
{
    // STUDENTO VARDAS
    ValytiIsvesti();
    std::string tempVardas;
    std::cout << "Įveskite studento VARDĄ" << std::endl;
    std::cin >> tempVardas;

    // STUDENTO PAVARDE
    ValytiIsvesti();
    std::string tempPavarde;
    std::cout << "Įveskite studento PAVARDĘ" << std::endl;
    std::cin >> tempPavarde;

    // STUDENTO REZULTATAI
    ValytiIsvesti();
    std::cout << "Ar norite studento rezultatus įvesti RANKINIU būdu ar sugeneruoti ATSITIKTINIU (1-2):" << std::endl;
    std::cout << "1. Rankiniu" << std::endl;
    std::cout << "2. Atsitiktiniu" << std::endl;

    int pasirinkimas;
    while (true)
    {
        std::cin >> pasirinkimas;
        if (!(std::cin) || (pasirinkimas != 1 && pasirinkimas != 2))
        {
            ValytiIsvesti();
            std::cout << "Blogas pasirinkimas! Galimi pasirinkimai (1-2):" << std::endl;
            std::cout << "1. Rankiniu" << std::endl;
            std::cout << "2. Atsitiktiniu" << std::endl;

            ValytiIvesti();
            continue;
        }

        break;
    }

    // STUDENTO REZULTATAS - KINTAMIEJI
    int tempEgzaminasRez;
    std::vector<int> tempNamuDarbaiRez;

    // STUDENTO REZULTATAS - RANKINIS BŪDAS
    if (pasirinkimas == 1)
    {
        ValytiIsvesti();
        std::cout << "Įveskite studento EGZAMINO rezultatą" << std::endl;
        while (true)
        {
            std::cin >> tempEgzaminasRez;
            if (!(std::cin) || (tempEgzaminasRez < 0 || tempEgzaminasRez > 10))
            {
                std::cout << "Bloga reikšmė! EGZAMINO rezultato galimos reikšmės yra NUO 0 IKI 10 IMTINAI" << std::endl;

                ValytiIvesti();
                continue;
            }

            break;
        }

        ValytiIsvesti();
        std::cout << "Įveskite studento NAMŲ DARBŲ rezultatus. Norint baigti rezultatų įvedimą, įveskite „-1“" << std::endl;

        int tempNamuDarbasRez;
        while (true)
        {
            std::cin >> tempNamuDarbasRez;

            if (tempNamuDarbasRez == -1)
                break;

            if (!(std::cin) || (tempNamuDarbasRez < 0 || tempNamuDarbasRez > 10))
            {
                std::cout << "Bloga reikšmė! NAMŲ DARBO rezultato galimos reikšmės yra NUO 0 IKI 10 IMTINAI, norint įvedimą baigti, įveskite „-1“" << std::endl;

                ValytiIvesti();
                continue;
            }

            tempNamuDarbaiRez.push_back(tempNamuDarbasRez);
        }
    }

    // STUDENTO REZULTATAS - ATSITIKTININS BŪDAS
    if (pasirinkimas == 2)
    {
        tempEgzaminasRez = AtsitiktinisSkaicius(0, 10);

        ValytiIsvesti();
        std::cout << "Įveskite kiek NAMŲ DARBŲ rezultatų norite sugeneruoti (1 - 100)" << std::endl;

        int namuDarbuSk;
        while(true)
        {
            std::cin >> namuDarbuSk;

            if (!(std::cin) || (namuDarbuSk < 1 || namuDarbuSk > 100))
            {
                ValytiIsvesti();
                std::cout << "Bloga reikšmė! NAMŲ DARBŲ SKAIČIAUS reikšmės yra NUO 1 IKI 100" << std::endl;

                ValytiIvesti();
                continue;
            }

            break;
        }

        for (int i = 0; i < namuDarbuSk; i++)
        {
            tempNamuDarbaiRez.push_back(AtsitiktinisSkaicius(0, 10));
        }
    }

    // STUDENTO KŪRIMAS
    try
    {
        NaujasStudentas(studentoIndeksas, studentai, tempVardas, tempPavarde, tempEgzaminasRez, tempNamuDarbaiRez);
    }
    catch (const std::exception &e)
    {
        ValytiIsvesti();
        std::cout << "Naujo studento įrašymo operacija nepavyko! Klaidos pranešimas:" << std::endl;
        std::cerr << e.what() << std::endl;
        Pauze();
    }
}

void PasirinkimasGeneruotiFaila()
{
    ValytiIsvesti();
    std::cout << "Įveskite kiek studentų norite sugeneruoti" << std::endl;
    int studentuSk;
    while (true)
    {
        std::cin >> studentuSk;
        if (!(std::cin) || (studentuSk < 1 || studentuSk > 2147483647))
        {
            std::cout << "Bloga reikšmė! STUDENTŲ KIEKIO SKAIČIAUS reikšmės yra NUO 1 IKI 2147483647" << std::endl;
            ValytiIvesti();
            continue;
        }

        break;
    }

    ValytiIsvesti();
    std::cout << "Įveskite kiek namų darbų pažymių studentai turės" << std::endl;
    int namuDarbuSk;
    while (true)
    {
        std::cin >> namuDarbuSk;
        if (!(std::cin) || (namuDarbuSk < 1 || namuDarbuSk > 2147483647))
        {
            std::cout << "Bloga reikšmė! NAMŲ DARBŲ SKAIČIAUS reikšmės yra NUO 1 IKI 2147483647" << std::endl;
            ValytiIvesti();
            continue;
        }

        break;
    }

    ValytiIsvesti();
    std::cout << "Įveskite kur norite išsaugoti šį failą" << std::endl;

    std::string vieta;
    std::cin >> vieta;

    ValytiIsvesti();
    std::cout << "Pradedamas generuoti failas" << std::endl;

    GeneruotiFaila(studentuSk, namuDarbuSk, vieta);
}

void PasirinkimasNuskaitytiFaila(int &studentoIndeksas, VStudentas &studentai)
{
    ValytiIsvesti();
    std::cout << "Įveskite NAMŲ DARBŲ skaičių (1 - 100)" << std::endl;

    int namuDarbuSk;
    while (true)
    {
        std::cin >> namuDarbuSk;
        if (!(std::cin) || (namuDarbuSk < 1 || namuDarbuSk > 100))
        {
            std::cout << "Bloga reikšmė! NAMŲ DARBŲ SKAIČIAUS reikšmės yra NUO 1 IKI 100" << std::endl;
            ValytiIvesti();
            continue;
        }

        break;
    }

    std::ifstream failas;
    failas.open("./test/t10000.txt");
    if (!failas)
    {
        std::cout << "Nerastas failas!" << std::endl;
        Pauze();
    }

    std::string tekstas;
    int laukelis = -1;

    std::string tempVardas;
    std::string tempPavarde;
    int tempEgzaminasRez;
    std::vector<int> tempNamuDarbaiRez;

    while (failas >> tekstas)
    {
        laukelis++;

        // Vardas
        if (laukelis == 0)
        {
            tempVardas = tekstas;
            continue;
        }

        // Pavarde
        if (laukelis == 1)
        {
            tempPavarde = tekstas;
            continue;
        }

        // Namu Darbai
        if (laukelis > 1 && laukelis < 2 + namuDarbuSk)
        {
            tempNamuDarbaiRez.push_back(std::stoi(tekstas));
            continue;
        }

        // Egzaminas
        if (laukelis > 1 + namuDarbuSk)
        {
            tempEgzaminasRez = std::stoi(tekstas);
            NaujasStudentas(studentoIndeksas, studentai, tempVardas, tempPavarde, tempEgzaminasRez, tempNamuDarbaiRez);

            laukelis = -1;
            continue;
        }
    }

    failas.close();
}

void PasirinkimasSkaiciuotiAbu(VStudentas &studentai)
{
    ValytiIsvesti();
    std::cout << std::setw(20) << std::left << "Vardas";
    std::cout << std::setw(20) << std::left << "Pavardė";
    std::cout << std::setw(20) << std::left << "Galutinis vid.";
    std::cout << "Galutinė med." << std::endl;
    std::cout << "----------------------------------------------------------------------------" << std::endl;

    RikiuotiStudentus(studentai);

    for (auto &studentas : studentai)
    {
        std::cout << std::setw(20) << std::left << studentas.vardas;
        std::cout << std::setw(20) << std::left << studentas.pavarde;
        std::cout << std::setw(20) << std::left << std::setprecision(2) << std::fixed <<StudentoVidurkis(studentas);
        std::cout << std::setprecision(2) << std::fixed <<StudentoMediana(studentas) << std::endl;
    }

    Pauze();
}

void PasirinkimasSkaiciuotiVidurki(VStudentas &studentai)
{
    ValytiIsvesti();
    std::cout << std::setw(20) << std::left << "Vardas";
    std::cout << std::setw(20) << std::left << "Pavardė";
    std::cout << "Galutinis vid." << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;

    RikiuotiStudentus(studentai);

    for (auto &studentas : studentai)
    {
        std::cout << std::setw(20) << std::left << studentas.vardas;
        std::cout << std::setw(20) << std::left << studentas.pavarde;
        std::cout << std::setprecision(2) << std::fixed << StudentoVidurkis(studentas)  << std::endl;
    }

    Pauze();
}

void PasirinkimasSkaiciuotiMediana(VStudentas &studentai)
{
    ValytiIsvesti();
    std::cout << std::setw(20) << std::left << "Vardas";
    std::cout << std::setw(20) << std::left << "Pavardė";
    std::cout << "Galutinė med." << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;

    RikiuotiStudentus(studentai);

    for (auto &studentas : studentai)
    {
        std::cout << std::setw(20) << std::left << studentas.vardas;
        std::cout << std::setw(20) << std::left << studentas.pavarde;
        std::cout << std::setprecision(2) << std::fixed <<StudentoMediana(studentas) << std::endl;
    }

    Pauze();
}

void PasirinkimasGreicioAnalize(int &studentoIndeksas, VStudentas &studentai)
{
    // Įrašų kiekis
    ValytiIsvesti();
    std::cout << "Kiek įrašų norite sugeneruoti?" << std::endl;

    int irasuSk;
    while (true)
    {
        std::cin >> irasuSk;
        if (!(std::cin) || (irasuSk < 1 || irasuSk > 2147483647))
        {
            std::cout << "Bloga reikšmė! ĮRAŠŲ KIEKIO SKAIČIAUS reikšmės yra NUO 1 IKI 2147483647" << std::endl;
            ValytiIvesti();
            continue;
        }

        break;
    }

    // Namų darbų pažymių kiekis
    ValytiIsvesti();
    std::cout << "Kiek namų darbų pažymių norite sugeneruoti?" << std::endl;

    int namuDarbuSk;
    while (true)
    {
        std::cin >> namuDarbuSk;
        if (!(std::cin) || (namuDarbuSk < 1 || namuDarbuSk > 2147483647))
        {
            std::cout << "Bloga reikšmė! NAMŲ DARBŲ SKAIČIAUS reikšmės yra NUO 1 IKI 2147483647" << std::endl;
            ValytiIvesti();
            continue;
        }

        break;
    }

    ValytiIsvesti();
    std::cout << "Kur norite išsaugoti failą?" << std::endl;
    std::string vieta;
    std::cin >> vieta;

    ValytiIsvesti();
    // Pradėti spartos testavimą
    TestuotiSparta(irasuSk, namuDarbuSk, vieta, studentoIndeksas, studentai);
}

void Ivestis(int &studentoIndeksas, VStudentas &studentai)
{
    while (true)
    {
        ValytiIsvesti();
        if (studentoIndeksas < 1)
        {
            std::cout << "Pasirinkite veiksmą (1-5):" << std::endl;
            std::cout << "1. Naujas studentas" << std::endl;
            std::cout << "2. Generuoti studentus" << std::endl;
            std::cout << "3. Nuskaityti studentų failą" << std::endl;
            std::cout << "4. Generuoti studentų failą" << std::endl;
            std::cout << "5. Programos veikimo greičio analizė" << std::endl;
        }
        else
        {
            std::cout << "Pasirinkite veiksmą (1-8):" << std::endl;
            std::cout << "1. Naujas studentas" << std::endl;
            std::cout << "2. Generuoti studentus" << std::endl;
            std::cout << "3. Nuskaityti studentų failą" << std::endl;
            std::cout << "4. Generuoti studentų failą" << std::endl;
            std::cout << "5. Programos veikimo greičio analizė" << std::endl;
            std::cout << "6. Skaičiuoti studentų galutinį vidurkį" << std::endl;
            std::cout << "7. Skaičiuoti studentų galutinę medianą" << std::endl;
            std::cout << "8. Skaičiuoti studentų galutinį vidurkį ir medianą" << std::endl;
        }

        int pasirinkimas;
        while (true)
        {
            std::cin >> pasirinkimas;

            // Programos pradžia
            if (studentoIndeksas < 1)
            {
                if (!(std::cin) || (pasirinkimas != 1 && pasirinkimas != 2 && pasirinkimas != 3 && pasirinkimas != 4 && pasirinkimas != 5))
                {
                    ValytiIsvesti();
                    std::cout << "Blogas pasirinkimas! Galimi pasirinkimai (1-5):" << std::endl;
                    std::cout << "1. Naujas studentas" << std::endl;
                    std::cout << "2. Generuoti studentus" << std::endl;
                    std::cout << "3. Nuskaityti studentų failą" << std::endl;
                    std::cout << "4. Generuoti studentų failą" << std::endl;
                    std::cout << "5. Programos veikimo greičio analizė" << std::endl;
                    ValytiIvesti();
                    continue;
                }
            }
            else // Programa tęsias
            {
                if (!(std::cin) || (pasirinkimas != 1 && pasirinkimas != 2 && pasirinkimas != 3 && pasirinkimas != 4 && pasirinkimas != 5 && pasirinkimas != 6 && pasirinkimas != 7 && pasirinkimas != 8))
                {
                    ValytiIsvesti();
                    std::cout << "Blogas pasirinkimas! Galimi pasirinkimai (1-8):" << std::endl;
                    std::cout << "1. Naujas studentas" << std::endl;
                    std::cout << "2. Generuoti studentus" << std::endl;
                    std::cout << "3. Nuskaityti studentų failą" << std::endl;
                    std::cout << "4. Generuoti studentų failą" << std::endl;
                    std::cout << "5. Programos veikimo greičio analizė" << std::endl;
                    std::cout << "6. Skaičiuoti studentų galutinį vidurkį" << std::endl;
                    std::cout << "7. Skaičiuoti studentų galutinę medianą" << std::endl;
                    std::cout << "8. Skaičiuoti studentų galutinį vidurkį ir medianą" << std::endl;
                    ValytiIvesti();
                    continue;
                }
            }

            break;
        }

        if (pasirinkimas == 1) PasirinkimasNaujasStudentas(studentoIndeksas, studentai);
        //if (pasirinkimas == 2) PasirinkimasGeneruotiStudentus();
        if (pasirinkimas == 3) PasirinkimasNuskaitytiFaila(studentoIndeksas, studentai);
        if (pasirinkimas == 4) PasirinkimasGeneruotiFaila();
        if (pasirinkimas == 5) PasirinkimasGreicioAnalize(studentoIndeksas, studentai);
        if (pasirinkimas == 6) PasirinkimasSkaiciuotiVidurki(studentai);
        if (pasirinkimas == 7) PasirinkimasSkaiciuotiMediana(studentai);
        if (pasirinkimas == 8) PasirinkimasSkaiciuotiAbu(studentai);
    }
}