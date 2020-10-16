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
	static int anCurent;

	Student() :ID_Matricol(1111) {
		this->nume = new char[strlen("Anonim") + 1];
		strcpy_s(this->nume, strlen("Anonim") + 1, "Anonim");
	}

	Student(int varsta) :ID_Matricol(2000) {
		this->varsta = varsta;

		this->nume = new char[strlen("Anonim") + 1];
		strcpy_s(this->nume, strlen("Anonim") + 1, "Anonim");
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

	Student(const Student& stud) :ID_Matricol(stud.ID_Matricol) {
		this->gen = stud.gen;

		this->nume = new char[strlen(stud.nume) + 1];
		strcpy_s(this->nume, strlen(stud.nume) + 1, stud.nume);

		this->varsta = stud.varsta;
		this->prenume = stud.prenume;
		this->nrNote = stud.nrNote;

		this->note = new double[stud.nrNote];
		for (int i = 0; i < stud.nrNote; i++) {
			this->note[i] = stud.note[i];
		}
	}

	~Student() {
		cout << "destructor" << endl;

		if (nume != nullptr) {
			delete[] nume;
		}
		if (note != nullptr) {
			delete[] note;
		}
	}

	Student& operator=(const Student& stud) {
		if (this != &stud) {
			delete[] this->nume;//delete memory leaks;
			delete[] this->note;

			this->gen = stud.gen;

			this->nume = new char[strlen(stud.nume) + 1];
			strcpy_s(this->nume, strlen(stud.nume) + 1, stud.nume);

			this->varsta = stud.varsta;
			this->prenume = stud.prenume;
			this->nrNote = stud.nrNote;

			this->note = new double[stud.nrNote];
			for (int i = 0; i < stud.nrNote; i++) {
				this->note[i] = stud.note[i];
			}
		}
		return *this;
	}

	int getIDMatricol() {
		return ID_Matricol;
	}

	GEN getGen() {
		return gen;
	}

	void setGen(GEN gen) {
		this->gen = gen;
	}

	char* getNume() {
		return nume;
	}

	void setNume(char* nume) {
		if (nume != nullptr) {
			delete[] this->nume;//delete memory leaks

			this->nume = new char[strlen(nume) + 1];
			strcpy_s(this->nume, strlen(nume) + 1, nume);
		}
		else {
			throw new exception("Exception: Nume este nullptr.");
		}
	}

	string getPrenume() {
		return prenume;
	}

	void setPrenume(string prenume) {
		this->prenume = prenume;
	}

	int getVarsta() {
		return varsta;
	}

	void setVarsta(int varsta) {
		this->varsta = varsta;
	}

	int getNrNote() {
		return nrNote;
	}

	void setNrNote(int nrNote) {
		this->nrNote = nrNote;
	}

	double* getNote() {
		return note;
	}

	void setNote(double* note, int nrNote) {
		this->nrNote = nrNote;

		if (nrNote > 0) {
			delete[] this->note;//delete memory leaks

			this->note = new double[nrNote];
			for (int i = 0; i < nrNote; i++) {
				this->note[i] = note[i];
			}
		}
		else {
			throw new exception("Exception: nrNote<0");
		}
	}

	static int getAnCurent() {
		return anCurent;
	}

	void setAnCurent(int anCurent) {
		this->anCurent = anCurent;
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
			<< " si este in anul " << anCurent
			<< " are notele\n";
		for (int i = 0; i < nrNote; i++) {
			cout << "Nota " << i + 1 << ": " << note[i] << "\n";
		}

		cout << endl;
	}

	void adaugaNotaNoua(double notaNoua) {
		double* aux = new double[nrNote + 1];
		for (int i = 0; i < nrNote; i++) {
			aux[i] = note[i];
		}
		aux[nrNote++] = notaNoua;
		delete[] note;
		note = aux;
	}
};

int Student::anCurent = 0;

int main() {
	Student s1;
	s1.varsta = 20;
	s1.anCurent = 2;
	s1.afisare();
	s1.anCurent = 3;

	Student s2(21);
	s2.afisare();

	cout << "Student::getAnCurent()  " << Student::getAnCurent() << endl << endl;
	cout << "s2.getAnCurent()  " << s2.getAnCurent() << endl << endl;

	double v[] = { 5.5,7.5,8.4,10 };

	//char vv[] = { 'P','o','p','e','s','c','u' };
	Student s3(1001, GEN::BARBAT, "Popescu", 22, "Ionut", 4, v);
	s3.afisare();
	cout << s3.getGenCaSirDeCaractere();

	int* xx = NULL;
	delete xx;


	int* xxa = nullptr;
	delete xxa;

	//setter si getter
	Student s4;
	s4.setAnCurent(4);
	s4.setGen(GEN::FEMEIE);
	char vv[] = "Ionescu";
	s4.setNume(vv);
	s4.setPrenume("Mihaela");
	s4.setVarsta(23);
	double ww[] = { 6,5.5,9,10,8.4 };
	s4.setNote(ww, 5);

	cout << "\n\nStudentul cu ID-ul matricol " << s4.getIDMatricol()
		<< " si cu numele " << (s4.getNume() == nullptr ? "\"nullptr\"" : s4.getNume())
		<< " prenumele " << s4.getPrenume()
		<< " are varsta de " << s4.getVarsta() << " ani"
		<< " si are genul " << s4.getGenCaSirDeCaractere()
		<< " si este in anul " << s4.getAnCurent()
		<< " are notele\n";
	for (int i = 0; i < s4.getNrNote(); i++) {
		cout << "Nota " << i + 1 << ": " << s4.getNote()[i] << "\n";
	}

	cout << endl;

	//constr de copiere
	Student s5(s4);
	s5.afisare();
	Student s6 = s1;
	s6.afisare();

	//op egal

	Student s7;
	cout << "s7" << endl;
	s7 = s5;
	s7.afisare();
	s7.adaugaNotaNoua(10);
	s7.adaugaNotaNoua(9);
	cout << "s7" << endl;
	s7.afisare();
}