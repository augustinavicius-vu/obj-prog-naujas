#pragma once

#include <string>
#include <vector>

#include "studentas.h"

void ValytiIvesti();
void NaujasStudentas(int &studentoIndeksas, VStudentas &studentai, std::string vardas, std::string pavarde, int egzaminasRez, std::vector<int> namuDarbaiRez);
void RikiuotiStudentus(VStudentas &studentai);