#include<iostream>

using namespace std;

class Animal {
	char* nume;
	string culoare;
	int varsta;
	bool sex;
	double* kgInUltimiiAni;
	int nrAniInregistrati;
public:

	Animal();

	Animal(const char* nume, string culoare, int varsta) {
		if (nume != nullptr) {
			this->nume = new char[strlen(nume) + 1];
			strcpy_s(this->nume, strlen(nume) + 1, nume);
		}
		else {
			throw new exception("Error: nume este nullptr.");
		}

		if (!culoare.empty()) {
			this->culoare = culoare;
		}
		else {
			throw new exception("Error: culoare este empty.");
		}

		if (varsta > 0) {
			this->varsta = varsta;
		}
		else {
			throw new exception("Error: varsta trebue sa fie > 0.");
		}

		this->sex = false;
		this->nrAniInregistrati = 0;
		this->kgInUltimiiAni = nullptr;
	}

	Animal(const Animal& animal) {
		this->nume = new char[strlen(animal.nume) + 1];
		strcpy_s(this->nume, strlen(animal.nume) + 1, animal.nume);

		this->culoare = animal.culoare;

		this->varsta = animal.varsta;

		this->nrAniInregistrati = animal.nrAniInregistrati;
		this->kgInUltimiiAni = new double[animal.nrAniInregistrati];
		for (int i = 0; i < nrAniInregistrati; i++) {
			this->kgInUltimiiAni[i] = animal.kgInUltimiiAni[i];
		}
	}

	~Animal() {
		if (nume != nullptr) {
			delete[] nume;
		}

		if (kgInUltimiiAni != nullptr) {
			delete[] kgInUltimiiAni;
		}
	}

	void setKgInUltimiiAni(double* kgInUltimiiAni, int nrAniInregistrati) {
		this->nrAniInregistrati = nrAniInregistrati;
		if (nrAniInregistrati >= 0) {
			delete[] this->kgInUltimiiAni;

			this->kgInUltimiiAni = new double[nrAniInregistrati];

			for (int i = 0; i < nrAniInregistrati; i++) {
				this->kgInUltimiiAni[i] = kgInUltimiiAni[i];
			}
		}
		else {
			throw new exception("Exception: nrAniInregistrati < 0");
		}
	}

	void adaugareElement(double elem) {
		double* aux = new double[nrAniInregistrati + 1];
		for (int i = 0; i < nrAniInregistrati; i++) {
			aux[i] = this->kgInUltimiiAni[i];
		}

		aux[nrAniInregistrati++] = elem;
		delete[] this->kgInUltimiiAni;
		this->kgInUltimiiAni = aux;
	}

	void stergereElement(double elem) {
		int index = -1;
		double* aux = new double[nrAniInregistrati - 1];

		for (int i = 0; i < nrAniInregistrati; i++) {
			if (elem == kgInUltimiiAni[i])
			{
				index = i;
				break;
			}
			aux[i] = this->kgInUltimiiAni[i];
		}

		if (index != -1) {
			for (int i = index; i < nrAniInregistrati - 1; i++) {
				aux[i] = this->kgInUltimiiAni[i + 1];
			}

			delete[] this->kgInUltimiiAni;
			nrAniInregistrati--;
			this->kgInUltimiiAni = aux;
		}
	}

	friend void afisare(Animal a);


	//Operatori
	//op. unari
	//op ++ pre-incrementare
	const Animal operator++() {
		this->varsta++;

		return *this;
	}

	//op ++ post-incrementare
	const Animal operator++(int) {
		Animal aux(*this);
		this->varsta++;

		return aux;
	}

	//op. binari
	//op. egal
	Animal& operator=(const Animal& animal) {
		if (this != &animal) {
			delete[] this->nume;
			delete[] this->kgInUltimiiAni;

			this->nume = new char[strlen(animal.nume) + 1];
			strcpy_s(this->nume, strlen(animal.nume) + 1, animal.nume);

			this->culoare = animal.culoare;

			this->varsta = animal.varsta;

			this->nrAniInregistrati = animal.nrAniInregistrati;
			this->kgInUltimiiAni = new double[animal.nrAniInregistrati];
			for (int i = 0; i < nrAniInregistrati; i++) {
				this->kgInUltimiiAni[i] = animal.kgInUltimiiAni[i];
			}
		}

		return *this;
	}

	//op +  (animal+int) ex: //c = a + b;
	int operator+(int x) {
		return this->varsta + x;
	}

	//op +  (animal+animal) ex: //c = a + b;
	Animal& operator+(Animal animal) {
		Animal* p = new Animal(*this);

		p->culoare = p->culoare + " si " + animal.culoare;

		return *p;
	}

	//op +  (int+animal) ex: //c = b + a;
	friend int operator+(int x, Animal a);

	//op +=  //ex: c+=5;
	void operator+=(int x) {
		varsta += x;
	}

	//op<<
	friend ostream& operator<<(ostream& out, Animal a) {
		out << "--> Nume: " << a.nume << " Culoare: " << a.culoare << " Varsta: " << a.varsta
			<< " NrAniInregistrati: " << a.nrAniInregistrati << "  ;;;";

		for (int i = 0; i < a.nrAniInregistrati; i++) {
			out << a.kgInUltimiiAni[i] << " ";
		}
		out << endl;

		return out;
	}

	//op >>
	friend istream& operator>>(istream& in, Animal& a) {
		char aux[100];
		cout << "Nume: "; in >> aux;

		delete[] a.nume;
		delete[] a.kgInUltimiiAni;

		a.nume = new char[strlen(aux) + 1];
		strcpy_s(a.nume, strlen(aux) + 1, aux);

		cout << "Nr ani inreg: "; in >> a.nrAniInregistrati;
		a.kgInUltimiiAni = new double[a.nrAniInregistrati];
		for (int i = 0; i < a.nrAniInregistrati; i++) {
			in >> a.kgInUltimiiAni[i];
		}

		cout << "Culoare: "; in >> a.culoare;
		cout << "Varsta: "; in >> a.varsta;

		return in;
	}

	//op !
	bool operator!() {
		return !sex;
	}

	//op []
	double& operator[](int index) {
		if (index >= 0 && index < nrAniInregistrati) {
			return kgInUltimiiAni[index];
		}
		else {
			throw new exception("Error: index >= 0 && index < nrAniInregistrati");
		}
	}

	//op ()
	void operator()(int valoare) {
		if (valoare >= 5 && valoare <= 15) {
			for (int i = 0; i < nrAniInregistrati; i++) {
				kgInUltimiiAni[i] += valoare;
			}
		}
		else {
			throw new exception("Error: Op (): valoare >= 5 && valoare <= 15");
		}
	}

	//op cast - explicit/implicit
	operator int() {
		return varsta;
	}

	//op ==
	bool operator==(Animal& animal) {
		if (this == &animal) {
			return true;
		}

		bool normalFieldsValidation = strcmp(this->nume, animal.nume) == 0 &&
			this->culoare == animal.culoare &&
			this->varsta == animal.varsta &&
			this->sex == animal.sex &&
			this->nrAniInregistrati == animal.nrAniInregistrati;

		if (normalFieldsValidation) {
			for (int i = 0; i < nrAniInregistrati; i++) {
				if (this->kgInUltimiiAni[i] != animal.kgInUltimiiAni[i]) {
					return false;
				}
			}

			return true;
		}

		return false;
	}
};


//op +  (int+animal) ex: //c = b + a;
int operator+(int x, Animal a) {
	return x + a.varsta;
}

Animal::Animal() {
	char aux[] = "Anonim";
	this->nume = new char[strlen(aux) + 1];
	strcpy_s(this->nume, strlen(aux) + 1, aux);

}

void afisare() {
	cout << "afisare()" << endl;
}

void afisare(const char* a) {
	cout << "afisare(const char *a) " << a << endl;
}

void afisare(int a) {
	cout << "afisare(int a) " << a << endl;
}

void afisare(int a, double b) {
	cout << "afisare(int a, double b) " << a << " " << b << endl;
}

void afisare(double a, double b) {
	cout << "afisare(double a, double b) " << a << " " << b << endl;
}

void afisare(Animal a) {
	cout << "afisare(Animal a) --> Nume: " << a.nume << " Culoare: " << a.culoare
		<< " Varsta: " << a.varsta << endl;
}

int main() {
	Animal a8;
	afisare();
	afisare("ssollp");
	afisare(5);
	afisare(5, 32.15);
	afisare(12.42, 22.3);

	Animal a1("John", "verde", 10);
	afisare(a1);

	cout << "Operatori\n\n";
	afisare(++a1);
	afisare(a1++);
	afisare(a1);


	cout << a1 + 2 << endl;

	Animal a2("Blacky", "negru", 9);
	Animal a3;

	a3 = a1 + a2;
	afisare(a3);

	a3 += 2;
	cout << a3;

	Animal a4;
	//cin >> a4;
	cout << a4;

	cout << ((!a4 == 1) ? "male" : "female") << endl;

	double v[] = { 22.4, 30.4, 31.3, 35 };
	a3.setKgInUltimiiAni(v, 4);
	cout << a3;
	a3.stergereElement(31.3);
	a3.adaugareElement(40);
	a3.adaugareElement(70);
	a3.adaugareElement(90);
	cout << a3;


	//op ==
	Animal a7(a3);
	if (a7 == a3) {
		cout << "a7 == a3" << endl;
	}
	else {
		cout << "a7 != a3" << endl;
	}

	if (a8 == a3) {
		cout << "a8 == a3" << endl;
	}
	else {
		cout << "a8 != a3" << endl;
	}

	//op []
	cout << "a3[4] = " << a3[4] << endl;

	//op cast explicit
	cout << "(int)a3 = " << (int)a3 << endl;

	//op cast implicit
	int varsta = a3;
	cout << "(int) implicit = " << varsta << endl;

	//op ()
	a3(10);
	cout << a3 << endl;
}