#include <vector>
#include <iostream>

// Mano bibliotekos/funkcijos
#include "./includes/studentas.h"
#include "./includes/menu.h"

#if defined(WIN32) || defined(_WIN32) // Windows
#include <windows.h>
#pragma execution_character_set( "utf-8" )
#endif

int main()
{
#if defined(WIN32) || defined(_WIN32) // Windows
SetConsoleOutputCP( 65001 );
#endif

    // Studentų vektorius
    StudentasVector studentai;
    StudentasVector studentaiGalv;
    StudentasVector studentaiVarg;

    // Pradinė funkcija (Pagrindinis meniu, atsakingas už programos veikimą)
    Ivestis(studentai, studentaiGalv, studentaiVarg);
    
    return 0;
}