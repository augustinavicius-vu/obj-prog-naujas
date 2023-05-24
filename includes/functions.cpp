#include <iostream>
#include <climits>
#include <algorithm>
#include <fstream>
#include <string>
#include <chrono>
#include <type_traits>
#include <random>

#include "functions.h"
#include "studentas.h"

// Valyti Naudotojo Įvestį
void ValytiIvesti()
{
    std::cin.clear();
    std::cin.ignore(INT_MAX, '\n');
}

void ValytiIsvesti()
{
    #if defined(WIN32) || defined(_WIN32) // Windows
    system("cls");
    #else // Viskas kita (siuo atveju Linux)
    system("clear");
    #endif
}

void Pauze()
{
    #if defined(WIN32) || defined(_WIN32) // Windows
    system("pause");
    #else // Viskas kita (siuo atveju Linux)
    system("sleep 1h");
    #endif
}

int AtsitiktinisSkaicius(int min, int max)
{
    std::random_device seed;
    std::mt19937 generator(seed());
    std::uniform_int_distribution<int> distribution(min, max);

    return distribution(generator);
}

void GeneruotiFaila(int studentuSk, int namuDarbuSk, std::string vieta) 
{
    std::ofstream failas(vieta);
    failas << "Vardas Pavardė ";
    for (int i = 0; i < namuDarbuSk; i++)
    {
        failas << "ND" << i + 1 << " ";
    }
    failas << "Egzaminas\n";

    for (int i = 0; i < studentuSk; i++) {
        failas << "Vardas" << i + 1 << " Pavardė" << i + 1;
        for (int j = 0; j < namuDarbuSk; j++)
        {
            failas << " " << AtsitiktinisSkaicius(1, 10) << " "; // Namų darbai
        }
        failas << AtsitiktinisSkaicius(1, 10) << "\n"; // Egzaminas
    }
        
    failas.close();
}

void EksportuotiStudentus(StudentasVector studentai, std::string vieta)
{
    // Failas Atsidaro
    std::ofstream studentuFailas(vieta);

    // Pavadinimai
    studentuFailas << "Vardas " << "Pavardė ";
    for (int i = 0; i < studentai[0].namuDarbai().size(); i++)
    {
        studentuFailas << "ND" << i +1 << " ";
    }
    studentuFailas << "Egzaminas" << std::endl;

    // Duomenys
    for (auto &studentas : studentai)
    {
        studentuFailas << studentas.vardas() << " " << studentas.pavarde() << " ";
        for (auto &namuDarbas : studentas.namuDarbai())
        {
            studentuFailas << namuDarbas << " ";
        }
        studentuFailas << studentas.egzaminas() << std::endl;
    }

    // Failas Užsidaro
    studentuFailas.close();
}
/*
template <typename Container>
void NaujasStudentas(int &studentoIndeksas, Container &studentai, std::string vardas, std::string pavarde, int egzaminasRez, std::vector<int> namuDarbaiRez)
{
    studentai.push_back({ vardas, pavarde, egzaminasRez, namuDarbaiRez});
    studentoIndeksas++;
}

bool RikiavimoTipas(const Studentas &studentasA, const Studentas &studentasB)
{
    if (studentasA.vardas == studentasB.vardas)
    {
        return studentasA.pavarde < studentasB.pavarde;
    }
    else
    {
        return studentasA.vardas < studentasB.vardas;
    }
    
}

template <typename Container>
void RikiuotiStudentus(Container &studentai)
{
    std::sort(studentai.begin(), studentai.end(), RikiavimoTipas);
}

void RikiuotiStudentusList(LStudentas &studentai)
{
    studentai.sort(RikiavimoTipas);
}

void GeneruotiFailaBalas(int studentuSk, VStudentas studentai, std::string vieta)
{
    std::ofstream failas(vieta);

    for (const auto &studentas : studentai)
    {
        failas << studentas.vardas << " " << studentas.pavarde;
        for (const auto &pazymys: studentas.namuDarbaiRez)
        {
            failas << " " << pazymys;
        }
        failas << " " << studentas.egzaminasRez << std::endl;
    }

    failas.close();
}
template <typename Container>
void NuskaityiFaila(Container &studentai, std::string vieta, int &studentoIndeksas)
{
    studentoIndeksas = 0;
    studentai.clear();

    std::ifstream failas(vieta);

    int laukelis = -1;
    int namuDarbuSk = 0;
    bool skaityti = false;

    std::string tekstas;
    std::string tempVardas;
    std::string tempPavarde;
    int tempEgzaminasRez;
    std::vector<int> tempNamuDarbaiRez;
    while (failas >> tekstas)
    {
        if (skaityti)
        {
            laukelis++;

            // Vardas
            if (laukelis == 0)
            {
                tempVardas = tekstas;
                continue;
            }

            // Pavarde
            if (laukelis == 1)
            {
                tempPavarde = tekstas;
                continue;
            }

            // Namu Darbai
            if (laukelis > 1 && laukelis < 2 + namuDarbuSk)
            {
                tempNamuDarbaiRez.push_back(std::stoi(tekstas));
                continue;
            }

            // Egzaminas
            if (laukelis > 1 + namuDarbuSk)
            {
                tempEgzaminasRez = std::stoi(tekstas);

                NaujasStudentas(studentoIndeksas, studentai, tempVardas, tempPavarde, tempEgzaminasRez, tempNamuDarbaiRez);

                tempNamuDarbaiRez.clear();
                laukelis = -1;
                continue;
            }
        } else {
            if (tekstas == "Egzaminas")
            {
                skaityti = true;
                namuDarbuSk = namuDarbuSk - 2;
            } else {
                namuDarbuSk++;
            }
        }
    }

    failas.close();
}

template <typename Container>
void RusiuotiStudentusBalas(Container &studentai, Container &studentaiA, Container &studentaiB, int &studentaiASk, int &studentaiBSk)
{
    for (const auto& studentas : studentai)
    {
        double studentoVidurkis = StudentoVidurkis(studentas);
        if (studentoVidurkis < 5) {
            studentaiA.push_back(studentas);
        } else {
            studentaiB.push_back(studentas);
        }
    }
}


bool kriterijusRusiuoti(Studentas studentas) {
    double studentoVidurkis = StudentoVidurkis(studentas);
    return studentoVidurkis < 5;
}
template <typename Container>
void RusiuotiStudentusBalasNaujas(Container &studentai, Container &studentaiGalv)
{
    auto studentoIteratorius = studentai.begin();

    while (studentoIteratorius != studentai.end()) {
        double studentoVidurkis = StudentoVidurkis(*studentoIteratorius);

        if (studentoVidurkis >= 5) {
            studentaiGalv.push_back(*studentoIteratorius);
        } else {
            ++studentoIteratorius;
        }
    }

    studentai.erase(std::remove_if(studentai.begin(), studentai.end(), kriterijusRusiuoti), studentai.end()); // Panaikinama, aks nereikalinga
}

void TestuotiSparta(int irasuSk, int namuDarbuSk, std::string vieta, int &studentoIndeksas, VStudentas &studentai)
{
    ValytiIsvesti();

    // Pradžia
    std::cout << "Pradedama programos spartos analizė" << std::endl;
    auto start = std::chrono::high_resolution_clock::now();

    // Failo generavimas
    auto startGen = std::chrono::high_resolution_clock::now();
    GeneruotiFaila(irasuSk, namuDarbuSk, vieta);
    auto endGen = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffGen = endGen - startGen;
    std::cout << irasuSk << " įrašų generavimas ir išvedimas į failą užtruko: " << diffGen.count() << std::endl;

    // Failo nuskaitymas
    auto startRead = std::chrono::high_resolution_clock::now();
    NuskaityiFaila(studentai, vieta, studentoIndeksas);
    auto endRead = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffRead = endRead - startRead;
    std::cout << irasuSk << " įrašų nuskaitymas užtruko: " << diffRead.count() << std::endl;

    // Studentų rūšiavimas
    auto startSort = std::chrono::high_resolution_clock::now();
    VStudentas studentaiA;
    VStudentas studentaiB;
    int studentaiASk = 0;
    int studentaiBSk = 0;
    RusiuotiStudentusBalas(studentai, studentaiA, studentaiB, studentaiASk, studentaiBSk);
    auto endSort = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffSort = endSort - startSort;
    std::cout << irasuSk << " įrašų rūšiavimas į dvi kategorijas užtruko: " << diffSort.count() << std::endl;

    // Vieta galvociams ir vargsiukams
    std::string vietaVarg = vieta.substr(0, vieta.find(".", 0)).append("_vargsiukai.txt");
    std::string vietaGalv = vieta.substr(0, vieta.find(".", 0)).append("_galvociai.txt");
    // Studentų išvedimas į failus galvočiai
    auto startWrite1 = std::chrono::high_resolution_clock::now();
    GeneruotiFailaBalas(studentaiASk, studentaiA, vietaVarg);
    auto endWrite1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffWrite1 = endWrite1 - startWrite1;
    std::cout << irasuSk << " vargšiukų įrašų įrašymas į failą užtruko: " << diffWrite1.count() << std::endl;

    // Studentų išvedimas į failus galvočiai
    auto startWrite2 = std::chrono::high_resolution_clock::now();
    GeneruotiFailaBalas(studentaiBSk, studentaiB, vietaGalv);
    auto endWrite2 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffWrite2 = endWrite2 - startWrite2;
    std::cout << irasuSk << " galvočių įrašų įrašymas į failą užtruko: " << diffWrite2.count() << std::endl;

    // Pabaiga
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diff = end - start;
    std::cout << "Programos analizė užtruko: " << diff.count() << std::endl;

    Pauze();
}

void TestuotiKonteinerius(std::string vieta)
{
    ValytiIsvesti();

    // Pradžia
    std::cout << "Pradedamas konteinerių testavimas" << std::endl;

    // Pradiniai kintamieji
    VStudentas studentaiVector;
    LStudentas studentaiList;
    DStudentas studentaiDeque;

    int studentoIndeksasV = 0;
    int studentoIndeksasL = 0;
    int studentoIndeksasD = 0;

    // Konteineriu testavimas
    // Nuskaitymas
    // Vector
    auto startReadVector = std::chrono::high_resolution_clock::now();
    NuskaityiFaila(studentaiVector, vieta, studentoIndeksasV);
    auto endReadVector = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffReadVector = endReadVector - startReadVector;
    std::cout << studentoIndeksasV << " įrašų nuskaitymas truko su Vector: " << diffReadVector.count() << std::endl;

    // List
    auto startReadList = std::chrono::high_resolution_clock::now();
    NuskaityiFaila(studentaiList, vieta, studentoIndeksasL);
    auto endReadList = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffReadList = endReadList - startReadList;
    std::cout << studentoIndeksasV << " įrašų nuskaitymas truko su List: " << diffReadList.count() << std::endl;

    // Deque
    auto startReadDeque = std::chrono::high_resolution_clock::now();
    NuskaityiFaila(studentaiDeque, vieta, studentoIndeksasD);
    auto endReadDeque = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffReadDeque = endReadDeque - startReadDeque;
    std::cout << studentoIndeksasV << " įrašų nuskaitymas truko su Deque: " << diffReadDeque.count() << std::endl;


    // Rūšiavimas
    // Vector
    auto startSortVector = std::chrono::high_resolution_clock::now();
    RikiuotiStudentus(studentaiVector);
    auto endSortVector = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffSortVector = endSortVector - startSortVector;
    std::cout << studentoIndeksasV << " įrašų rikiavimas truko su Vector: " << diffSortVector.count() << std::endl;

    // List
    auto startSortList = std::chrono::high_resolution_clock::now();
    RikiuotiStudentusList(studentaiList);
    auto endSortList = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffSortList = endSortList - startSortList;
    std::cout << studentoIndeksasV << " įrašų rikiavimas truko su List: " << diffSortList.count() << std::endl;

    // Deque
    auto startSortDeque = std::chrono::high_resolution_clock::now();
    RikiuotiStudentus(studentaiDeque);
    auto endSortDeque = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffSortDeque = endSortDeque - startSortDeque;
    std::cout << studentoIndeksasV << " įrašų rikiavimas truko su Deque: " << diffSortDeque.count() << std::endl;

    // Filtravimas
    // 1 strategija
    // Pagrindiniai kintamieji
    VStudentas studentaiVectorGalv;
    VStudentas studentaiVectorVarg;
    int studentoIndeksasVGalv = 0;
    int studentoIndeksasVVarg = 0;

    LStudentas studentaiListGalv;
    LStudentas studentaiListVarg;
    int studentoIndeksasLGalv = 0;
    int studentoIndeksasLVarg = 0;

    DStudentas studentaiDequeGalv;
    DStudentas studentaiDequeVarg;
    int studentoIndeksasDGalv = 0;
    int studentoIndeksasDVarg = 0;

    // Vector
    auto startFilterVector = std::chrono::high_resolution_clock::now();
    RusiuotiStudentusBalas(studentaiVector, studentaiVectorVarg, studentaiVectorGalv, studentoIndeksasVVarg, studentoIndeksasVGalv);
    auto endFilterVector = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffFilterVector = endFilterVector - startFilterVector;
    std::cout << studentoIndeksasV << " įrašų filtravimas truko su Vector: " << diffFilterVector.count() << std::endl;

    // List
    auto startFilterList = std::chrono::high_resolution_clock::now();
    RusiuotiStudentusBalas(studentaiList, studentaiListVarg, studentaiListGalv, studentoIndeksasLVarg, studentoIndeksasLGalv);
    auto endFilterList = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffFilterList = endFilterList - startFilterList;
    std::cout << studentoIndeksasV << " įrašų filtravimas truko su List: " << diffFilterList.count() << std::endl;

    // Deque
    auto startFilterDeque = std::chrono::high_resolution_clock::now();
    RusiuotiStudentusBalas(studentaiDeque, studentaiDequeVarg, studentaiDequeGalv, studentoIndeksasDVarg, studentoIndeksasDGalv);
    auto endFilterDeque = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffFilterDeque = endFilterDeque - startFilterDeque;
    std::cout << studentoIndeksasV << " įrašų filtravimas truko su Deque: " << diffFilterDeque.count() << std::endl;
    // 2 strategija
    VStudentas studentaiVectorGalv;
    LStudentas studentaiListGalv;
    DStudentas studentaiDequeGalv;

    // Vector
    auto startFilterVector = std::chrono::high_resolution_clock::now();
    RusiuotiStudentusBalasNaujas(studentaiVector, studentaiVectorGalv);
    auto endFilterVector = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffFilterVector = endFilterVector - startFilterVector;
    std::cout << studentoIndeksasV << " įrašų filtravimas truko su Vector: " << diffFilterVector.count() << std::endl;

    // List
    auto startFilterList = std::chrono::high_resolution_clock::now();
    RusiuotiStudentusBalasNaujas(studentaiList, studentaiListGalv);
    auto endFilterList = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffFilterList = endFilterList - startFilterList;
    std::cout << studentoIndeksasV << " įrašų filtravimas truko su List: " << diffFilterList.count() << std::endl;

    // Deque
    auto startFilterDeque = std::chrono::high_resolution_clock::now();
    RusiuotiStudentusBalasNaujas(studentaiDeque, studentaiDequeGalv);
    auto endFilterDeque = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> diffFilterDeque = endFilterDeque - startFilterDeque;
    std::cout << studentoIndeksasV << " įrašų filtravimas truko su Deque: " << diffFilterDeque.count() << std::endl;
    
    Pauze();
}

*/