#include "Companie.h"

Companie::Companie(string denumire, Persoana** angajati, int nrAngajati) {
	this->denumire = denumire;
	this->nrAngajati = nrAngajati;
	this->angajati = new Persoana * [nrAngajati];
	for (int i = 0; i < nrAngajati; i++) {
		this->angajati[i] = angajati[i];
	}
}

Companie::Companie(const Companie& c) {
	this->denumire = c.denumire;
	this->nrAngajati = c.nrAngajati;
	this->angajati = new Persoana * [c.nrAngajati];
	for (int i = 0; i < c.nrAngajati; i++) {
		this->angajati[i] = c.angajati[i];
	}
}

Companie::~Companie() {
	if (angajati != nullptr) {
		for (int i = 0; i < nrAngajati; i++) {
			delete angajati[i];
		}
		delete[] angajati;
	}
}

ostream& operator<<(ostream& iesire, Companie& c) {
	iesire << "Compania: " << c.denumire << " are " << c.nrAngajati << " angajati. Angajatii sunt:\n";
	for (int i = 0; i < c.nrAngajati; i++) {
		cout << *c.angajati[i];
	}

	return iesire;
}

void Companie::adaugaAngajat(Persoana* a) {
	Persoana** aux = new Persoana * [nrAngajati + 1];
	for (int i = 0; i < nrAngajati; i++) {
		aux[i] = angajati[i];
	}

	delete[] angajati;

	aux[nrAngajati++] = a;
	angajati = aux;
}