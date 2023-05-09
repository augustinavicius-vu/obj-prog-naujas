#include <iostream>
#include <climits>
#include <algorithm>
#include <fstream>
#include <string>

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