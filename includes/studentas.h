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
        Zmogus(const std::string& vardas, const std::string& pavarde) : vardas_(vardas), pavarde_(pavarde) {}
};

class Studentas : public Zmogus
{
    private:
        double egzaminas_;
        std::vector<double> namuDarbai_;
    public:
        // Konstruktorius
        Studentas(const std::string& vardas, const std::string& pavarde, const double &egzaminas, std::vector<double> &namuDarbai) : Zmogus(vardas, pavarde), egzaminas_(egzaminas), namuDarbai_(namuDarbai) {}

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
        Studentas(const Studentas&& naujas)
        : Zmogus(std::move(naujas.vardas_), std::move(naujas.pavarde_)), egzaminas_(naujas.egzaminas_), namuDarbai_(std::move(naujas.namuDarbai_)) {}

        // Perkėlimas
        Studentas(Studentas&& naujas)
        : Zmogus(std::move(naujas.vardas_), std::move(naujas.pavarde_)), egzaminas_(naujas.egzaminas_), namuDarbai_(std::move(naujas.namuDarbai_)) {}

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