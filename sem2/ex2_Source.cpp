#include<iostream>
#include<string>

using namespace std;

enum class GEN { FEMEIE, BARBAT = 3, NECUNOSCUT = 5 };

//private, protected, public
class Student {
private:
	const int ID_Matricol;
	GEN gen;
public:
	char* nume;
	int varsta;
	string prenume;
	int nrNote;
	double* note;

	Student() :ID_Matricol(1111) {

	}

	Student(int varsta) :ID_Matricol(2000) {
		this->varsta = varsta;
	}

	Student(int id, GEN gen, const char* nume, int varsta, string prenume, int nrNote,
		double* note) :ID_Matricol(id) {
		this->gen = gen;

		this->nume = new char[strlen(nume) + 1];
		strcpy_s(this->nume, strlen(nume) + 1, nume);

		this->varsta = varsta;
		this->prenume = prenume;
		this->nrNote = nrNote;

		this->note = new double[nrNote];
		for (int i = 0; i < nrNote; i++) {
			this->note[i] = note[i];
		}
	}

	const char* getGenCaSirDeCaractere() {
		switch (gen)
		{
		case GEN::FEMEIE: {
			return "femeie";
		}
		case GEN::BARBAT: {
			return "barbat";
		}
		case GEN::NECUNOSCUT: {
			return "necunoscut";
		}
		default:
			return "nu e un gen";
			break;
		}
	}

	void afisare() {
		cout << "Studentul cu ID-ul matricol " << ID_Matricol
			<< " si cu numele " << (nume == nullptr ? "\"nullptr\"" : nume) << " prenumele " << prenume
			<< " are varsta de " << varsta << " ani"
			<< " si are genul " << getGenCaSirDeCaractere()
			<< " are notele\n";
		for (int i = 0; i < nrNote; i++) {
			cout << "Nota " << i + 1 << ": " << note[i] << "\n";
		}

		cout << endl;
	}
};


int main() {

	Student s1;
	s1.varsta = 20;
	s1.afisare();

	Student s2(21);
	s2.afisare();

	double v[] = { 5.5,7.5,8.4,10 };

	//char vv[] = { 'P','o','p','e','s','c','u' };
	Student s3(1001, GEN::BARBAT, "Popescu", 22, "Ionut", 4, v);
	s3.afisare();
	cout << s3.getGenCaSirDeCaractere();
}