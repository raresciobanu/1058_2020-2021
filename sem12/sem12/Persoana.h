#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

#include "InterfataCalcule.h"

class Persoana : InterfataCalcule
{
public:
	string nume;
	int varsta;
	char* telefon;
	double salariu;

	Persoana();

	Persoana(string nume, int varsta, const char* telefon, double salariu);

	Persoana(const Persoana& p);

	Persoana& operator=(const Persoana& p);

	~Persoana();

	friend ostream& operator<<(ostream& iesire, Persoana& p);

	friend ofstream& operator<<(ofstream& iesire, Persoana& p);

	friend ifstream& operator>>(ifstream& intrare, Persoana& p);

	void scrieInFisierBinar(ofstream& iesire);

	void citireDinFisierBinar(ifstream& intrare);

	double calculeazaSalariuDupaMarireProcentuala(double procentaj);
};

