#pragma once
#include "Persoana.h"
class Programator :
    public Persoana
{
public:
    string limbajProgramare;

    Programator(string nume, int varsta, const char* telefon, string limbajProgramare);
};

