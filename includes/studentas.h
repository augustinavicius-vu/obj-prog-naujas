#pragma once

#include <string>
#include <vector>

struct Studentas
{
    std::string vardas;
    std::string pavarde;
    int egzaminasRez;
    std::vector<int> namuDarbaiRez;
};

typedef std::vector<Studentas> VStudentas;