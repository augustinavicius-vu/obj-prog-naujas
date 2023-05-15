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

void GeneruotiFailaBalas(int studentuSk, VStudentas studentai, std::string vieta)
{
    std::ofstream failas(vieta + "");
    for (int i = 0; i < studentuSk; i++)
    {
        failas << studentai[i].vardas << " " << studentai[i].pavarde;
        for (int j = 0; j < studentai[i].namuDarbaiRez.size(); j++)
        {
            failas << " " << studentai[i].namuDarbaiRez[j];
        }
        failas << " " << studentai[i].egzaminasRez << std::endl;
    }
    failas.close();
}

void NuskaityiFaila(VStudentas &studentai, std::string vieta, int &studentoIndeksas)
{
    studentoIndeksas = 0;
    studentai.clear();

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

                tempNamuDarbaiRez.clear();
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

void RusiuotiStudentusBalas(VStudentas &studentai, VStudentas &studentaiA, VStudentas &studentaiB, int &studentaiASk, int &studentaiBSk, int &studentoIndeksas)
{
    for (int i = 0; i < studentoIndeksas; i++)
    {
        double studentoVidurkis = StudentoVidurkis(studentai[i]);
        if (studentoVidurkis < 5) {
            studentaiA.push_back(Studentas());
            studentaiA[studentaiASk] = studentai[i];
            studentaiASk++;
        } else {
            studentaiB.push_back(Studentas());
            studentaiB[studentaiBSk] = studentai[i];
            studentaiBSk++;
        }
    }
}

void TestuotiSparta(int irasuSk, int namuDarbuSk, std::string vieta, int &studentoIndeksas, VStudentas &studentai)
{
    // Pradžia
    std::cout << "Pradedama programos spartos analizė" << std::endl;
    auto start = std::chrono::high_resolution_clock::now();

    // Failo generavimas
    auto startGen = std::chrono::high_resolution_clock::now();
    GeneruotiFaila(irasuSk, namuDarbuSk, vieta);
    auto endGen = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffGen = endGen - startGen;
    std::cout << irasuSk << " įrašų generavimas ir išvedimas į failą užtruko: " << diffGen.count() << std::endl;

    // Failo nuskaitymas
    auto startRead = std::chrono::high_resolution_clock::now();
    NuskaityiFaila(studentai, vieta, studentoIndeksas);
    auto endRead = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffRead = endRead - startRead;
    std::cout << irasuSk << " įrašų nuskaitymas užtruko: " << diffRead.count() << std::endl;

    // Studentų rūšiavimas
    auto startSort = std::chrono::high_resolution_clock::now();
    VStudentas studentaiA;
    VStudentas studentaiB;
    int studentaiASk = 0;
    int studentaiBSk = 0;
    RusiuotiStudentusBalas(studentai, studentaiA, studentaiB, studentaiASk, studentaiBSk, studentoIndeksas);
    auto endSort = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffSort = endSort - startSort;
    std::cout << irasuSk << " įrašų rūšiavimas į dvi kategorijas užtruko: " << diffSort.count() << std::endl;

    // Vieta galvociams ir vargsiukams
    std::string vietaVarg = vieta.substr(0, vieta.find(".", 0)).append("_vargsiukai.txt");
    std::string vietaGalv = vieta.substr(0, vieta.find(".", 0)).append("_galvociai.txt");
    // Studentų išvedimas į failus galvočiai
    auto startWrite1 = std::chrono::high_resolution_clock::now();
    GeneruotiFailaBalas(studentaiASk, studentaiA, vietaVarg);
    auto endWrite1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffWrite1 = endWrite1 - startWrite1;
    std::cout << irasuSk << " vargšiukų įrašų įrašymas į failą užtruko: " << diffWrite1.count() << std::endl;

    // Studentų išvedimas į failus galvočiai
    auto startWrite2 = std::chrono::high_resolution_clock::now();
    GeneruotiFailaBalas(studentaiBSk, studentaiB, vietaGalv);
    auto endWrite2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffWrite2 = endWrite2 - startWrite2;
    std::cout << irasuSk << " galvočių įrašų įrašymas į failą užtruko: " << diffWrite2.count() << std::endl;

    // Pabaiga
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Programos veiko analizė užtruko: " << diff.count() << std::endl;

    Pauze();
}