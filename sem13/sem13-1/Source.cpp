#include<iostream>

using namespace std;

template <typename T> T adunare(T a, T b) {
	return a + b;
}

template <class T, class Y> Y inmultire(T a, Y b) {
	return a * b;
}

template<class T> class Vector {
private:
	int nrElem;
	T* elem;
public:
	Vector() {
		this->elem = nullptr;
		this->nrElem = 0;
	}

	Vector(int nrElem, T* elem) {
		this->nrElem = nrElem;

		this->elem = new T[nrElem];
		for (int i = 0; i < nrElem; i++) {
			this->elem[i] = elem[i];
		}
	}

	Vector(const Vector& v) {
		this->nrElem = v.nrElem;

		this->elem = new T[v.nrElem];
		for (int i = 0; i < v.nrElem; i++) {
			this->elem[i] = v.elem[i];
		}
	}

	~Vector() {
		if (elem != nullptr) {
			delete[] elem;
		}
	}

	int getSize() {
		return this->nrElem;
	}

	bool isEmpty() {
		return this->nrElem == 0;
	}

	void addElem(T elementNou) {
		T* aux = new T[nrElem + 1];
		for (int i = 0; i < nrElem; i++) {
			aux[i] = this->elem[i];
		}

		aux[nrElem++] = elementNou;
		delete[] this->elem;
		this->elem = aux;
	}

	void removeElem(int position) {
		if (position >= 0 && position < nrElem) {
			T* aux = new T[nrElem - 1];
			int k = 0;
			for (int i = 0; i < nrElem; i++) {
				if (i != position) {
					aux[k++] = this->elem[i];
				}
			}

			delete[] this->elem;
			this->elem = aux;
		}
		else {
			throw new exception("bad position!");
		}
	}

	T operator[](int index) {
		if (index >= 0 && index < nrElem) {
			return elem[index];
		}
		else {
			throw new exception("bad index in op[]!");
		}
	}
};

int main() {
	cout << "adunare: " << adunare<int>(4, 3) << endl;
	cout << "inmultire: " << inmultire<int, double>(4, 3.4) << endl << endl;


	Vector<double> vector1;
	vector1.addElem(2.2);
	vector1.addElem(3.9);
	vector1.addElem(4.6);
	vector1.addElem(5.5);
	for (int i = 0; i < vector1.getSize(); i++) {
		cout << "vector1[" << i << "] = " << vector1[i] << endl;
	}

	cout << endl << endl;
	Vector<string> vector2;
	vector2.addElem("aaaa");
	vector2.addElem("bbbb");
	vector2.addElem("cccc");
	vector2.addElem("dddd");
	vector2.addElem("eeee");
	for (int i = 0; i < vector2.getSize(); i++) {
		cout << "vector2[" << i << "] = " << vector2[i] << endl;
	}
}