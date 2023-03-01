#include <iostream>
#include <fstream>

void PasirinkimasNuskaitytiFaila(int &studentoIndeksas, VStudentas &studentai)
{
    system("cls");
    std::cout << "Įvekite NAMŲ DARBŲ skaičių (1 - 100)" << std::endl;
    
    int namuDarbuSk;
    while(true)
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

    // Failo atidarymas
    try
    {
        failas.open("./test/t10000.txt");
    }
    catch(const std::exception& e)
    {
        std::cout << "Failo atidarymo operacija nepavyko! Klaidos pranšimas:" << std::endl;
        std::cerr << e.what() << '\n';
        return;
    }
    
    int tekstas;
    int laukelis = 0;
    while (failas >> tekstas)
    {
        // Vardas
        if (laukelis == 0)
        {
            continue;
        }

        // Pavarde
        if (laukelis == 1)
        {
            continue;
        }

        // Namu Darbai
        if (laukelis )
        {
            
            continue;
        }
        // Egzaminas

    }
    failas.close();
}