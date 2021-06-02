#include <string>
#include <iostream>
using namespace std;

int inputCheck(int i) {
	while (1) {
		string strChoice;
		int choice;
		cout << "Enter your choice: ";
		cin >> strChoice;
		int j;
		for (j = 0; j < (int)strChoice.size(); j++) {
			if (strChoice[j]<'1' || strChoice[j]>'9') {
				break;
			}
		}
		if (j != (int)strChoice.size()) {
			cout << "Try again\n";
			continue;
		}
		choice = stoi(strChoice);
		if (choice < 1 || choice > i) {
			cout << "Try again\n";
			continue;
		}
		else {
			system("cls");
			return choice;
		}
	}
}