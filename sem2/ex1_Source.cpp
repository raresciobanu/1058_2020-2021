#include<iostream>

using namespace std;

void afisare(int x, int* y) {
	cout << x << " ";

	if (y == nullptr) {
		cout << "\"nullptr\"" << endl;
	}
}

int main() {
	int x = 11, y = 12, z = 33, w = 44;

	const int aa = 200;
	//aa = 21;//error

	//pointer constant la o zona de memorie
	int* const px = &x;

	//px = &y;//error
	*px = 55;

	//pointer la o zona de memorie constanta
	const int* py; // sau int const* pz = &z;

	py = &y;
	//*py = 20;//error

	//pointer constant la o zona de memorie constanta
	const int* const pz = &z;
	//pz = &w;//error
	//*pz = 100;//error

	int* pu = NULL;
	int* pv = nullptr;

	afisare(NULL, pv);

	int iiii;
}