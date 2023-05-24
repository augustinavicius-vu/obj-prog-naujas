#pragma once
#include "studentas.h"

void Ivestis(StudentasVector &studentai, StudentasVector &studentaiGalv, StudentasVector &studentaiVarg);

void PasirinkimasNaujasStudentas(StudentasVector &studentai); 
void PasirinkimasGeneruotiStudentuFaila();
void PasirinkimasRikiuotiStudentus(StudentasVector &studentai);
void PasirinkimasRusiuotiStudentus(StudentasVector &studentai, StudentasVector &studentaiGalv, StudentasVector &studentaiVarg);
void PasirinkimasEksportuotiStudentus(StudentasVector &studentai);