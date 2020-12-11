#pragma once
#include<iostream>
#include<fstream>
#include<string>
using namespace std;

class Persoana
{
public:
	string nume;
	int varsta;
	char* telefon;

	Persoana();

	Persoana(string nume, int varsta, const char* telefon);

	Persoana(const Persoana& p);

	Persoana& operator=(const Persoana& p);

	~Persoana();

	friend ostream& operator<<(ostream& iesire, Persoana& p);

	friend ofstream& operator<<(ofstream& iesire, Persoana& p);

	friend ifstream& operator>>(ifstream& intrare, Persoana& p);

	void scrieInFisierBinar(ofstream& iesire);

	void citireDinFisierBinar(ifstream& intrare);
};

