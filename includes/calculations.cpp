#include <algorithm>
#include <random>
#include "studentas.h" // Studentas VStudentas

// Studento Vidurkis - 0.4 namų darbų rez. * 0.6 egzamino rezultatas
double StudentoVidurkis(Studentas studentas)
{
    int suma = 0;
    for (int i = 0; i < studentas.namuDarbaiRez.size(); i++)
    {
        suma += studentas.namuDarbaiRez[i];
    }
    return (double)((suma / studentas.namuDarbaiRez.size()) * 0.4) + (studentas.egzaminasRez * 0.6); // Namu darbu vidurkis * 0.4 + Egzamino rezultatas * 0.6
}

// Studento Mediana
double StudentoMediana(Studentas studentas)
{
    std::sort(studentas.namuDarbaiRez.begin(), studentas.namuDarbaiRez.end());

    if (studentas.namuDarbaiRez.size() % 2 != 0)
    {
        return (double)studentas.namuDarbaiRez[studentas.namuDarbaiRez.size() / 2];
    }
    else
    {
        return (double)(studentas.namuDarbaiRez[(studentas.namuDarbaiRez.size() - 1) / 2] + studentas.namuDarbaiRez[studentas.namuDarbaiRez.size() / 2]) / 2.0;
    }
}

// Atsitiktinis Natūralusis Skaičius
int AtsitiktinisSkaicius(int min, int max)
{
    std::random_device seed;
    std::mt19937 generator(seed());
    std::uniform_int_distribution<int> distribution(min, max);

    return distribution(generator);
}