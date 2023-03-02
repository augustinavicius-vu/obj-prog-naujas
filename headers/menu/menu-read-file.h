#include <iostream>
#include <fstream>

void PasirinkimasNuskaitytiFaila(int &studentoIndeksas, VStudentas &studentai)
{
    system("cls");
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
        system("pause");
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