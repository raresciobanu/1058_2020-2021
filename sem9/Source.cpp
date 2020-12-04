#include<iostream>

using namespace std;

class ExceptieCustom : exception {
public:
	const char* what() {
		return "ERROR: varsta animalului trebuie sa fie >0 si <40\n";
	}
};

class Animal {
public:
	string culoare;
	string nume;
	int varsta;

	Animal(string culoare, string nume, int varsta) {
		this->culoare = culoare;
		this->nume = nume;
		this->varsta = varsta;
	}

	virtual int determinaVarstaInAniOmenesti() = 0;

	virtual void scoateSunet() {
		cout << "Animalul a scos un sunet.\n";
	}

	void setCuloare(string culoare) {
		if (culoare.size() < 3) {
			throw new exception("ERROR: Culoarea animalului trebuie sa aiba minim 3 caractere\n");
		}
		else {
			this->culoare = culoare;
		}
	}

	void setVarsta(int varsta) {
		if (varsta < 0 || varsta > 40) {
			throw new ExceptieCustom();
		}
		else {
			this->varsta = varsta;
		}
	}
};

class InterfataPisica {
	virtual void scriePisica() = 0;
};

class Pisica : public Animal, InterfataPisica {
	int nrVieti;
public:
	Pisica(string culoare, string nume, int varsta, int nrVieti) : Animal(culoare, nume, varsta) {
		this->nrVieti = nrVieti;
	}

	void scoateSunet() {
		cout << "Pisica face miau miau.\n";
	}

	int determinaVarstaInAniOmenesti() {
		return this->varsta * 2;
	}

	void scriePisica() {
		cout << "Pisica " << nume << " are culoarea " << culoare << ", varsta de " << varsta
			<< " ani si are " << nrVieti << " vieti.\n";
	}
};

class Caine : public Animal {
	bool faceParteDinHaita;
public:
	Caine(string culoare, string nume, int varsta, bool faceParteDinHaita) : Animal(culoare, nume, varsta) {
		this->faceParteDinHaita = faceParteDinHaita;
	}

	void scoateSunet() {
		cout << "Cainele face ham ham.\n";
	}

	int determinaVarstaInAniOmenesti() {
		return this->varsta * 3;
	}
};

//polimorfism = supraincarcare + suprascriere
int main() {
	Animal* ap1 = new Pisica("gri", "Nume_Animal1", 3, 9);
	Animal* ap2 = new Caine("alb", "Nume_Animal2", 5, false);

	Pisica p1("maro", "Nume_Pisica1", 2, 9);
	Pisica p2("alb-negru", "Nume_Pisica2", 5, 8);

	Caine c1("negru", "Nume_Caine1", 9, false);
	Caine c2("portocaliu", "Nume_Caine2", 11, true);

	//early-binding
	cout << "\n\n++early-binding++\n\n";

	//a1.scoateSunet();

	p1.scoateSunet();
	p1.Animal::scoateSunet();


	//late-binding
	cout << "\n\n++late-binding++\n\n";
	//obiecte si pointeri la obiecte
	cout << "\n==obiecte si pointeri la obiecte==\n";
	//Animal* ap1, * ap2;
	//ap1 = &a1;
	//ap2 = &a2;

	//a1.scoateSunet();
	//a2.scoateSunet();
	ap1->scoateSunet();
	ap2->scoateSunet();
	cout << endl;

	Pisica* pp1, * pp2;
	pp1 = &p1;
	pp2 = &p2;

	p1.scoateSunet();
	p2.scoateSunet();
	pp1->scoateSunet();
	pp2->scoateSunet();
	pp2->scriePisica();
	cout << endl;

	Caine* cp1, * cp2;
	cp1 = &c1;
	cp2 = &c2;

	c1.scoateSunet();
	c2.scoateSunet();
	cp1->scoateSunet();
	cp2->scoateSunet();
	cout << endl;

	//conversie la pointeri de obiecte de baza
	cout << "\n==conversie la pointeri de obiecte de baza==\n";
	ap1->scoateSunet();
	cout << ap1->determinaVarstaInAniOmenesti() << " ani omenesti" << endl;

	ap1 = pp1;
	ap1->scoateSunet();
	cout << ap1->determinaVarstaInAniOmenesti() << " ani omenesti" << endl;

	ap1 = cp1;
	ap1->scoateSunet();
	cout << ap1->determinaVarstaInAniOmenesti() << " ani omenesti" << endl;


	//vector dinamic de pointeri de animale
	cout << "\n==vector dinamic de pointeri de animale==\n";
	Animal** animale = new Animal * [4]{/* &a1, &a2,*/ &p1, &p2, &c1, &c2 };
	for (int i = 0; i < 4; i++) {
		animale[i]->scoateSunet();
	}

	//try-catch
	cout << "\n\n++try-catch++\n";
	try
	{
		ap1->setCuloare("ssss");

		ap1->setVarsta(55);
	}
	catch (exception* e)
	{
		cout << e->what() << "Eroarea nu este fatala. Programul poate continua\n";
	}
	catch (ExceptieCustom* e) {
		cout << e->what() << "Eroarea nu este fatala. Programul poate continua\n";
	}
}