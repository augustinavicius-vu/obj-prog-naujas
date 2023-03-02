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

void RikiuotiStudentus(VStudentas &studentai)
{
    std::sort(studentai.begin(), studentai.end(), RikiavimoTipas);
}