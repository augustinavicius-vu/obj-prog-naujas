#pragma once

#include <string>
#include <vector>

#include "studentas.h"

// Konsolės funkcijos
void ValytiIvesti();
void ValytiIsvesti();
void Pauze();

// Pagalbinės funkcijos
void NaujasStudentas(int &studentoIndeksas, VStudentas &studentai, std::string vardas, std::string pavarde, int egzaminasRez, std::vector<int> namuDarbaiRez);
void RikiuotiStudentus(VStudentas &studentai);

void GeneruotiFaila(int studentuSk, int namuDarbuSk, std::string vieta);
void TestuotiSparta(int irasuSk, int namuDarbuSk, std::string vieta);