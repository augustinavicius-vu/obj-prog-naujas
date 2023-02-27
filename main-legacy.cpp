// Bibliotekos
#include <iostream>
#include <iomanip>
#include <limits.h>
#include <windows.h>
#include <random>
#pragma execution_character_set("utf-8");

// Studento struktura
struct Studentas
{
    std::string vardas;
    std::string pavarde;
    int egzaminasRez;
    int namuDarbuSk = 0;
    int *namuDarbaiRez;
};

Studentas *studentai;

bool ivestis = true;
int studentoIndeksas = 0;

void Ivestis();
void IvestiesValymas();
double StudentoVidurkis(int studentoIndeksas);
int AtsitiktinisSkaicius();
void RikiuotiMasyva(int studentoIndeksas, Studentas *studentai);

int main()
{
    // Lietuviškų raidžių palaikymas
    SetConsoleOutputCP(65001);

    // Pradinis studentų masyvas
    studentai = (Studentas *)calloc(1, sizeof(Studentas));

    Ivestis();
    // Ivestis();

    return 0;
}

void Ivestis()
{
    while (true)
    {
        system("cls");
        if (studentoIndeksas < 1) // Pradžia
        {
            std::cout << "Prašome pasirinkti veiksmą (1-1):" << std::endl;
            std::cout << "1. Naujas studentas" << std::endl;
        }
        else
        {
            std::cout << "Prašome pasirinkti veiksmą (1-1):" << std::endl;
            std::cout << "1. Naujas studentas" << std::endl;
            std::cout << "2. Skaičiuoti studentų galutinį vidurkį" << std::endl;
            std::cout << "3. Skaičiuoti studentų galutinę medianą" << std::endl;
        }

        // Pasirinkimo logika
        int pasirinkimas;
        while (true)
        {
            std::cin >> pasirinkimas;

            if (!(std::cin))
            {
                std::cout << "Blogas ivedimas" << std::endl;
                IvestiesValymas();
                continue;
            }

            if (std::cin && pasirinkimas != 1 && pasirinkimas != 2 && pasirinkimas != 3)
            {
                std::cout << "Blogas ivedimas" << std::endl;
                IvestiesValymas();
                continue;
            }

            break;
        }

        // Naujas studentas
        if (pasirinkimas == 1)
        {
            if (studentoIndeksas > 0)
            {
                studentai = (Studentas *)realloc(studentai, sizeof(Studentas) * (studentoIndeksas + 1));
            }
            system("cls");
            std::string tempVardas;
            std::cout << "Įveskite studento VARDĄ:" << std::endl;
            std::cin >> tempVardas;
            studentai[studentoIndeksas].vardas = tempVardas;
            // std::cin >> studentai[studentoIndeksas].vardas; SEGMENTATION FAULT?

            system("cls");
            std::string tempPavarde;
            std::cout << "Įveskite studento PAVARDĘ:" << std::endl;
            std::cin >> tempPavarde;
            studentai[studentoIndeksas].pavarde = tempPavarde;
            // std::cin >> studentai[studentoIndeksas].pavarde; SEGMENTATION FAULT?

            system("cls");
            std::cout << "Ar norite studento rezultatus įvesti RANKINIU būdu ar sugeneruoti ATSITIKTINIU būdu?" << std::endl;
            std::cout << "1. Rankiniu" << std::endl;
            std::cout << "2. Atsitiktiniu" << std::endl;

            while (true)
            {
                std::cin >> pasirinkimas;
                if ((!(std::cin)) || (std::cin && pasirinkimas != 1 && pasirinkimas != 2))
                {
                    std::cout << "Blogas pasirinkimas" << std::endl;
                    IvestiesValymas();
                    continue;
                }

                break;
            }

            if (pasirinkimas == 1)
            {
                // EGZAMINO REZULTATAS
                system("cls");
                std::cout << "Įveskite EGZAMINO rezultatą" << std::endl;
                int tempEgzaminasRez;
                while (true)
                {
                    std::cin >> tempEgzaminasRez;
                    if (!(std::cin) || (std::cin && (tempEgzaminasRez < 0 || tempEgzaminasRez > 10)))
                    {
                        std::cout << "Blogas įvedimas" << std::endl;
                        IvestiesValymas();

                        continue;
                    }

                    break;
                }
                studentai[studentoIndeksas].egzaminasRez = tempEgzaminasRez;

                // NAMU DARBU REZULTATAS
                system("cls");
                std::cout << "Įveskite NAMŲ DARBŲ rezultatus. Baigus įveskite „-1“." << std::endl;
                int tempNamuDarbasRez;
                int namuDarbuIndeksas = 0;
                while (true)
                {
                    std::cin >> tempNamuDarbasRez;

                    if (tempNamuDarbasRez == -1)
                        break;

                    if (!(std::cin) || (std::cin && (tempNamuDarbasRez < 0 || tempNamuDarbasRez > 10)))
                    {
                        std::cout << "Blogas įvedimas" << std::endl;
                        IvestiesValymas();

                        continue;
                    }
                    else
                    {
                        if (namuDarbuIndeksas < 1)
                        {
                            studentai[studentoIndeksas].namuDarbaiRez = (int *)calloc(1, sizeof(int));
                            studentai[studentoIndeksas].namuDarbaiRez[namuDarbuIndeksas] = tempNamuDarbasRez;
                            studentai[studentoIndeksas].namuDarbuSk = namuDarbuIndeksas;
                            namuDarbuIndeksas++;
                            continue;
                        }
                        else
                        {
                            studentai[studentoIndeksas].namuDarbaiRez = (int *)realloc(studentai[studentoIndeksas].namuDarbaiRez, sizeof(int) * (namuDarbuIndeksas + 1));
                            studentai[studentoIndeksas].namuDarbaiRez[namuDarbuIndeksas] = tempNamuDarbasRez;
                            studentai[studentoIndeksas].namuDarbuSk = namuDarbuIndeksas;
                            namuDarbuIndeksas++;
                            continue;
                        }
                    }
                }
                studentai[studentoIndeksas].egzaminasRez = tempEgzaminasRez;
            }

            if (pasirinkimas == 2)
            {
                studentai[studentoIndeksas].egzaminasRez = AtsitiktinisSkaicius();
                system("cls");
                std::cout << "Įveskite NAMŲ DARBŲ kiekį" << std::endl;

                int namuDarbuSk;
                std::cin >> namuDarbuSk;

                studentai[studentoIndeksas].namuDarbaiRez = (int *)realloc(studentai[studentoIndeksas].namuDarbaiRez, sizeof(int) * namuDarbuSk);
                for (int i = 0; i < namuDarbuSk; i++)
                {
                    studentai[studentoIndeksas].namuDarbaiRez[i] = AtsitiktinisSkaicius();
                }
            }

            studentoIndeksas++;
        }

        // Vidurkis
        if (pasirinkimas == 2)
        {
            system("cls");
            std::cout << "Vardas" << std::setw(10) << "Pavarde" << std::setw(30) << "Galutinis Vidurkis" << std::endl;
            std::cout << "----------------------------------------------------------------------" << std::endl;
            for (int i = 0; i < studentoIndeksas; i++)
            {
                std::cout << studentai[i].vardas << std::setw(9) << studentai[i].pavarde << std::setw(20) << std::fixed << std::setprecision(2) << StudentoVidurkis(i) << std::endl;
            }
            system("pause");
        }

        // Mediana
        if (pasirinkimas == 3)
        {
            system("cls");
            std::cout << "Vardas" << std::setw(10) << "Pavarde" << std::setw(30) << "Galutinis Vidurkis" << std::endl;
            std::cout << "----------------------------------------------------------------------" << std::endl;
            for (int i = 0; i < studentoIndeksas; i++)
            {
                //std::cout << studentai[i].vardas << std::setw(9) << studentai[i].pavarde << std::setw(20) << std::fixed << std::setprecision(2) << StudentoVidurkis(i) << std::endl;
                RikiuotiMasyva(studentoIndeksas, studentai);
            }
            system("pause");
        }
    }
}

void IvestiesValymas()
{
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
}

int AtsitiktinisSkaicius()
{
    std::random_device seed;                                // Seed'as generatoriui
    std::mt19937 generator(seed());                         // Mersenne Twister algorythm
    std::uniform_int_distribution<int> distribution(0, 10); // Random unsigned int'as tranformuojamas i int'a su numatytais reziais

    return distribution(generator);
}

double StudentoVidurkis(int studentoIndeksas)
{
    int suma = 0;
    for (int i = 0; i < studentai[studentoIndeksas].namuDarbuSk; i++) // auto &studentas:studentai
    {
        suma += studentai[studentoIndeksas].namuDarbaiRez[i];
    }
    return (double)((suma / studentai[studentoIndeksas].namuDarbuSk) * 0.4) + (studentai[studentoIndeksas].egzaminasRez * 0.6); // Namu darbu vidurkis * 0.4 + Egzamino rezultatas * 0.6
}

double StudentoMediana(int studentoIndeksas)
{
    struct Studentas studentas = studentai[studentoIndeksas];

    if (studentas.namuDarbaiRezs.size() % 2 != 0)
    {
        return (double)studentas.namuDarbaiRezs[studentas.namuDarbaiRezs.size() / 2];
    }
    else
    {
        return (double)(studentas.namuDarbaiRezs[(studentas.namuDarbaiRezs.size() - 1) / 2] + studentas.namuDarbaiRezs[studentas.namuDarbaiRezs.size() / 2]) / 2.0;
    }
}

void RikiuotiMasyva(int studentoIndeksas, Studentas *studentai)
{
    for (int i = 0; i < studentai[studentoIndeksas].namuDarbuSk; i++)
    {
        std::cout << studentai[studentoIndeksas].namuDarbaiRez[i] << std::endl;
    }
}

