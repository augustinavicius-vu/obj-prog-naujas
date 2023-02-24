// Bibliotekos
#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

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
int AtsitiktinisSkaicius();

int main()
{
    std::vector<Studentas> studentai;

    while (ivestisPagr)
    {
        // Buferio valymas is naujo vedant duomenis
        std::cin.clear(); // Ivesties klaidos buferio istrynimas
        system("cls");

        // Veiksmu pasirinkimai - startas
        std::cout << "Prasome pasirinkti veiksma:" << std::endl;
        std::cout << "1. Naujas studentas" << std::endl;
        std::cout << "2. Studentu vidurkio skaiciavimas" << std::endl;
        std::cout << "3. Studentu medianos skaiciavimas" << std::endl;

        // Veiksmo pasrinikimo logika
        int veiksmas = 0;
        while (!(std::cin >> veiksmas)) // KEISTI TIKRINIMA (bloga antra interacija)
        {
            system("cls");
            // Veiksmu pasirinkimai - blogas pasirinkimas
            std::cout << "Prasome pasirinkti veiksma:" << std::endl;
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
                std::cout << "Iveskite studento NAMU DARBU rezultatus, jei norite baigti, iveskite b" << std::endl;
                while (std::cin >> namuDarbasRezTemp)
                {
                    // Namu darbu rez ivedimo pabaiga
                    if (namuDarbasRezTemp == 'b') // Prideti daugiau veiksmo baigimo variaciju
                        break;

                    if (namuDarbasRezTemp < 0 || namuDarbasRezTemp > 10)
                        continue; // Reikia UX Friendly tikrinimo

                    studentai[studentoIndeksas].namuDarbaiRezs.push_back(namuDarbasRezTemp);
                }

                studentoIndeksas++;
            }

            // Atsitiktinis rezultatu vedimas
            if (pasirinkimasRezIvedimas == 2)
            {
                system("cls");
                std::cout << "Iveskite kiek norite NAMU DARBU rezultatu sugeneruoti" << std::endl;

                int namuDarbuRezSk = 0;
                std::cin >> namuDarbuRezSk;

                studentai[studentoIndeksas].egzaminasRez = AtsitiktinisSkaicius();

                for (int i = 0; i < namuDarbuRezSk; i++) {
                    studentai[studentoIndeksas].namuDarbaiRezs.push_back(AtsitiktinisSkaicius());
                    std::cout << AtsitiktinisSkaicius() << std::endl;
                }
                system("pause");
            }
        }

        // Studentu vidurkio skaiciavimas
        if (veiksmas == 2)
        {
            system("cls");
            std::cout << "Vardas Pavarde Vidurkis" << std::endl;
            for (int i = 0; i < studentai.size(); i++)
            {
                std::cout << studentai[i].vardas << " " << studentai[i].pavarde << " " << std::setprecision(2) << std::fixed << StudentoVidurkis(studentai, i) << std::endl; // KEISTI FUNKCIJOS ARGUMENTUS
            }
            system("pause");
        }

        // Studentu medianos skaiciavimas
        if (veiksmas == 3)
        {
            system("cls");
            std::cout << "Vardas Pavarde Mediana" << std::endl;
            for (int i = 0; i < studentai.size(); i++)
            {
                std::cout << studentai[i].vardas << " " << studentai[i].pavarde << " " << std::setprecision(2) << std::fixed << StudentoMediana(studentai, i) << std::endl; // KEISTI FUNKCIJOS ARGUMENTUS
            }
            system("pause");
        }
    }
}

double StudentoVidurkis(std::vector<Studentas> studentai, int studentoIndeksas)
{
    int suma = 0;
    for (int i = 0; i < studentai[studentoIndeksas].namuDarbaiRezs.size(); i++)
    {
        suma += studentai[studentoIndeksas].namuDarbaiRezs[i];
    }
    return (double)((suma / studentai[studentoIndeksas].namuDarbaiRezs.size()) * 0.4) + (studentai[studentoIndeksas].egzaminasRez * 0.6); // Namu darbu vidurkis * 0.4 + Egzamino rezultatas * 0.6
}

double StudentoMediana(std::vector<Studentas> studentai, int studentoIndeksas)
{
    struct Studentas studentas = studentai[studentoIndeksas];
    std::sort(studentas.namuDarbaiRezs.begin(), studentas.namuDarbaiRezs.end());

    if (studentas.namuDarbaiRezs.size() % 2 != 0)
    {
        return (double)studentas.namuDarbaiRezs[studentas.namuDarbaiRezs.size() / 2];
    }
    else
    {
        return (double)(studentas.namuDarbaiRezs[(studentas.namuDarbaiRezs.size() - 1) / 2] + studentas.namuDarbaiRezs[studentas.namuDarbaiRezs.size() / 2]) / 2.0;
    }
}

int AtsitiktinisSkaicius()
{
    std::random_device seed; // Seed'as generatoriui
    std::mt19937 generator(seed()); // Mersenne Twister algorythm
    std::uniform_int_distribution<int> distribution(0, 10); // Random unsigned int'as tranformuojamas i int'a su numatytais reziais

    return distribution(generator);
}