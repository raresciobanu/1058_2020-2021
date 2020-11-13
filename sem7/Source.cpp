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

		this->serie = new char[strlen("n/a") + 1];
		strcpy_s(this->serie, strlen("n/a") + 1, "n/a");
	}

	Vehicul(int anFabricatie, int capacitateCilindrica) {
		cout << "Constructor (int anFabricatie, int capacitateCilindrica) Vehicul\n";

		this->anFabricatie = anFabricatie;

		this->capacitateCilindrica = capacitateCilindrica;

		this->serie = new char[strlen("n/a") + 1];
		strcpy_s(this->serie, strlen("n/a") + 1, "n/a");
	}

	Vehicul(string culoare, int anFabricatie, const char* serie, int capacitateCilindrica)
	{
		cout << "Constructor Vehicul(string culoare, int anFabricatie, const char* serie, int capacitateCilindrica)\n";

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

	Vehicul& operator=(const Vehicul& v) {
		cout << "Operator= Vehicul\n";

		if (this != &v) {
			if (this->serie != nullptr) {
				delete[] this->serie;
			}

			this->culoare = v.culoare;

			this->serie = new char[strlen(v.serie) + 1];
			strcpy_s(this->serie, strlen(v.serie) + 1, v.serie);

			this->anFabricatie = v.anFabricatie;

			this->capacitateCilindrica = v.capacitateCilindrica;
		}

		return *this;
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
	const int ID;
	static int random;

	//	Vehicul(string culoare, int anFabricatie, const char* serie, int capacitateCilindrica)
	//Motocicleta = Vehicul + (alti param si functii);

	Motocicleta() : Vehicul(2012, 2), ID(10) {
		cout << "Constructor Motocicleta() \n";

		this->areSa = false;
	}

	Motocicleta(string culoare, int anFabricatie, const char* serie, int capacitateCilindrica, bool areSa)
		: Vehicul(culoare, anFabricatie, serie, capacitateCilindrica), ID(random++) {
		cout << "Constructor Motocicleta 5 param \n";

		this->areSa = areSa;
	}

	Motocicleta(const Motocicleta& m) :Vehicul(m), ID(m.ID) {
		cout << "Constructor copiere Motocicleta\n";

		this->areSa = m.areSa;
	}

	~Motocicleta() {
		cout << "Destructor Motocicleta\n";
	}

	Motocicleta& operator=(const Motocicleta& m) {
		cout << "Operator= Motocicleta\n";

		if (this != &m) {
			Vehicul::operator=(m);

			this->areSa = m.areSa;
		}

		return *this;
	}

	void fct1() {
		this->anFabricatie;
		this->serie;
	}

	friend ostream& operator<<(ostream& out, Motocicleta m) {
		out << "Operator << Motocicleta \n";

		out << "Motocicleta: \n";

		//up-casting => poti transforma un copil in parinte;
		out << (Vehicul)m;
		out << "Are sa: " << m.areSa << endl;

		return out;
	}
};

int Motocicleta::random = 1000;

class Masina : protected Vehicul {
public:
	bool arePortbagaj;


	void fct2() {
		this->anFabricatie;
		this->serie;
	}
};

//clasa copil a lui Masina si este si clasa nepot a lui Vehicul
class MasinaExtinsa : Masina {
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

	//Masina masina;
	// masina.capacitateCilindrica; //eroare pt ca mostenirea este protected si practic
	//nu mai ai acces din main() la orice este public din parinte;

	//TIR tir;
	// tir.capacitateCilindrica; //eroare pt ca mostenirea este protected si practic
	//nu mai ai acces din main() la orice este public din parinte;
}