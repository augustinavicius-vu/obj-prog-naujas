#include <istream>
#include <iostream>
#include <string>

#include "studentas.h"
#include "functions.h"

std::istream& Studentas::nuskaitytiFaila(std::istream &is)
{
    is >> vardas_ >> pavarde_;

    double namuDarbas;
    while (is >> namuDarbas)
    {
        namuDarbai_.push_back(namuDarbas);
    }

    egzaminas_ = namuDarbas;

    return is;
}

std::istream &Studentas::nuskaitytiKonsole(std::istream &is)
{
    // STUDENTO VARDAS
    ValytiIsvesti();
    std::cout << "Įveskite studento VARDĄ" << std::endl;
    is >> vardas_;

    // STUDENTO PAVARDE
    ValytiIsvesti();
    std::cout << "Įveskite studento PAVARDĘ" << std::endl;
    is >> pavarde_;

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
        is >> egzaminas_;


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

            namuDarbai_.push_back(tempNamuDarbasRez);
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
            namuDarbai_.push_back(AtsitiktinisSkaicius(0, 10));
        }
    }

    return is;
}

double Studentas::galutinisBalas() const
{
    double suma = 0;

    for (auto &namuDarbas : namuDarbai_)
    {
        suma += namuDarbas;
    }

    return ((suma / namuDarbai_.size()) * 0.4) + (egzaminas_ * 0.6);
}

bool palygintiVardus(const Studentas &studentasA, const Studentas &studentasB)
{
    return studentasA.vardas() > studentasB.vardas();
}

bool vertinimoKriterijus(const Studentas &studentas)
{
    return studentas.galutinisBalas() >= 5;
}