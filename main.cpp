#include <vector>
#include <iostream>

// Mano bibliotekos/funkcijos
#include "./includes/studentas.h"
#include "./includes/menu.h"

int main()
{
    // Studentų vektorius
    StudentasVector studentai;
    StudentasVector studentaiGalv;
    StudentasVector studentaiVarg;

    // Pradinė funkcija (Pagrindinis meniu, atsakingas už programos veikimą)
    Ivestis(studentai, studentaiGalv, studentaiVarg);
    
    return 0;
}