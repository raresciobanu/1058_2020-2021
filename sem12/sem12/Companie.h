#pragma once
#include "Persoana.h"
class Companie
{
public:
	string denumire;
	int nrAngajati;
	Persoana** angajati;

	Companie(string denumire, Persoana** angajati, int nrAngajati);

	Companie(const Companie& c);

	~Companie();

	friend ostream& operator<<(ostream& iesire, Companie& c);

	void adaugaAngajat(Persoana* a);
};

