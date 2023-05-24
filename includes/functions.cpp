#include <iostream>
#include <climits>
#include <algorithm>
#include <fstream>
#include <string>
#include <chrono>
#include <type_traits>
#include <random>

#include "functions.h"
#include "studentas.h"

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

int AtsitiktinisSkaicius(int min, int max)
{
    std::random_device seed;
    std::mt19937 generator(seed());
    std::uniform_int_distribution<int> distribution(min, max);

    return distribution(generator);
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

void EksportuotiStudentus(StudentasVector studentai, std::string vieta)
{
    // Failas Atsidaro
    std::ofstream studentuFailas(vieta);

    // Pavadinimai
    studentuFailas << "Vardas " << "Pavardė ";
    for (int i = 0; i < studentai[0].namuDarbai().size(); i++)
    {
        studentuFailas << "ND" << i +1 << " ";
    }
    studentuFailas << "Egzaminas" << std::endl;

    // Duomenys
    for (auto &studentas : studentai)
    {
        studentuFailas << studentas.vardas() << " " << studentas.pavarde() << " ";
        for (auto &namuDarbas : studentas.namuDarbai())
        {
            studentuFailas << namuDarbas << " ";
        }
        studentuFailas << studentas.egzaminas() << std::endl;
    }

    // Failas Užsidaro
    studentuFailas.close();
}