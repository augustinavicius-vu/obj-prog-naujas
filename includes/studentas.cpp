#include <istream>
#include <iostream>
#include <string>

#include "studentas.h"

Studentas::Studentas(std:: istream &is)
{
    nuskaityti(is);
}

std::istream& Studentas::nuskaityti(std::istream &is)
{
    is >> vardas_ >> pavarde_;

    double namuDarbas;
    while (is >> namuDarbas)
    {
        namuDarbai_.push_back(namuDarbas);
    }

    egzaminas_ = namuDarbas;

    return is;
}

double Studentas::galutinisBalas() const
{
    double suma = 0;

    for (auto &namuDarbas : namuDarbai_)
    {
        suma += namuDarbas;
    }

    return ((suma / namuDarbai_.size()) * 0.4) + (egzaminas_ * 0.6);
}