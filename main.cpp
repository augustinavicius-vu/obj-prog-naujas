#include <vector>
#include <iostream>

// Mano bibliotekos/funkcijos
#include "./includes/studentas.h"
#include "./includes/menu.h"

int main()
{
    Studentas s1;
    std::cin >> s1;

    std::cout << s1 << std::endl;

    // Kopijos konstruktorius
    Studentas s2(s1);
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;

    // Perkėlimo konstruktorius
    Studentas s3(std::move(s1));
    std::cout << s1 << std::endl;
    std::cout << s3 << std::endl;

    // Kopijos prisikirimo operatorius
    Studentas s4;
    s4 = s2;
    std::cout << s4 << std::endl;

    // Perkėlimo prisikirimo operatorius
    Studentas s5;
    s5 = std::move(s3);
    std::cout << s3 << std::endl;
    std::cout << s5 << std::endl;

    /*
    // Studentų vektorius
    StudentasVector studentai;
    StudentasVector studentaiGalv;
    StudentasVector studentaiVarg;

    // Pradinė funkcija (Pagrindinis meniu, atsakingas už programos veikimą)
    Ivestis(studentai, studentaiGalv, studentaiVarg);
    */
    
    return 0;
}