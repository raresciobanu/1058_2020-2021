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
		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);

		this->culoare = culoare;

		this->varsta = varsta;
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
	}

	void setKgInUltimiiAni(double* kgInUltimiiAni, int nrAniInregistrati) {
		this->nrAniInregistrati = nrAniInregistrati;
		if (nrAniInregistrati > 0) {
			this->kgInUltimiiAni = new double[nrAniInregistrati];

			for (int i = 0; i < nrAniInregistrati; i++) {
				this->kgInUltimiiAni[i] = kgInUltimiiAni[i];
			}
		}
		else {
			throw new exception("Exception: nrAniInregistrati <=0");
		}
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
			<< " NrAniInregistrati: " << a.nrAniInregistrati << " ";

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
		a.nume = new char[strlen(aux) + 1];
		strcpy_s(a.nume, strlen(aux) + 1, aux);

		cout << "Culoare: "; in >> a.culoare;
		cout << "Varsta: "; in >> a.varsta;

		return in;
	}

	//op !
	bool operator!() {
		return !sex;
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
	cout << a3;

}