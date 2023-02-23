// Bibliotekos
#include <iomanip>
#include <iostream>
#include <string>
#include <ctime>
#include <vector>

// Pagrindiniai kintamieji
bool ivestisPagr = true;
int studentoIndeksas = 0;

// Studento struktura
struct Studentas
{
    std::string vardas;
    std::string pavarde;
    std::vector<int> namuDarbaiRezs;
    int egzaminasRez;
};

// Funkcijos
double StudentoVidurkis(std::vector<Studentas> studentai, int studentoIndeksas);
double StudentoMediana(std::vector<Studentas> studentai, int studentoIndeksas);

int main()
{
    std::vector<Studentas> studentai;

    while (ivestisPagr)
    {
        // Buferio valymas is naujo vedant duomenis
        std::cin.clear();            // Ivesties klaidos buferio istrynimas
        system("cls");

        // Veiksmu pasirinkimai - startas
        std::cout << "Prasome pasirinkti veiksma:" << std::endl;
        std::cout << "1. Naujas studentas" << std::endl;
        std::cout << "2. Studentu vidurkio skaiciavimas" << std::endl;
        std::cout << "3. Studentu medianos skaiciavimas" << std::endl;

        // Veiksmo pasrinikimo logika
        int veiksmas = 0;
        while (!(std::cin >> veiksmas)) // KEISTI TIKRINIMA
        {
            system("cls");
            // Veiksmu pasirinkimai - blogas pasirinkimas
            std::cout << "Pasirinktas veiksmas neteisingas, galimi pasirinkimai 1, 2, 3:" << std::endl;
            std::cout << "1. Naujas studentas" << std::endl;
            std::cout << "2. Studentu vidurkio skaiciavimas" << std::endl;
            std::cout << "3. Studentu medianos skaiciavimas" << std::endl;

            // Blogas veiksmo buferio istrynimas
            std::cin.clear();            // Ivesties klaidos buferio istrynimas
            std::cin.ignore(1000, '\n'); // Ivesties buferis ignoruojamas iki naujos eilutes
        }


        // Veiksmai
        // Naujas studentas
        if (veiksmas == 1)
        {
            system("cls");

            studentai.push_back(Studentas()); // Sukuriame vietos naujam studentui pagal Studentas struct
            
            std::cout << "Iveskite studento VARDA" << std::endl; // STUDENTO VARDAS
            std::cin >> studentai[studentoIndeksas].vardas;
            system("cls");
            std::cout << "Iveskite studento PAVARDE" << std::endl; // STUDENTO PAVARDE
            std::cin >> studentai[studentoIndeksas].pavarde;
            system("cls");

            int pasirinkimasRezIvedimas = 0; // REZULTATU IVEDIMAS
            std::cout << "Ar norite RANKINIU budu surasyti namu darbu ir egzamino rezultatus AR ATSITIKTINIU budu?" << std::endl;
            std::cout << "1. Rankiniu" << std::endl;
            std::cout << "2. Atsitiktiniu" << std::endl;

            // Rankinio ar Atsitiktinio ivedimo logika
            while (!(std::cin >> pasirinkimasRezIvedimas)) // KEISTI TIKRINIMA (kad butu ir pacios reiksmes reziu tikrinimas)
            {
                // Veiksmu pasirinkimai - blogas pasirinkimas
                std::cout << "Pasirinktas veiksmas neteisingas, galimi variantai RANKINIU (1) arba ATSITIKTINIU (2)" << std::endl;
                std::cout << "1. Rankiniu" << std::endl;
                std::cout << "2. Atsitiktiniu" << std::endl;

                // Blogas veiksmo buferio istrynimas
                std::cin.clear();            // Ivesties klaidos buferio istrynimas
                std::cin.ignore(1000, '\n'); // Ivesties buferis ignoruojamas iki naujos eilutes
            }

            system("cls");

            // Rankinis rezultatu vedimas
            if (pasirinkimasRezIvedimas == 1)
            {
                // Egzamino rezultatas
                int egzaminasRezTemp = 0;
                std::cout << "Iveskite studento EGZAMINO rezultata" << std::endl;

                while (!(std::cin >> egzaminasRezTemp)) // KEISTI TIKRINIMA (kad butu ir pacios reiksmes reziu tikrinimas)
                {
                    // Egzamino rezultatas
                    std::cout << "Irasytas egzamino rezultatas klaidingas" << std::endl;

                    // Blogas veiksmo buferio istrynimas
                    std::cin.clear();            // Ivesties klaidos buferio istrynimas
                    std::cin.ignore(1000, '\n'); // Ivesties buferis ignoruojamas iki naujos eilutes
                }

                studentai[studentoIndeksas].egzaminasRez = egzaminasRezTemp;

                // Namu darbo rezultatas
                int namuDarbasRezTemp = 0;
                system("cls");
                std::cout << "Iveskite studento NAMU DARBO rezultatus, jei norite baigti, iveskite b" << std::endl;
                while (std::cin >> namuDarbasRezTemp)
                {
                    // Namu darbu rez ivedimo pabaiga
                    if (namuDarbasRezTemp == 'b')
                        break;

                    if (namuDarbasRezTemp < 0 || namuDarbasRezTemp > 10)
                        continue; // Reikia UX Friendly tikrinimo

                    studentai[studentoIndeksas].namuDarbaiRezs.push_back(namuDarbasRezTemp);
                }
            }

            // Atsitiktinsi rezultatu vedimas
            if (pasirinkimasRezIvedimas == 2)
            {
            }
        }

        // Studentu vidurkio skaiciavimas
        if (veiksmas == 2)
        {
            std::cout << "Vardas Pavarde Vidurkis" << std::endl;
            for (int i = 0; i < studentai.size(); i++)
            {
                std::cout << studentai[i].vardas << " " << studentai[i].pavarde << " " << std::setprecision(2) << std::fixed  << StudentoVidurkis(studentai, i) << std::endl; // KEISTI FUNKCIJOS ARGUMENTUS
            }
            system("pause");
        }

        // Studentu medianos skaiciavimas
        if (veiksmas == 3)
        {
        }

        studentoIndeksas++;
    }
}

double StudentoVidurkis(std::vector<Studentas> studentai, int studentoIndeksas)
{
    int suma = 0;
    for (int i = 0; i < studentai[studentoIndeksas].namuDarbaiRezs.size(); i++)
    {
        suma += studentai[studentoIndeksas].namuDarbaiRezs[i];
    }
    return (double) suma / studentai[studentoIndeksas].namuDarbaiRezs.size();
}

double StudentoMediana(std::vector<Studentas> studentai, int studentoIndeksas)
{
    double mediana = 0;
    return mediana;
}