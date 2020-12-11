#include<iostream>
#include<fstream>

#include "Persoana.h"

using namespace std;

int main() {
	Persoana p1("Popescu Ionel", 44, "0763 332 221");

	cout << "p1:   " << p1 << endl;

	//fisiere
	//flag-uri
	//ios::app - adauga informatii la un fisier existent
	//ios::nocreate - deschide fisierul daca exista deja.
	//ios::in - pt citire dintr-un fisier
	//ios::out - scriere intr-un fisier
	//ios::truc - sterge tot din fisier inainte sa scrii in el 
	//ios::noreplace - doar pt a crea un nou fisier
	//ios::ate - deschide fisierul si merge la sfarsitul lui - fol pt adaugare info la final
	//ios::binary - fisierul deschis va contine doar informatii binare

	ofstream fisTextOut("aaa.txt", ios::app);
	if (fisTextOut.is_open()) {
		fisTextOut << p1;
		fisTextOut.close();
	}
	else {
		cout << "Fisierul aaa.txt nu a putut fi deschis pentru scrire.\n";
	}

	Persoana p2;
	ifstream fisTextIn("aaa.txt");
	if (fisTextIn.is_open()) {
		fisTextIn >> p2;
		cout << "p2 din fisier:   " << p2 << endl;

		fisTextIn.close();
	}
	else {
		cout << "Fisierul aaa.txt nu a putut fi deschis pentru citire.\n";
	}


	ofstream fisBinarOut("www.dat", ios::out | ios::binary);
	if (fisBinarOut.is_open()) {
		p2.scrieInFisierBinar(fisBinarOut);
		fisBinarOut.close();
	}
	else {
		cout << "Fisierul www.dat nu a putut fi deschis pentru scrire.\n";
	}

	Persoana p3;
	ifstream fisBinarIn("www.dat", ios::in | ios::binary);
	if (fisBinarIn.is_open()) {
		p3.citireDinFisierBinar(fisBinarIn);
		cout << "p3 din fisier binar:   " << p3 << endl;

		fisBinarIn.close();
	}
	else {
		cout << "Fisierul www.dat nu a putut fi deschis pentru citire.\n";
	}
}