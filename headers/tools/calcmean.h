#include <vector>
#include "studstruct.h" // struct Studentas

double StudentoVidurkis(int studentoIndeksas, std::vector<Studentas> studentai)
{
    int suma = 0;
    for (int i = 0; i < studentai[studentoIndeksas].namuDarbaiRez.size(); i++) // auto &studentas:studentai
    {
        suma += studentai[studentoIndeksas].namuDarbaiRez[i];
    }
    return (double)((suma / studentai[studentoIndeksas].namuDarbaiRez.size()) * 0.4) + (studentai[studentoIndeksas].egzaminasRez * 0.6); // Namu darbu vidurkis * 0.4 + Egzamino rezultatas * 0.6
}