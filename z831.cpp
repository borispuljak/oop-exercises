#include <iostream>
// predlo�ak tvector - otvoriti za detalje
#include "tvector.h"

using namespace std;

int main()
{
// deklaracija objekta vec kao spremnika tipa tvector
    tvector<double> vec;
    double val;

	cout << "Unos proizvoljnog niza brojeva u vektor." << endl;
	cout << "Unos zavrsava kada se otkuca neko slovo!" << endl;
// punjenje vektora
    while (cin >> val)
	{
		vec.push_back(val);
	}

// nakon zavr�enog unosa ra�unamo sumu i srednju vrijednost
    double sum = 0;
	for (int i=0; i<vec.size(); i++) {
// pojedinom �lanu vektora pristupamo sli�no kao i �lanu nizaa
        sum += vec[i];
	}
    double avg =sum /vec.size();

    cout <<"Suma od "<<vec.size()
         <<" elemenata: "<< sum
        <<". Srednja vrijednost: "<< avg << endl;

	return 0;
}
