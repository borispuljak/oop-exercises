#include <iostream>
using namespace std;

const int def_iarray_size = 5;

class iarray {
public:
	// predodre�eni konstruktor 
	iarray(int def_size = def_iarray_size) {
		init(nullptr, def_size);
	}
	// kopirni konstruktor 
	iarray(const iarray& rhs) {
		init(rhs.m_arr, rhs.m_size);
	}
	// konstruktor pomo�u postoje�eg int * niza 
	iarray(const int *array, int size) {
		init(array, size);
	}
	// destruktor
	~iarray(void) {
		delete[] m_arr;
	}
	// pridjela vrijednosti
	iarray& operator=(const iarray&);
	// daje broj elemenata niza 
	int size() const { return m_size; }
	// indeksni operator 
	int& operator[](int index);
private:
	// pomo�na funkcija 
	void init(const int *array, int size);
	// pokaziva� na memoriju koja sadr�i niz 
	int *m_arr;
	// broj elemenata niza 
	int m_size;
};

void iarray::init(const int *array, int size) {
	// alociraj memoriju veli�ine m_size cijelih brojeva 
	m_size = size;
	m_arr = new int[size];
	//inicijaliziraj niz 
	if (array != 0) {
		for (int index = 0; index < size; index++) {
			m_arr[index] = array[index];
		}
	}
}
