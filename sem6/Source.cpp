#include<iostream>

using namespace std;

class Vehicul {
	string culoare;
protected:
	int anFabricatie;
	char* serie;
public:
	int capacitateCilindrica;

	Vehicul() {
		cout << "Constructor () Vehicul\n";

	}
	
	Vehicul(string culoare, int anFabricatie, const char* serie, int capacitateCilindrica)
	{
		cout << "Constructor Vehicul 4 param \n";

		this->culoare = culoare;

		this->serie = new char[strlen(serie) + 1];
		strcpy_s(this->serie, strlen(serie) + 1, serie);

		this->anFabricatie = anFabricatie;

		this->capacitateCilindrica = capacitateCilindrica;
	}

	//constructor de copiere
	Vehicul(const Vehicul& v) {
		cout << "Constructor copiere Vehicul\n";
		this->culoare = v.culoare;

		this->serie = new char[strlen(v.serie) + 1];
		strcpy_s(this->serie, strlen(v.serie) + 1, v.serie);

		this->anFabricatie = v.anFabricatie;

		this->capacitateCilindrica = v.capacitateCilindrica;
	}


	~Vehicul() {
		cout << "Destructor Vehicul\n";
		if (this->serie != nullptr) {
			delete[] this->serie;
		}
	}


	//cout<<"avaewrvre"; //adica: ostream << const char*
	//cout<<vehicul3; //adica: ostream << Vehicul

	friend ostream& operator<<(ostream& out, Vehicul v) {
		out << "Operator << Vehicul \n";

		out << "Culoare " << v.culoare << " An fabricatie " << v.anFabricatie
			<< " Serie " << v.serie << " Capacitate cilindrica " << v.capacitateCilindrica << endl;

		return out;
	}

	void functieParinte() {

	}
};

class Motocicleta : public Vehicul {
public:
	bool areSa;

	//	Vehicul(string culoare, int anFabricatie, const char* serie, int capacitateCilindrica)
	//Motocicleta = Vehicul + (alti param si functii);

	Motocicleta() : Vehicul("verde", 2012, "cMCjhwm22", 2) {
		cout << "Constructor Motocicleta() \n";
		this->areSa = false;
	}

	Motocicleta(string culoare, int anFabricatie, const char* serie, int capacitateCilindrica, bool areSa)
		: Vehicul(culoare, anFabricatie, serie, capacitateCilindrica){
		cout << "Constructor Motocicleta 5 param \n";
		this->areSa = areSa;
	}

	Motocicleta(const Motocicleta& m) :Vehicul(m){
		cout << "Constructor copiere Motocicleta\n";

		this->areSa = m.areSa;
	}

	void fct1() {
		this->anFabricatie;
		this->serie;
	}

	friend ostream& operator<<(ostream& out, Motocicleta m) {
		out << "Operator << Vehicul \n";

		out << "Motocicleta: \n";

		//up-casting => poti transforma un copil in parinte;
		out << (Vehicul)m;
		out << "Are sa: " << m.areSa << endl;

		return out;
	}

	~Motocicleta() {
		cout << "Destructor Motocicleta\n";
	}
};

class Masina : protected Vehicul {
public:
	bool arePortbagaj;


	void fct2() {
		this->anFabricatie;
		this->serie;
	}
};

//clasa copil a lui Masina si este si clasa nepot a lui Vehicul
class MasinaExtinsa: Masina{
	void fct4() {
		this->anFabricatie;
		this->serie;
	}
};

class TIR : private Vehicul {
public:
	bool areRemorca;

	void fct3() {
		this->anFabricatie;
		this->serie;
	}
};

int main() {
	Vehicul v1("rosu", 2020, "c38verun", 4);
	cout << v1 << endl << endl;

	Motocicleta motocicleta1;
	cout << "\n";
	motocicleta1.capacitateCilindrica;
	motocicleta1.functieParinte();
	cout << motocicleta1 << endl << endl;

	Motocicleta motocicleta2("albastru", 2005, "cavr@cj24444", 3, true);
	cout << motocicleta2 << endl << endl;

	Masina masina;
	// masina.capacitateCilindrica; //eroare pt ca mostenirea este protected si practic
	//nu mai ai acces din main() la orice este public din parinte;
	
	TIR tir;
	// tir.capacitateCilindrica; //eroare pt ca mostenirea este protected si practic
	//nu mai ai acces din main() la orice este public din parinte;
}