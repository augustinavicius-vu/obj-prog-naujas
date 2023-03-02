#include <iostream>
#include <vector>

void NaujasStudentas(int &studentoIndeksas, VStudentas &studentai, std::string vardas, std::string pavarde, int egzaminasRez, std::vector<int> namuDarbaiRez)
{
    studentai.push_back(Studentas());

    studentai[studentoIndeksas].vardas = vardas;
    studentai[studentoIndeksas].pavarde = pavarde;
    studentai[studentoIndeksas].egzaminasRez = egzaminasRez;
    studentai[studentoIndeksas].namuDarbaiRez = namuDarbaiRez;

    studentoIndeksas++;
}