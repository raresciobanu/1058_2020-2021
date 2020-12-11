#include "Marinar.h"

Marinar::Marinar(string nume, int varsta, const char* telefon, int orePeMare)
	:Persoana(nume, varsta, telefon)
{
	this->orePeMare = orePeMare;
}
