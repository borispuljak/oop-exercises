#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void main(void)
{
// deklaracija objekta in_files klase ulaznog toka
// uz otvaranje datoteke cities 
	ifstream in_file("cities");
	
// provjera uspje�nosti otvaranja datoteke
	if (!in_file)
		return;

	string string_A;

// petlja za �itanje se prekida kod nailaska na kraj datoteke
	while (!in_file.eof())
	{
// �itanje jednog stringa iz datoteke
		in_file >> string_A;

// ispisivanje stringa na ekran
		cout << string_A << " ";
	}

// zatvaranje datoteke
	in_file.close();
	
}