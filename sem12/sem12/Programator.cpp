#include "Programator.h"

Programator::Programator(string nume, int varsta, const char* telefon, string limbajProgramare, double salariu)
	:Persoana(nume, varsta, telefon, salariu)
{
	this->limbajProgramare = limbajProgramare;
}

double Programator::calculeazaSalariuDupaMarireProcentuala(double procentaj)
{
	salariu += salariu * procentaj / 100 + 300;
	return salariu;
}
