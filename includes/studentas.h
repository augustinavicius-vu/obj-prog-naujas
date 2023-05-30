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
        std::string vardas_; //!< Žmogaus vardas
        std::string pavarde_; //!< Žmogaus pavardė
};

class Studentas : public Zmogus
{
    private:
        double egzaminas_; //!< Egzamino pažymys
        std::vector<double> namuDarbai_; //!< Namų darbų pažymiai vektoriuje
    public:
        // Default
        Studentas() : egzaminas_(0) {} //!< Default konstruktorius
        Studentas(std::istream& is); //!< Konstruktiorius skirtas duomenų įvedimui

        // GET
        std::string vardas() const { return vardas_; } //!< Metodas gauti vardą
        std::string pavarde() const { return pavarde_ ;} //!< Metodas gauti pavardę
        double egzaminas() const { return egzaminas_; } //!< Metodas gauti egzamino balą
        const std::vector<double> namuDarbai() const { return namuDarbai_; } //! Metodas gauti namų darbų vektorių

        // SET
        std::istream &nuskaitytiFaila(std::istream &is); //!< Metodas pritaikytas failo nuskaitymui ir duomenų įrašymui
        std::istream &nuskaitytiKonsole(std::istream &is); //!< Metodas pritaikytas naudotojo ivesčiai priimti ir gautus duomenis įrašyti

        // HELPERS
        double galutinisBalas() const; //!< Metodas grąžinantis studento balutinį balą
};

typedef std::vector<Studentas> StudentasVector;

// Predikatai
bool palygintiVardus(const Studentas &studentasA, const Studentas &studentasB);
bool vertinimoKriterijus(const Studentas &studentas);