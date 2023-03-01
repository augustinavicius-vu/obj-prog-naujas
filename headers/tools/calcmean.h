#include <vector>

double StudentoVidurkis(Studentas studentas)
{
    int suma = 0;
    for (int i = 0; i < studentas.namuDarbaiRez.size(); i++) // auto &studentas:studentai
    {
        suma += studentas.namuDarbaiRez[i];
    }
    return (double)((suma / studentas.namuDarbaiRez.size()) * 0.4) + (studentas.egzaminasRez * 0.6); // Namu darbu vidurkis * 0.4 + Egzamino rezultatas * 0.6
}