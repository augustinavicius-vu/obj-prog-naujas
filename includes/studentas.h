#pragma once

#include <istream>
#include <string>
#include <vector>

class Studentas
{
    private:
        std::string vardas_;
        std::string pavarde_;
        double egzaminas_;
        std::vector<double> namuDarbai_;
    public:
        // Konstruktoriai
        Studentas() : egzaminas_(0) {}
        Studentas(std::istream &is);

        // GET
        std::string vardas() const { return vardas_; }
        std::string pavarde() const { return pavarde_ ;}
        double egzaminas() const { return egzaminas_; }
        const std::vector<double> namuDarbai() const { return namuDarbai_; }

        // SET
        std::istream &nuskaitytiFaila(std::istream &is);
        std::istream &nuskaitytiKonsole(std::istream &is);

        // HELPERS
        double galutinisBalas() const;
};

typedef std::vector<Studentas> StudentasVector;