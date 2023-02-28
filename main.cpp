// Bibliotekos
#include <iomanip>
#include <iostream>
#include <vector>
#include <algorithm>

#include <limits.h>
#include <windows.h>

#pragma execution_character_set("utf-8");

// Pagrindiniai kintamieji
bool ivestisPagr = true;
int studentoIndeksas = 0;

#include "typedefs.h"
#include "./headers/menu/menu-main.h"

int main()
{
    // Nustatyti konsolę į lietuviškas raides palaikantį output'ą
    SetConsoleOutputCP(65001);

    // Studentų vektoriaus inicializacija
    VStudentas studentai;

    // Pradinė funkcija (Pagrindinis meniu, atsakingas už programos veikimą)
    Ivestis(studentoIndeksas, studentai);

    return 0;
}