#pragma once

#include <string>
#include <vector>
#include <list>
#include <deque>

struct Studentas
{
    std::string vardas;
    std::string pavarde;
    int egzaminasRez;
    std::vector<int> namuDarbaiRez;
};

typedef std::vector<Studentas> VStudentas;
typedef std::list<Studentas> LStudentas;
typedef std::deque<Studentas> DStudentas;