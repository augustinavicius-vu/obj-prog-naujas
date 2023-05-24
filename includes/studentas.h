#pragma once

#include <algorithm>
#include <fstream>
#include <istream>
#include <string>
#include <vector>
#include <iostream>

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

        // Destruktorius
        ~Studentas() {}

        // Kopija
        Studentas(const Studentas &naujas) : vardas_(naujas.vardas_), pavarde_(naujas.pavarde_), egzaminas_(naujas.egzaminas_), namuDarbai_(naujas.namuDarbai_) {}

        // Perkėlimas
        Studentas(Studentas &&naujas) noexcept : vardas_(std::move(naujas.vardas_)), pavarde_(std::move(naujas.pavarde_)), egzaminas_(std::move(naujas.egzaminas_)), namuDarbai_(std::move(naujas.namuDarbai_)) {}

        // Priskyrimo Operatorius
        Studentas &operator = (const Studentas& naujas)
        {
            if (this != &naujas)
            {
                vardas_ = naujas.vardas_;
                pavarde_ = naujas.pavarde_;
                egzaminas_ = naujas.egzaminas_;
                namuDarbai_ = naujas.namuDarbai_;
            }

            return *this;
        }

        // Perkėlimo Operatorius
        Studentas &operator=(Studentas &&naujas) noexcept
        {
            if (this != &naujas)
            {
                vardas_ = std::move(naujas.vardas_);
                pavarde_ = std::move(naujas.pavarde_);
                egzaminas_ = std::move(naujas.egzaminas_);
                namuDarbai_ = std::move(naujas.namuDarbai_);
            }

            return *this;
        }
};

typedef std::vector<Studentas> StudentasVector;

// Predikatai
bool palygintiVardus(const Studentas &studentasA, const Studentas &studentasB);
bool vertinimoKriterijus(const Studentas &studentas);