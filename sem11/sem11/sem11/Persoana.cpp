#include "Persoana.h"

Persoana::Persoana()
{
	this->varsta = 33;
	this->nume = "n/a";
	this->telefon = new char[strlen("Anonim") + 1];
	strcpy_s(this->telefon, strlen("Anonim") + 1, "Anonim");
}

Persoana::Persoana(string nume, int varsta, const char* telefon)
{
	this->nume = nume;
	this->varsta = varsta;
	this->telefon = new char[strlen(telefon) + 1];
	strcpy_s(this->telefon, strlen(telefon) + 1, telefon);
}

Persoana::Persoana(const Persoana& p)
{
	this->nume = p.nume;
	this->varsta = p.varsta;
	this->telefon = new char[strlen(p.telefon) + 1];
	strcpy_s(this->telefon, strlen(p.telefon) + 1, p.telefon);
}

Persoana& Persoana::operator=(const Persoana& p)
{
	if (this != &p) {
		if (telefon != nullptr) {
			delete[] telefon;
		}

		this->nume = p.nume;
		this->varsta = p.varsta;
		this->telefon = new char[strlen(p.telefon) + 1];
		strcpy_s(this->telefon, strlen(p.telefon) + 1, p.telefon);
	}

	return *this;
}

Persoana::~Persoana()
{
	if (telefon != nullptr) {
		delete[] telefon;
	}
}

void Persoana::scrieInFisierBinar(ofstream& iesire)
{
	//pt string/char* intai se salveaza in fisier dimensiunea sirului de caract + 1 (pt '\0')
	//pentru a putea mai tarziu sa stii cat sa citesti din fisier.

	int dim1 = nume.size() + 1; // +1 - pentru '\0'
	iesire.write((char*)&dim1, sizeof(dim1));

	iesire.write(nume.c_str(), dim1);

	iesire.write((char*)&varsta, sizeof(varsta)); // CITESTE DE LA adresa lui varsta primii 4 bytes si scriei in fisierul binar.

	int dim2 = strlen(telefon) + 1; // +1 - pentru '\0'
	iesire.write((char*)&dim2, sizeof(dim2));

	iesire.write(telefon, dim2);
}

void Persoana::citireDinFisierBinar(ifstream& intrare)
{
	int dim1 = 0;
	intrare.read((char*)&dim1, sizeof(dim1));
	char aux1[100];
	intrare.read(aux1, dim1);
	nume = aux1;

	intrare.read((char*)&varsta, sizeof(varsta)); // CITESTE DIN FISIER 4 bytes si scriei LA adresa lui varsta.

	int dim2 = 0;
	intrare.read((char*)&dim2, sizeof(dim2));
	char aux2[100];
	intrare.read(aux2, dim2);

	if (telefon != nullptr) {
		delete[]telefon;
	}
	telefon = new char[dim2];
	strcpy_s(telefon, dim2, aux2);
}

ostream& operator<<(ostream& iesire, Persoana& p)
{
	iesire << "Nume: " << p.nume << " varsta: " << p.varsta << " telefon: " << p.telefon << endl;
	return iesire;
}

ofstream& operator<<(ofstream& iesire, Persoana& p)
{
	iesire << p.nume << endl << p.varsta << endl << p.telefon << endl;
	return iesire;
}

ifstream& operator>>(ifstream& intrare, Persoana& p)
{
	getline(intrare, p.nume); //getline este din libraria string

	intrare >> p.varsta;
	intrare.ignore();

	char aux[100];
	intrare.getline(aux, 100); //intrare.getline este din libraria istream

	if (p.telefon != nullptr) {
		delete[] p.telefon;
	}
	p.telefon = new char[strlen(aux) + 1];
	strcpy_s(p.telefon, strlen(aux) + 1, aux);

	return intrare;
}
