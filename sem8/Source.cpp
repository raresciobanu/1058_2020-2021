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
		this->serie = new char[strlen("n/a") + 1];
		strcpy_s(this->serie, strlen("n/a") + 1, "n/a");
	}

	Vehicul(int anFabricatie, int capacitateCilindrica) {
		this->anFabricatie = anFabricatie;

		this->capacitateCilindrica = capacitateCilindrica;

		this->serie = new char[strlen("n/a") + 1];
		strcpy_s(this->serie, strlen("n/a") + 1, "n/a");
	}

	Vehicul(string culoare, int anFabricatie, const char* serie, int capacitateCilindrica)
	{
		this->culoare = culoare;

		this->serie = new char[strlen(serie) + 1];
		strcpy_s(this->serie, strlen(serie) + 1, serie);

		this->anFabricatie = anFabricatie;

		this->capacitateCilindrica = capacitateCilindrica;
	}

	//constructor de copiere
	Vehicul(const Vehicul& v) {
		this->culoare = v.culoare;

		this->serie = new char[strlen(v.serie) + 1];
		strcpy_s(this->serie, strlen(v.serie) + 1, v.serie);

		this->anFabricatie = v.anFabricatie;

		this->capacitateCilindrica = v.capacitateCilindrica;
	}

	Vehicul& operator=(const Vehicul& v) {
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

	bool operator==(Vehicul vehicul) {
		if (this == &vehicul) {
			return true;
		}

		return this->culoare == vehicul.culoare &&
			this->anFabricatie == vehicul.anFabricatie &&
			this->capacitateCilindrica == vehicul.capacitateCilindrica &&
			strcmp(this->serie, vehicul.serie) == 0;
	}

	~Vehicul() {
		if (this->serie != nullptr) {
			delete[] this->serie;
		}
	}


	//cout<<"avaewrvre"; //adica: ostream << const char*
	//cout<<vehicul3; //adica: ostream << Vehicul

	friend ostream& operator<<(ostream& out, Vehicul v) {
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
		this->areSa = false;
	}

	Motocicleta(string culoare, int anFabricatie, const char* serie, int capacitateCilindrica, bool areSa)
		: Vehicul(culoare, anFabricatie, serie, capacitateCilindrica), ID(random++) {

		this->areSa = areSa;
	}

	Motocicleta(const Motocicleta& m) :Vehicul(m), ID(m.ID) {
		this->areSa = m.areSa;
	}

	~Motocicleta() {
	}

	Motocicleta& operator=(const Motocicleta& m) {
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

	bool operator==(Motocicleta motocicleta) {
		return this->areSa == motocicleta.areSa && Vehicul::operator==(motocicleta);
	}

	friend ostream& operator<<(ostream& out, Motocicleta m) {
		out << "Motocicleta: \n";

		//up-casting => poti transforma un copil in parinte;
		out << (Vehicul)m;
		out << "Are sa: " << m.areSa << endl;
		out << "ID: " << m.ID << endl;

		return out;
	}
};
int Motocicleta::random = 1000;

class ReprezentantaDeMotociclete {
	string denumire;
	Motocicleta* motociclete;
	int nrMotociclete;

public:
	ReprezentantaDeMotociclete(string denumire, Motocicleta* motociclete, int nrMotociclete) {
		this->denumire = denumire;

		this->nrMotociclete = nrMotociclete;

		this->motociclete = new Motocicleta[nrMotociclete];
		for (int i = 0; i < nrMotociclete; i++) {
			this->motociclete[i] = motociclete[i];
		}
	}

	ReprezentantaDeMotociclete(const ReprezentantaDeMotociclete& reprezentanta) {
		this->denumire = reprezentanta.denumire;

		this->nrMotociclete = reprezentanta.nrMotociclete;

		this->motociclete = new Motocicleta[reprezentanta.nrMotociclete];
		for (int i = 0; i < reprezentanta.nrMotociclete; i++) {
			this->motociclete[i] = reprezentanta.motociclete[i];
		}
	}

	ReprezentantaDeMotociclete& operator=(const ReprezentantaDeMotociclete& reprezentanta) {
		if (this != &reprezentanta) {
			if (this->motociclete != nullptr) {
				delete[] this->motociclete;
			}

			this->denumire = reprezentanta.denumire;

			this->nrMotociclete = reprezentanta.nrMotociclete;

			this->motociclete = new Motocicleta[reprezentanta.nrMotociclete];
			for (int i = 0; i < reprezentanta.nrMotociclete; i++) {
				this->motociclete[i] = reprezentanta.motociclete[i];
			}

		}

		return *this;
	}

	int getNrMotociclete() {
		return this->nrMotociclete;
	}

	Motocicleta& operator[](int index) {
		if (index >= 0 && index < nrMotociclete) {
			return this->motociclete[index];
		}
		else {
			throw new exception("EROARE: Motocicleta& operator[](int index)");
		}
	}

	void adaugareMotocicleta(Motocicleta elem) {
		Motocicleta* aux = new Motocicleta[nrMotociclete + 1];
		for (int i = 0; i < nrMotociclete; i++) {
			aux[i] = this->motociclete[i];
		}

		aux[nrMotociclete++] = elem;
		delete[] this->motociclete;
		this->motociclete = aux;
	}

	//stergere element si toate aparitiile sale
	void stergereMotocicleta(Motocicleta motocicleta) {
		int nrAparitii = 0; 
		for (int i = 0; i < nrMotociclete; i++) {
			if (motocicleta == motociclete[i])
			{
				nrAparitii++;
			}
		}

		if (nrAparitii > 0) {
			for (int i = 0; i < nrMotociclete; i++) {
				if (motocicleta == motociclete[i])
				{
					for (int j = i; j < nrMotociclete - 1; j++) {
						this->motociclete[j] = this->motociclete[j + 1];
					}
					nrMotociclete--;
				}
			}

			Motocicleta* aux = new Motocicleta[nrMotociclete];
			for (int i = 0; i < nrMotociclete; i++) {
				aux[i] = motociclete[i];
			}

			delete[] this->motociclete;
			this->motociclete = aux;
		}
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

void afisareReprezentantaMoto(ReprezentantaDeMotociclete reprezentanta) {
	for (int i = 0; i < reprezentanta.getNrMotociclete(); i++) {
		cout<<reprezentanta[i]<<endl;
	}
}

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

	//compunere
	cout << "\ncompunere\n";
	Motocicleta motociclete[] = { motocicleta1, motocicleta2 };
	ReprezentantaDeMotociclete reprezentanta1("Moto Sport Rares SRL", motociclete, 2);
	afisareReprezentantaMoto(reprezentanta1);


	cout << "\nadaugare\n";
	Motocicleta motocicleta3("verde", 2005, "aaaa4444", 4, true);
	reprezentanta1.adaugareMotocicleta(motocicleta3);
	reprezentanta1.adaugareMotocicleta(motocicleta3);
	reprezentanta1.adaugareMotocicleta(motocicleta2);

	afisareReprezentantaMoto(reprezentanta1);

	cout << "\nstergere\n";
	reprezentanta1.stergereMotocicleta(motocicleta2);
	afisareReprezentantaMoto(reprezentanta1);
}