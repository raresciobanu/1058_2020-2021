#include<iostream>

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

int main() {
	int u = 120;
	cout << "u=" << u << endl;
	cout << "refU=" << &u << endl;

	int* pu = &u;
	cout << "pu=" << pu << endl;
	cout << "*pu=" << *pu << endl;

	//////////////////
	int* px = new int(5);
	cout << "px=" << *px << endl;
	delete px;

	int arr[] = { 2,11,3,41,21,4 };
	int* py = arr;

	cout << "adrese din vector static" << endl;
	cout << &arr[1] << endl;
	cout << &arr[2] << endl;
	cout << "adrese din pointer" << endl;
	cout << (py + 1) << endl;
	cout << (py + 2) << endl;


	cout << *(py + 1) << endl;
	cout << *(py + 2) << endl;

	int* w = new int[3];
	for (int i = 0; i < 3; i++) {
		w[i] = i + 1 * 3;
	}

	for (int i = 0; i < 3; i++) {
		cout << "w[" << i << "]=" << w[i] << " ";
	}
	cout << endl;
	delete[] w;

	int** matrice = new int* [3];
	for (int i = 0; i < 3; i++) {
		matrice[i] = new int[4];
		for (int j = 0; j < 4; j++) {
			matrice[i][j] = (i + j + 1) * 2;
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			cout << matrice[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < 3; i++) {
		delete matrice[i];
	}

	delete[] matrice;




	int N, elementNou;
	cout << "N="; cin >> N;
	int* t = new int[N];
	for (int i = 0; i < N; i++) {
		cout << "t[" << i << "]=";  cin >> t[i];
	}
	cout << "ElementNou="; cin >> elementNou;

	int* aux = new int[N + 1];
	for (int i = 0; i < N; i++) {
		aux[i] = t[i];
	}

	aux[N++] = elementNou;
	delete[] t;
	t = aux;

	for (int i = 0; i < N; i++) {
		cout << "t[" << i << "]=" << t[i] << " ";
	}

	delete[] t;
}