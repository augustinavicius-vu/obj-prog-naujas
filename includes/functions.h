#pragma once
#include <string>
#include <vector>

#include "studentas.h"

// Konsolės funkcijos
void ValytiIvesti();
void ValytiIsvesti();
void Pauze();

// Papildomos funkcijos
int AtsitiktinisSkaicius(int min, int max);

// Funkcijos
void GeneruotiFaila(int studentuSk, int namuDarbuSk, std::string vieta);
void EksportuotiStudentus(StudentasVector studentai, std::string vieta);


/*
// Pagalbinės funkcijos
template <typename Container>
void NaujasStudentas(int &studentoIndeksas, Container &studentai, std::string vardas, std::string pavarde, int egzaminasRez, std::vector<int> namuDarbaiRez);

template <typename Container>
void RikiuotiStudentus(Container &studentai);

template <typename Container>
void RusiuotiStudentusBalas(Container &studentai, Container &studentaiA, Container &studentaiB, int &studentaiASk, int &studentaiBSk);

void GeneruotiFailaBalas(int studentuSk, VStudentas studentai, std::string vieta);
void TestuotiSparta(int irasuSk, int namuDarbuSk, std::string vieta, int &studentoIndeksas, VStudentas &studentai);
void TestuotiKonteinerius(std::string vieta);
*/