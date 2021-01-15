//s6 - fisiere

#include<iostream>
#include<fstream>
#include<vector>

using namespace std;


class Fisier {
private:
	string denumire;
	static int RANDOM_INT;
	int ziuaCrearii;
	int dimensiune;
	char* bytes = nullptr;

public:
	Fisier() {
		this->denumire = "Fisierul" + RANDOM_INT;
		RANDOM_INT++;
		this->ziuaCrearii = 1;
		this->dimensiune = 0;
		this->bytes = nullptr;
	}

	Fisier(string denumire, int ziuaCrearii, int dimensiune, char* bytes) {
		if (denumire.empty()) {
			throw new exception("denumire nu poate fi gol");
		}
		else {
			this->denumire = denumire;
		}
		if (ziuaCrearii < 1 || ziuaCrearii>31) {
			throw new exception("ziua crearii este <1 || >31");
		}
		else {
			this->ziuaCrearii = ziuaCrearii;
		}

		if (dimensiune < 0) {
			throw new exception("dimensiunea nu poate fi mai mica ca 0");
		}
		else {
			this->dimensiune = dimensiune;
		}

		this->bytes = new char[dimensiune];
		for (int i = 0; i < dimensiune; i++) {
			this->bytes[i] = bytes[i];
		}

		RANDOM_INT++;
	}

	Fisier(const Fisier& f) {
		this->denumire = f.denumire + "_copy";
		this->ziuaCrearii = f.ziuaCrearii;
		this->dimensiune = f.dimensiune;

		this->bytes = new char[f.dimensiune];
		for (int i = 0; i < f.dimensiune; i++) {
			this->bytes[i] = f.bytes[i];
		}
	}

	Fisier& operator=(const Fisier& f) {
		if (this != &f) {
			delete[] this->bytes;

			this->denumire = f.denumire + "_copy";
			this->ziuaCrearii = f.ziuaCrearii;
			this->dimensiune = f.dimensiune;

			this->bytes = new char[f.dimensiune];
			for (int i = 0; i < f.dimensiune; i++) {
				this->bytes[i] = f.bytes[i];
			}
		}

		return *this;
	}

	~Fisier() {
		if (this->bytes != nullptr) {
			delete[] this->bytes;
		}
	}

	friend ostream& operator<<(ostream& out, const Fisier& f) {
		out << "Fisierul " << f.denumire << " creat pe " << f.ziuaCrearii << " are dimensiunea " << f.dimensiune << " si bytes: ";
		for (int i = 0; i < f.dimensiune; i++) {
			out << f.bytes[i] << " ";
		}

		out << endl;
		return out;
	}

	void arhiveaza() {
		int elemDuplicate = 0;

		for (int i = 0; i < dimensiune - 1; i++) {
			if (bytes[i] == bytes[i + 1]) {
				elemDuplicate++;
				for (int j = i; j < dimensiune - 1; j++) {
					bytes[j] = bytes[j + 1];
				}
				dimensiune--;
			}
		}

		char* aux = new char[dimensiune];
		for (int i = 0; i < dimensiune; i++) {
			aux[i] = bytes[i];
		}

		delete[] bytes;
		bytes = aux;
	}

	explicit operator long() {
		return this->dimensiune;
	}

	void operator[](int index) {
		if (index >= 0 && index < dimensiune) {
			bytes[index] = '0';
		}
		else {
			throw new exception("eroare in op[]");
		}
	}

	void operator+=(Fisier& f1) {
		char* aux = new char[this->dimensiune + f1.dimensiune];

		for (int i = 0; i < this->dimensiune; i++) {
			aux[i] = this->bytes[i];
		}

		delete[] this->bytes;

		int k = 0;
		for (int i = this->dimensiune; i < this->dimensiune + f1.dimensiune; i++) {
			aux[i] = f1.bytes[k++];
		}

		this->bytes = aux;

		this->dimensiune = this->dimensiune + f1.dimensiune;
	}

	string getDenumire() {
		return denumire;
	}

	int getDimensiune() {
		return this->dimensiune;
	}

	char* getBytes() {
		return this->bytes;
	}

	void setDenumire(string denumire) {
		if (denumire.empty()) {
			throw new exception("denumire nu poate fi gol");
		}
		else {
			this->denumire = denumire;
		}
	}
};
int Fisier::RANDOM_INT = 0;


class Director {
	char denumire[20];
	int nrFisiere;
	Fisier* fisiere;

public:
	Director(const char denumire[], int nrFisiere, Fisier* fisiere) {
		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);

		this->nrFisiere = nrFisiere;
		this->fisiere = new Fisier[nrFisiere];
		for (int i = 0; i < nrFisiere; i++) {
			this->fisiere[i] = fisiere[i];
		}
	}

	Director(const Director& d) {
		strcpy_s(this->denumire, strlen(d.denumire) + 1, d.denumire);

		this->nrFisiere = d.nrFisiere;
		this->fisiere = new Fisier[d.nrFisiere];
		for (int i = 0; i < d.nrFisiere; i++) {
			this->fisiere[i] = d.fisiere[i];
		}
	}

	Director& operator=(const Director& d) {
		if (this != &d) {
			strcpy_s(this->denumire, strlen(d.denumire) + 1, d.denumire);

			this->nrFisiere = d.nrFisiere;
			this->fisiere = new Fisier[d.nrFisiere];
			for (int i = 0; i < d.nrFisiere; i++) {
				this->fisiere[i] = d.fisiere[i];
			}
		}
		return *this;
	}

	~Director() {
		if (fisiere != nullptr) {
			delete[] fisiere;
		}
	}

	void Paste() {
		for (int i = 0; i < nrFisiere; i++) {
			ofstream outFis(fisiere[i].getDenumire() + ".txt");
			if (outFis.is_open()) {
				for (int j = 0; j < fisiere[i].getDimensiune(); j++) {
					outFis << fisiere[i].getBytes()[j] << " ";
				}
				outFis.close();
			}
			else {
				string cc = "Fisierul " + fisiere[i].getDenumire() + ".txt" + " nu a putut fi deschis!";
				throw new exception(cc.c_str());
			}
		}
	}
};

class Director_v2 {
	char denumire[20];
	int nrFisiere;
	vector<Fisier> fisiere;

public:
	Director_v2(const char denumire[], int nrFisiere, vector<Fisier> fisiere) {
		strcpy_s(this->denumire, strlen(denumire) + 1, denumire);

		this->nrFisiere = nrFisiere;
		this->fisiere = fisiere;
	}

	Director_v2(const Director_v2& d) {
		strcpy_s(this->denumire, strlen(d.denumire) + 1, d.denumire);

		this->nrFisiere = d.nrFisiere;
		this->fisiere = d.fisiere;
	}

	Director_v2& operator=(const Director_v2& d) {
		if (this != &d) {
			strcpy_s(this->denumire, strlen(d.denumire) + 1, d.denumire);

			this->nrFisiere = d.nrFisiere;
			this->fisiere = d.fisiere;
		}
		return *this;
	}

	~Director_v2() {}

	void Paste() {
		for (int i = 0; i < nrFisiere; i++) {
			ofstream outFis(fisiere[i].getDenumire() + ".txt");
			if (outFis.is_open()) {
				for (int j = 0; j < fisiere[i].getDimensiune(); j++) {
					outFis << fisiere[i].getBytes()[j] << " ";
				}
				outFis.close();
			}
			else {
				string cc = "Fisierul " + fisiere[i].getDenumire() + ".txt" + " nu a putut fi deschis!";
				throw new exception(cc.c_str());
			}
		}
	}
};
void main() {
	char v[]{ '1', '2', '2', '3', '3', '4', '5', '6', '6' };
	Fisier f1("fisier1", 22, 9, v);
	cout << f1 << endl;
	f1.arhiveaza();
	cout << f1 << endl;

	long aaa = (long)f1;//testare op cast explicit

	try {
		f1[-2];
	}
	catch (exception* e) {
		cout << "S-a prin exceptia: " << e->what() << endl;
	}

	char v2[]{ '1', '2', '2' };
	Fisier f2("fisier2", 11, 3, v2);
	f1 += f2;
	cout << f1 << endl;

	Fisier* fp = new Fisier[2]{ f1,f2 };
	Director d("Director 1", 2, fp);
	d.Paste();

	f1.setDenumire("d2---Fisier1");
	f2.setDenumire("d2---Fisier2");
	vector<Fisier> vvvv;
	vvvv.push_back(f1);
	vvvv.push_back(f2);

	Director_v2 d_v2("Director v2", 2, vvvv);
	d_v2.Paste();
}