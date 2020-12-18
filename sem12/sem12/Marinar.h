#pragma once
#include "Persoana.h"
class Marinar :
	public Persoana
{
public:
	int orePeMare;

	Marinar(string nume, int varsta, const char* telefon, int orePeMare, double salariu);

	double calculeazaSalariuDupaMarireProcentuala(double procentaj);
};

