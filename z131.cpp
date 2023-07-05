// ukljuèi biblioteku za ulaz/izlaz
#include <iostream>
using namespace std;

int main()
{
    doble r, kvadrat, area;	// deklaracija varijabli r i area     
    r = 2;					// zadana vrijednost radijusa 2m  
	kvadrat = r/r;			// radijus na kvadrat
    area = kvadrat*3.14;	// proraèun površine kruga 
   
// ispis na ekran - dijelovi ispisa povezani su operatorom <<
// kljuèna rijeè endl znaèi pomak u novi red
	cout << "Povrsina kruga =" << area <<  "m" << endl;
	
	return 0;
}
