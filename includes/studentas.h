#pragma once

#include <algorithm>
#include <fstream>
#include <istream>
#include <string>
#include <vector>
#include <iostream>

class Zmogus
{
    protected:
        std::string vardas_;
        std::string pavarde_;
    public:
        virtual void info() {};
};

class Studentas : public Zmogus
{
    private:
        double egzaminas_;
        std::vector<double> namuDarbai_;
    public:
        // Default
        Studentas() : egzaminas_(0) {}
        Studentas(std::istream& is);

        // Override'as
        void info() override
        {
            std::cout << "Studentas: " << vardas_ << " " << pavarde_ << std::endl;
        }

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

// Predikatai
bool palygintiVardus(const Studentas &studentasA, const Studentas &studentasB);
bool vertinimoKriterijus(const Studentas &studentas);