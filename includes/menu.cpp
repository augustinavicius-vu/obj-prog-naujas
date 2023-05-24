#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>

#include "studentas.h"
#include "functions.h"

#include "studentas.cpp"

void PasirinkimasNaujasStudentas(StudentasVector &studentai)
{
    ValytiIsvesti();

    // Naujo Studento Pasirinkimas
    std::cout << "Ar norite įvesti studentą rankiniu būdu (1) ar nuskaityti studentų failą (2)" << std::endl;
    int pasirinkimas;
    while (true)
    {
        std::cin >> pasirinkimas;
        if (!(std::cin) || (pasirinkimas != 1 && pasirinkimas != 2))
        {
            std::cout << "Bloga reikšmė! Pasrinikimo reikšmės yra NUO 1 IKI 2" << std::endl;
            ValytiIvesti();
            continue;
        }

        break;
    }

    // Rankinis įvedimas
    if (pasirinkimas == 1)
    {
        // Valyti output'ą
        ValytiIsvesti();

        Studentas tempStudentas;
        tempStudentas.nuskaitytiKonsole(std::cin);

        studentai.push_back(tempStudentas);
    }

    // Failo nuskaitymas
    if (pasirinkimas == 2)
    {
        // Valyti output'ą
        ValytiIsvesti();

        // Studentų failo vieta
        std::cout << "Įveskite studentų failo vietą" << std::endl;
        std::string failoVieta;
        std::cin >> failoVieta;

        // Atidaryti ir nuskaityti studentų failą
        std::ifstream studentuFailas(failoVieta);

        // Pradinė eilutė - nereiklainga
        std::string pradineEilute;
        std::getline(studentuFailas, pradineEilute);

        // Namų darbai ir egzaminas
        std::string eilute;
        while(std::getline(studentuFailas, eilute))
        {
            std::istringstream iss(eilute);
            Studentas tempStudentas;
            tempStudentas.nuskaitytiFaila(iss);
            studentai.push_back(tempStudentas);
        }

        studentuFailas.close();

        for (const auto &studentas : studentai)
        {
            std::cout << "Vardas" << studentas.vardas() << std::endl;
            std::cout << "Galutinis balas" << studentas.galutinisBalas() << std::endl;
        }

        Pauze();
    }
}

void PasirinkimasGeneruotiStudentuFaila()
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
/*
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
            //NaujasStudentas(studentoIndeksas, studentai, tempVardas, tempPavarde, tempEgzaminasRez, tempNamuDarbaiRez);

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

    //RikiuotiStudentus(studentai);

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

    //RikiuotiStudentus(studentai);

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

    //RikiuotiStudentus(studentai);

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

void PasirinkimasKonteineriuAnalize()
{
    ValytiIsvesti();
    std::cout << "Įveskite iš kur norite nuskaityti įrašų failą" << std::endl;
    std::string vieta;
    std::cin >> vieta;

    TestuotiKonteinerius(vieta);
}
*/

void Ivestis(StudentasVector &studentai)
{
    while (true)
    {
        ValytiIsvesti();
        if (studentai.size() < 1)
        {
            std::cout << "Pasirinkite veiksmą (1-4):" << std::endl;
            std::cout << "1. Sukurti/importuoti studentą/studentus" << std::endl;
            std::cout << "2. Generuoti studentų failą" << std::endl;
            std::cout << "3. Programos veikimo greičio analizė" << std::endl;
            std::cout << "4. Konteinerių veikimo greičio analizė" << std::endl;
        }
        else
        {
            std::cout << "Pasirinkite veiksmą (1-4):" << std::endl;
            std::cout << "1. Sukurti/importuoti studentą/studentus" << std::endl;
            std::cout << "2. Generuoti studentų failą" << std::endl;
            std::cout << "3. Programos veikimo greičio analizė" << std::endl;
            std::cout << "4. Konteinerių veikimo greičio analizė" << std::endl;
        }

        int pasirinkimas;
        while (true)
        {
            std::cin >> pasirinkimas;

            // Programos pradžia
            if (studentai.size() < 1)
            {
                if (!(std::cin) || (pasirinkimas < 1 || pasirinkimas > 6))
                {
                    ValytiIsvesti();
                    std::cout << "Blogas pasirinkimas! Galimi pasirinkimai (1-4):" << std::endl;
                    std::cout << "1. Sukurti/importuoti studentą/studentus" << std::endl;
                    std::cout << "2. Generuoti studentų failą" << std::endl;
                    std::cout << "3. Programos veikimo greičio analizė" << std::endl;
                    std::cout << "4. Konteinerių veikimo greičio analizė" << std::endl;
                    ValytiIvesti();
                    continue;
                }
            }
            else // Programa tęsias
            {
                if (!(std::cin) || (pasirinkimas < 1 || pasirinkimas > 9))
                {
                    ValytiIsvesti();
                    std::cout << "Blogas pasirinkimas! Galimi pasirinkimai (1-4):" << std::endl;
                    std::cout << "1. Sukurti/importuoti studentą/studentus" << std::endl;
                    std::cout << "2. Generuoti studentų failą" << std::endl;
                    std::cout << "3. Programos veikimo greičio analizė" << std::endl;
                    std::cout << "4. Konteinerių veikimo greičio analizė" << std::endl;
                    ValytiIvesti();
                    continue;
                }
            }

            break;
        }

        if (pasirinkimas == 1) PasirinkimasNaujasStudentas(studentai);
        if (pasirinkimas == 2) PasirinkimasGeneruotiStudentuFaila();
        //if (pasirinkimas == 3) PasirinkimasNuskaitytiFaila(studentoIndeksas, studentai);
        //if (pasirinkimas == 4) PasirinkimasGeneruotiFaila();
        //if (pasirinkimas == 5) PasirinkimasGreicioAnalize(studentoIndeksas, studentai);
        //if (pasirinkimas == 6) PasirinkimasKonteineriuAnalize();
        //if (pasirinkimas == 7) PasirinkimasSkaiciuotiVidurki(studentai);
        //if (pasirinkimas == 8) PasirinkimasSkaiciuotiMediana(studentai);
        //if (pasirinkimas == 9) PasirinkimasSkaiciuotiAbu(studentai);
    }
}