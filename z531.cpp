#include <iostream>
using namespace std;

// funkcija koja postavlja vrijednosti
// �lanova niza
//
//                   deklaracija niza kao argumenta funkcije
//                   ��������
void inicijalizacija(int iA[]) {
	for (int i = 0; i < 10; i++)
		iA[i] = 2 * i;
}

// funkcija koja ra�una i vra�a sumu niza
int suma(int iA[]) {
	int s = 0;

	for (int i = 0; i < 10; i++)
		s = s + iA[i];

	return s;
}

int main() {
	int A[10];				// deklaracija niza

// poziv funkcije, uz proslje�ivanje niza kao argumenta
	inicijalizacija(A);
	// ispis sadr�aja niza
	for (int i = 0; i < 10; i++)
		cout << "A[" << i << "]=" << A[i] << endl;

	// ispis sume niza
	cout << "Suma niza je:" << suma(A) << endl;

	return 0;
}
