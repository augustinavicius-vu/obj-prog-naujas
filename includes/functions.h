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