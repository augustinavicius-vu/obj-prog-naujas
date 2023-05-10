#include <iostream>
#include <climits>
#include <algorithm>
#include <fstream>
#include <string>
#include <chrono>

#include "studentas.h"
#include "calculations.h"

// Valyti Naudotojo Įvestį
void ValytiIvesti()
{
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
}

void ValytiIsvesti()
{
    #if defined(WIN32) || defined(_WIN32) // Windows
    system("cls");
    #else // Viskas kita (siuo atveju Linux)
    system("clear");
    #endif
}

void Pauze()
{
    #if defined(WIN32) || defined(_WIN32) // Windows
    system("pause");
    #else // Viskas kita (siuo atveju Linux)
    system("sleep 1h");
    #endif
}

void NaujasStudentas(int &studentoIndeksas, VStudentas &studentai, std::string vardas, std::string pavarde, int egzaminasRez, std::vector<int> namuDarbaiRez)
{
    studentai.push_back(Studentas());

    studentai[studentoIndeksas].vardas = vardas;
    studentai[studentoIndeksas].pavarde = pavarde;
    studentai[studentoIndeksas].egzaminasRez = egzaminasRez;
    studentai[studentoIndeksas].namuDarbaiRez = namuDarbaiRez;

    studentoIndeksas++;
}

bool RikiavimoTipas(const Studentas &studentasA, const Studentas &studentasB)
{
    if (studentasA.vardas == studentasB.vardas)
    {
        return studentasA.pavarde < studentasB.pavarde;
    }
    else
    {
        return studentasA.vardas < studentasB.vardas;
    }
    
}

void RikiuotiStudentus(VStudentas &studentai)
{
    std::sort(studentai.begin(), studentai.end(), RikiavimoTipas);
}

void GeneruotiFaila(int studentuSk, int namuDarbuSk, std::string vieta) 
{
    std::ofstream failas(vieta);
    failas << "Vardas Pavardė ";
    for (int i = 0; i < namuDarbuSk; i++)
    {
        failas << "ND" << i + 1 << " ";
    }
    failas << "Egzaminas\n";

    for (int i = 0; i < studentuSk; i++) {
        failas << "Vardas" << i + 1 << " Pavardė" << i + 1;
        for (int j = 0; j < namuDarbuSk; j++)
        {
            failas << " " << AtsitiktinisSkaicius(1, 10) << " "; // Namų darbai
        }
        failas << AtsitiktinisSkaicius(1, 10) << "\n"; // Egzaminas
    }
        
    failas.close();
}

void NuskaityiFaila(VStudentas &studentai, std::string vieta, int &studentoIndeksas)
{
    std::ifstream failas(vieta);

    int laukelis = -1;
    int namuDarbuSk = 0;
    bool skaityti = false;

    std::string tekstas;
    std::string tempVardas;
    std::string tempPavarde;
    int tempEgzaminasRez;
    std::vector<int> tempNamuDarbaiRez;
    while (failas >> tekstas)
    {
        if (skaityti)
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
        } else {
            if (tekstas == "Egzaminas")
            {
                skaityti = true;
                namuDarbuSk = namuDarbuSk - 2;
            } else {
                namuDarbuSk++;
            }
        }
    }

    failas.close();
}

void TestuotiSparta(int irasuSk, int namuDarbuSk, std::string vieta, int &studentoIndeksas, VStudentas &studentai)
{
    std::cout << "Pradedama programos spartos analizė" << std::endl;

    // Failo generavimas
    auto startGen = std::chrono::high_resolution_clock::now();
    GeneruotiFaila(irasuSk, namuDarbuSk, vieta);
    auto endGen = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffGen = endGen - startGen;
    std::cout << irasuSk << " įrašų generavimas ir išvedimas į failą truko: " << diffGen.count() << std::endl;

    // Failo nuskaitymas
    auto startRead = std::chrono::high_resolution_clock::now();
    NuskaityiFaila(studentai, vieta, studentoIndeksas);
    auto endRead = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffRead = endRead - startRead;
    std::cout << irasuSk << " įrašų nuskaitymas truko: " << diffRead.count() << std::endl;

    



    Pauze();



}