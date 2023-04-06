#include <iostream>
#include <climits>
#include <algorithm>

#include "studentas.h"

// Valyti Naudotojo Įvestį
void ValytiIvesti()
{
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
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