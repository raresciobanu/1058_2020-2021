#include "Programator.h"

Programator::Programator(string nume, int varsta, const char* telefon, string limbajProgramare)
	:Persoana(nume, varsta, telefon)
{
	this->limbajProgramare = limbajProgramare;
}
