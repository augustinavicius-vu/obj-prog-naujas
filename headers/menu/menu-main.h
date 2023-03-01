#include <iostream>

#include "../tools/clearcin.h" // ValytiIvesti()
#include "menu-new-stud.h" // Naujo studento meniu
#include "menu-stud-mean.h" // Studento vidurkis meniu
#include "menu-stud-medi.h" // Studento mediana meniu

void Ivestis(int &studentoIndeksas, VStudentas &studentai)
{
    while (true)
    {
        system("cls");
        if (studentoIndeksas < 1)
        {
            std::cout << "Pasirinkite veiksmą (1-3):" << std::endl;
            std::cout << "1. Naujas studentas" << std::endl;
            std::cout << "2. Generuoti studentus" << std::endl;
            std::cout << "3. Nuskaityti studentų failą" << std::endl;
        }
        else
        {
            std::cout << "Pasirinkite veiksmą (1-6):" << std::endl;
            std::cout << "1. Naujas studentas" << std::endl;
            std::cout << "2. Generuoti studentus" << std::endl;
            std::cout << "3. Nuskaityti studentų failą" << std::endl;
            std::cout << "4. Skaičiuoti studentų galutinį vidurkį" << std::endl;
            std::cout << "5. Skaičiuoti studentų gaultinę medianą" << std::endl;
            std::cout << "6. Skaičiuoti studentų galutinį vidurkį ir medianą" << std::endl;
        }

        int pasirinkimas;
        while (true)
        {
            std::cin >> pasirinkimas;

            // Programos pradžia
            if (studentoIndeksas < 1)
            {
                if (!(std::cin) || (pasirinkimas != 1 && pasirinkimas != 2 && pasirinkimas != 3))
                {
                    system("cls");
                    std::cout << "Blogas pasirinkimas! Galimi pasirinkimai (1-3):" << std::endl;
                    std::cout << "1. Naujas studentas" << std::endl;
                    std::cout << "2. Generuoti studentus" << std::endl;
                    std::cout << "3. Nuskaityti studentų failą" << std::endl;
                    ValytiIvesti();
                    continue;
                }
            }
            else // Programa tęsias
            {
                if (!(std::cin) || (pasirinkimas != 1 && pasirinkimas != 2 && pasirinkimas != 3 && pasirinkimas != 4 && pasirinkimas != 5 && pasirinkimas != 6))
                {
                    system("cls");
                    std::cout << "Blogas pasirinkimas! Galimi pasirinkimai (1-5):" << std::endl;
                    std::cout << "1. Naujas studentas" << std::endl;
                    std::cout << "2. Generuoti studentus" << std::endl;
                    std::cout << "3. Nuskaityti studentų failą" << std::endl;
                    std::cout << "4. Skaičiuoti studentų galutinį vidurkį" << std::endl;
                    std::cout << "5. Skaičiuoti studentų gaultinę medianą" << std::endl;
                    std::cout << "6. Skaičiuoti studentų galutinį vidurkį ir medianą" << std::endl;
                    ValytiIvesti();
                    continue;
                }
            }

            break;
        }

        if (pasirinkimas == 1)
            PasirinkimasNaujasStudentas(studentoIndeksas, studentai);
        //if (pasirinkimas == 2) PasirinkimasGeneruotiStudentus();
        //if (pasirinkimas == 3) PasirinkimasNuskaitytiFaila();
        if (pasirinkimas == 4) PasirinkimasSkaiciuotiVidurki(studentai);
        if (pasirinkimas == 5) PasirinkimasSkaiciuotiMediana(studentai);
        //if (pasirinkimas == 6) PasirinkimasSkaiciuotiAbu();
    }
}