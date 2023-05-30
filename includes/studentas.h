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


        // RULE OF FIVE
        // Destruktorius
        ~Studentas()
        {
            vardas_.clear();
            pavarde_.clear();
            egzaminas_ = 0;
            namuDarbai_.clear();
            namuDarbai_.shrink_to_fit();
        }

        // Kopija
        Studentas(const Studentas &naujas) : vardas_(naujas.vardas_), pavarde_(naujas.pavarde_), egzaminas_(naujas.egzaminas_), namuDarbai_(naujas.namuDarbai_) { }

        // Perkėlimas
        Studentas(Studentas &&naujas) noexcept : vardas_(std::move(naujas.vardas_)), pavarde_(std::move(naujas.pavarde_)), egzaminas_(std::move(naujas.egzaminas_)), namuDarbai_(std::move(naujas.namuDarbai_)) { naujas.~Studentas(); }

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

                naujas.~Studentas();
            }

            return *this;
        }

        // cin ir cout perdengimai
        friend std::istream& operator>>(std::istream& ivestis, Studentas &studentas)
        {
            ivestis >> studentas.vardas_ >> studentas.pavarde_ >> studentas.egzaminas_;
            size_t darbuSkaicius;
            ivestis >> darbuSkaicius;
            studentas.namuDarbai_.resize(darbuSkaicius);
            for (size_t i = 0; i < darbuSkaicius; ++i) {
                ivestis >> studentas.namuDarbai_[i];
            }
            return ivestis;
        }

        friend std::ostream& operator<<(std::ostream& isvestis, const Studentas &studentas) {
            isvestis << "Vardas: " << studentas.vardas_ << std::endl;
            isvestis << "Pavardė: " << studentas.pavarde_ << std::endl;
            isvestis << "Egzaminas: " << studentas.egzaminas_ << std::endl;
            isvestis << "Namų darbai: ";
            for (const auto& darbas : studentas.namuDarbai_) {
                isvestis << darbas << " ";
            }
            isvestis << std::endl;
            return isvestis;
        }
};

typedef std::vector<Studentas> StudentasVector;

// Predikatai
bool palygintiVardus(const Studentas &studentasA, const Studentas &studentasB);
bool vertinimoKriterijus(const Studentas &studentas);