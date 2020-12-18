#include "Marinar.h"

Marinar::Marinar(string nume, int varsta, const char* telefon, int orePeMare, double salariu)
	:Persoana(nume, varsta, telefon, salariu)
{
	this->orePeMare = orePeMare;
}

double Marinar::calculeazaSalariuDupaMarireProcentuala(double procentaj)
{
	salariu += salariu * procentaj / 100 + 500;
	return salariu;
}
