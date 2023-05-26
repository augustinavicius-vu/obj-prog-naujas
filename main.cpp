#include <vector>
#include <iostream>

// Mano bibliotekos/funkcijos
#include "./includes/studentas.h"
#include "./includes/menu.h"

int main()
{
    Studentas s1;
    Studentas s2;

    // Ivestis
    std::cin >> s1;
    std::cin >> s2;

    // Isvestis
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;


    s1 = s2;
    std::cout << s1 << std::endl;
    std::cout << s2 << std::endl;




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