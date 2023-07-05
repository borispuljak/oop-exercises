#include <iostream>
#include <list>
#include <string>

using namespace std;

int main() {
	string str;
	list<string> lst;
	list<string>::iterator iter;

// �ita stringove sa tipkovnice, dok se ne upi�e "kraj"
// i upisuje ih u listu
	cin >> str;
	while (str != "kraj") {
		lst.push_back(str);
		cin >> str;
	}
	cout << endl;

// ispisuje stringove iz liste pomo�u for petlje sa iteratorom
	for (iter = lst.begin(); iter != lst.end(); ++iter) {
		cout << *iter << endl;
	}

	return 0;
}
