//CLASE - STL
//• reprezinta o librarie de clase template standard(standard template library)
//• acopera principalele structuri de date : vector, lista, stiva, coada, tabela de dispersie(hash - table);
//• pot fi utilizate fara alte modificari pentru tipuri fundamentale sau definite de programator.

//STL=Containere + ITERATORI + ALGORITMI

//Containere: 
//• un obiect ce stocheaza alte obiecte si are metode pentru a le accesa;

//TIP CONTAINERE
//• secventiale : 
		//• vector;
		//• list;
		//• deque; 
//• asociative(valoare – cheie) :
		//• set(multime de chei unice, sortate)
		//• multiset(multime de chei, sortate)
		//• map(multime valori - chei unice, sortate)
		//• multimap(multime valori - chei sortate)
//• adaptive :
		//• stack 
		//• queue
		//• priority_queue


//ITERATORI
	//• forma generalizata a pointerilor; 
	//• utilizati pentru a itera prin elementele containerelor
	//• se comporta ca interfata intre containere si algoritmi
	//• iteratori predefiniti :
			//• ostream_iterator; 
			//• istream_iterator;
			//• reverse_iterator; 
			//• insert_iterator;

//ALGORITMI
	//• functii generice independente de tipul containerului; 
	//• utilizate pentru a prelucra elementele containerelor
	//• folosesc iteratori pentru acces la elemente
	//• functii importante : 
		//• copy;
		//• for_each;
		//• sort;
		//• find;
		//• transform

////Mai multe exemple: https://www.sanfoundry.com/cpp-programming-examples-stl/


//pt containerul vector trebuie sa adaugi #include <vector> 
//pt containerul list trebuie sa adaugi #include <list> 
//pt containerul map trebuie sa adaugi #include <map> 
//la fel si pt alte containere...


#include<iostream>
#include<fstream>

#include<vector>
#include<list>
#include<map>

#include "Persoana.h"
#include "Marinar.h"
#include "Programator.h"
#include "Companie.h"

using namespace std;

int main() {
	Persoana p1("Popescu Ionel", 44, "0763 332 221", 3000);

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

	//vector dinamic de pointeri la Persoana
	Marinar* pm1 = new Marinar("Cristi Ionescu", 44, "0768 999 111", 4000, 7000);
	Programator* pprog1 = new Programator("Ioana Barbu", 25, "0768 977 711", "C#", 8000);
	Persoana* pp1 = new Persoana("Maria Popescu", 30, "0788 771 222", 4000);

	Persoana** persoane = new Persoana * [3]{ pm1,pprog1, pp1 };
	Companie c("Rares SRL", persoane, 3);
	cout << c << endl;


	Marinar* pm2 = new Marinar("Marian Toma", 37, "0748 000 222", 2000, 5000);
	c.adaugaAngajat(pm2);
	cout << c << endl;

	for (int i = 0; i < c.nrAngajati; i++) {
		c.angajati[i]->calculeazaSalariuDupaMarireProcentuala(20);
	}

	cout << c << endl;


	//STL
	cout << "\nVECTOR STL\n";
	cout << "\nVECTOR STL afisare prin index\n";
	vector<Persoana*> vectorPersoane;
	vectorPersoane.push_back(pm1);
	vectorPersoane.push_back(pprog1);
	vectorPersoane.push_back(pp1);
	vectorPersoane.push_back(pm2);

	for (int i = 0; i < vectorPersoane.size(); i++) {
		cout << *vectorPersoane[i];
		vectorPersoane[i]->calculeazaSalariuDupaMarireProcentuala(10);
	}


	cout << "\nVECTOR STL afisare prin iterator\n";
	vector<Persoana*>::iterator iteratorVectorPersoane;
	for (iteratorVectorPersoane = vectorPersoane.begin(); iteratorVectorPersoane != vectorPersoane.end(); iteratorVectorPersoane++) {
		cout << *(*iteratorVectorPersoane);
	}

	cout << "\nLISTA STL\n";
	list<Persoana*> listaPersoane;
	listaPersoane.push_back(pm1);
	listaPersoane.push_back(pprog1);
	listaPersoane.push_back(pp1);
	listaPersoane.push_front(pm2);

	list<Persoana*>::iterator iteratorListaPersoane;
	for (iteratorListaPersoane = listaPersoane.begin(); iteratorListaPersoane != listaPersoane.end(); iteratorListaPersoane++) {
		cout << *(*iteratorListaPersoane);
	}

	cout << "\nMAP STL\n";
	map<int, Persoana*> mapPersoane;
	map<int, Persoana*>::iterator iteratorMapPersoane;

	mapPersoane.insert(pair<int, Persoana*>(100, pm1));
	mapPersoane.insert(pair<int, Persoana*>(3333, pprog1));
	mapPersoane.insert(pair<int, Persoana*>(220, pp1));
	mapPersoane.insert(pair<int, Persoana*>(10, pm2));

	for (iteratorMapPersoane = mapPersoane.begin(); iteratorMapPersoane != mapPersoane.end(); iteratorMapPersoane++) {
		cout << "La cheia " << iteratorMapPersoane->first << " se afla valoarea: " << *(iteratorMapPersoane->second);
	}

	cout << "\nLa cheia 220 se afla valoarea: " << *mapPersoane.find(220)->second << endl;
	cout << "\nLa cheia 220 se afla valoarea: " << *mapPersoane[220] << endl; //este echivalent cu ce este mai sus.

}