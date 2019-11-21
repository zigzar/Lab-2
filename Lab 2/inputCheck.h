#include <iostream>
using namespace std;

int inputCheck() {
	while (true) {
		int input;
		cin >> input;
		if (cin.fail()) {
			cin.clear();
			cin.ignore(cin.rdbuf()->in_avail());
			cout << endl << "Попробуйте ввести корректное число: ";
		}
		else {
			cin.ignore(cin.rdbuf()->in_avail());
			return input;
		}
	}
}