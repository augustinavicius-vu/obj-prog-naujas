#include <iostream>

// Funkciju deklaracijos
void DidintiStudentuMasyva();

bool ivestisPagr = true;

// Studento struktura
typedef struct Studentas
{
    std::string vardas;
    std::string pavarde;
    int pazymiai[10];
};

// Studentu dinaminis masyvas
struct Studentas *studentai;
size_t studentaiMasyvoDydis = 100;

int main()
{
    while (ivestisPagr)
    {
        // Veiksmu pasirinkimai - startas
        std::cout << "Prasome pasirinkti veiksma:" << std::endl;
        std::cout << "1. Naujas studentas" << std::endl;
        std::cout << "2. Studentu vidurkio skaiciavimas" << std::endl;
        std::cout << "3. Studentu medianos skaiciavimas" << std::endl;

        // Veiksmo pasrinikimo logika
        int veiksmas = 0;
        while (!(std::cin >> veiksmas))
        {
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
        // Pasirinktas veiksmas nera is pateiktu galimu
        if (veiksmas != 1 && veiksmas != 2 && veiksmas != 3)
        {
            std::cout << "Netinkamas veiksmas" << std::endl;
        }

        // Naujas studentas
        if (veiksmas == 1)
        {
        }

        // Studentu vidurkio skaiciavimas
        if (veiksmas == 2)
        {
        }

        // Studentu medianos skaiciavimas
        if (veiksmas == 3)
        {
        }
    }
}