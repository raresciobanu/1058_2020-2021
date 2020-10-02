#include<iostream>

using namespace std;

typedef struct {
	int varsta;
	double greutate;
	char nume[100];
	bool gen;
}persoana;

void fct1(int a, int b) {
	a = 20;
	b = 30;
}

void fct2(int& a, int& b) {
	a = 1;
	b = 3;
}

int main() {
	cout << "-====Seminar 1====-\n\n";

	persoana p;
	strcpy_s(p.nume, "Popescu Ioana");
	p.varsta = 21;
	p.gen = false;
	p.greutate = 61.5;

	cout << "Persoana p are: nume=" << p.nume << " varsta=" << p.varsta << " greutate=" << p.greutate
		<< " gen=" << (p.gen == false ? "Femeie" : "Barbat") << endl << "\n";

	int v[] = { 2,4,1,24,5,21,2 };
	for (int i = 0; i < 7; i++) {
		cout << "v[" << i << "]=" << v[i] << " ";
	}
	cout << endl;

	int a = 0, b = 0;
	fct1(a, b);
	cout << "a=" << a << " b=" << b << endl;

	fct2(a, b);
	cout << "a=" << a << " b=" << b << endl;
}