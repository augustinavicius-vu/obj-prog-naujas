#include <iostream>
#include <iomanip>

#include "../tools/calcmean.h"


void PasirinkimasSkaiciuotiVidurki(VStudentas &studentai)
{
    system("cls");
    std::cout << std::setw(20) << std::left << "Vardas";
    std::cout << std::setw(20) << std::left << "Pavardė";
    std::cout << "Galutinis vid." << std::endl;
    std::cout << "------------------------------------------------------" << std::endl;

    RikiuotiStudentus(studentai);

    for (auto &studentas : studentai)
    {
        std::cout << std::setw(20) << std::left << studentas.vardas;
        std::cout << std::setw(20) << std::left << studentas.pavarde;
        std::cout << StudentoVidurkis(studentas)  << std::endl;
    }

    system("pause");
}