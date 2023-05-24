#include <iostream>
#include <iomanip>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>
#include <chrono>
#include <algorithm>

#include "menu.h"
#include "studentas.h"
#include "functions.h"

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

        // Pradėti spartos matavimą
        auto start = std::chrono::high_resolution_clock::now();

        // Atidaryti ir nuskaityti studentų failą
        std::ifstream studentuFailas(failoVieta);

        // Pradinė eilutė - nereiklainga
        std::string pradineEilute;
        std::getline(studentuFailas, pradineEilute);

        // Namų darbai ir egzaminas
        int irasuSk = 0;
        std::string eilute;
        while(std::getline(studentuFailas, eilute))
        {
            std::istringstream iss(eilute);
            Studentas tempStudentas;
            tempStudentas.nuskaitytiFaila(iss);
            studentai.push_back(tempStudentas);

            irasuSk++;
        }

        studentuFailas.close();

        // Baigti spartos matavimą
        auto end = std::chrono::high_resolution_clock::now();
        std::chrono::duration<double> diff = end - start;
        std::cout << irasuSk << " įrašų nuskaitymas truko: " << diff.count() << std::endl;

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

    // Pradėti spartos matavimą
    auto start = std::chrono::high_resolution_clock::now();
    GeneruotiFaila(studentuSk, namuDarbuSk, vieta);

    // Baigti spartos matavimą
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> diff = end - start;
    std::cout << studentuSk << " įrašų generavimas užtruko: " << diff.count() << std::endl;

    Pauze();
}

void PasirinkimasRikiuotiStudentus(StudentasVector &studentai)
{
    ValytiIsvesti();
    std::cout << "Pradedama rikiuoti studentus" << std::endl;
    auto start = std::chrono::high_resolution_clock::now();
    std::sort(studentai.begin(), studentai.end(), palygintiVardus);
    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> diff = end - start;

    std::cout << studentai.size() << " įrašų rikiavimas truko: " << diff.count() << std::endl;
    Pauze();
}

void PasirinkimasRusiuotiStudentus(StudentasVector &studentai, StudentasVector &studentaiGalv, StudentasVector &studentaiVarg)
{
    ValytiIsvesti();
    std::cout << "Pradedama rušiuoti studentus" << std::endl;

    auto start = std::chrono::high_resolution_clock::now();
    
    std::partition_copy(studentai.begin(), studentai.end(), std::back_inserter(studentaiGalv), std::back_inserter(studentaiVarg), vertinimoKriterijus);

    auto end = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> diff = end - start;
    std::cout << studentai.size() << " įrašų rūšiavimas truko: " << diff.count() << std::endl;

    Pauze();
}

void PasirinkimasEksportuotiStudentus(StudentasVector &studentai, StudentasVector &studentaiGalv, StudentasVector &studentaiVarg)
{
    ValytiIsvesti();

    std::cout << "Nurodykite failo vietą, kur norite išeksportuoti turimus studentus" << std::endl;
    std::string vieta;
    std::cin >> vieta;

    std::string vietaVarg = vieta.substr(0, vieta.find(".", 0)).append("_vargsiukai.txt");
    std::string vietaGalv = vieta.substr(0, vieta.find(".", 0)).append("_galvociai.txt");

    std::cout << "Pradedamas duomenų įrašymas į failą" << std::endl;

    // Galvočiai
    auto startGalv = std::chrono::high_resolution_clock::now();

    EksportuotiStudentus(studentaiGalv, vietaGalv);

    auto endGalv = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffGalv = endGalv - startGalv;
    std::cout << studentaiGalv.size() << " įrašų įrašymas į failą truko: " << diffGalv.count() << std::endl;


    // Vargšiukai
    auto startVarg = std::chrono::high_resolution_clock::now();

    EksportuotiStudentus(studentaiVarg, vietaVarg);

    auto endVarg = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffVarg = endVarg - startVarg;
    std::cout << studentaiVarg.size() << " įrašų įrašymas į failą truko: " << diffVarg.count() << std::endl;

    Pauze();

}

void Ivestis(StudentasVector &studentai, StudentasVector &studentaiGalv, StudentasVector &studentaiVarg)
{
    while (true)
    {
        ValytiIsvesti();
        if (studentai.size() < 1)
        {
            std::cout << "Pasirinkite veiksmą (1-2):" << std::endl;
            std::cout << "1. Sukurti/importuoti studentą/studentus" << std::endl;
            std::cout << "2. Generuoti studentų failą" << std::endl;
        }
        else
        {
            std::cout << "Pasirinkite veiksmą (1-5):" << std::endl;
            std::cout << "1. Sukurti/importuoti studentą/studentus" << std::endl;
            std::cout << "2. Generuoti studentų failą" << std::endl;
            std::cout << "3. Rikiuoti studentus" << std::endl;
            std::cout << "4. Rušiuoti studentus" << std::endl;
            std::cout << "5. Eksportuoti studentus į failą" << std::endl;
        }

        int pasirinkimas;
        while (true)
        {
            std::cin >> pasirinkimas;

            // Programos pradžia
            if (studentai.size() < 1)
            {
                if (!(std::cin) || (pasirinkimas < 1 || pasirinkimas > 2))
                {
                    ValytiIsvesti();
                    std::cout << "Blogas pasirinkimas! Galimi pasirinkimai (1-2):" << std::endl;
                    std::cout << "1. Sukurti/importuoti studentą/studentus" << std::endl;
                    std::cout << "2. Generuoti studentų failą" << std::endl;
                    ValytiIvesti();
                    continue;
                }
            }
            else // Programa tęsias
            {
                if (!(std::cin) || (pasirinkimas < 1 || pasirinkimas > 5))
                {
                    ValytiIsvesti();
                    std::cout << "Blogas pasirinkimas! Galimi pasirinkimai (1-5):" << std::endl;
                    std::cout << "1. Sukurti/importuoti studentą/studentus" << std::endl;
                    std::cout << "2. Generuoti studentų failą" << std::endl;
                    std::cout << "3. Rikiuoti studentus" << std::endl;
                    std::cout << "4. Rušiuoti studentus" << std::endl;
                    std::cout << "5. Eksportuoti studentus į failą" << std::endl;
                    ValytiIvesti();
                    continue;
                }
            }

            break;
        }

        if (pasirinkimas == 1) PasirinkimasNaujasStudentas(studentai);
        if (pasirinkimas == 2) PasirinkimasGeneruotiStudentuFaila();
        if (pasirinkimas == 3) PasirinkimasRikiuotiStudentus(studentai);
        if (pasirinkimas == 4) PasirinkimasRusiuotiStudentus(studentai, studentaiGalv, studentaiVarg);
        if (pasirinkimas == 5) PasirinkimasEksportuotiStudentus(studentai, studentaiGalv, studentaiVarg);
    }
}