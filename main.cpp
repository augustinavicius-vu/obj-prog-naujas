#include <vector>
#include <iostream>

#include "./includes/studentas.h"
#include "./includes/calculations.h"
#include "./includes/helpers.h"
#include "./includes/menu.h"

// Pagrindiniai kintamieji
bool ivestisPagr = true;
int studentoIndeksas = 0;

int main()
{
    // Studentų vektoriaus inicializacija
    VStudentas studentai;

    // Pradinė funkcija (Pagrindinis meniu, atsakingas už programos veikimą)
    Ivestis(studentoIndeksas, studentai);

    return 0;
}