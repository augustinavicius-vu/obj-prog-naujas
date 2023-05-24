#include <vector>
#include <iostream>

// Mano bibliotekos/funkcijos
#include "./includes/studentas.h"
#include "./includes/menu.h"
#include "./includes/calculations.h"

int main()
{
    // Studentų vektorius
    StudentasVector studentai;

    // Pradinė funkcija (Pagrindinis meniu, atsakingas už programos veikimą)
    Ivestis(studentai);
    
    return 0;
}