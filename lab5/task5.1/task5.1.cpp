#include <iostream>
#include <list>
#include <string>
#include <iterator>
#include "functions.h"
using namespace std;

int main()
{
	string inputNumber;
	int currentNumber = 1;
	cin >> inputNumber;
	list<int> number, result;
	for (int i = 0; i < inputNumber.length(); i++) {
		number.push_back(inputNumber[i] - '0');
	}
	while (number.size() != 1 || *number.begin() > 7) {
		list<int>::iterator it = number.begin();
		list<int> tempNumber;
		for (int i = 0; it != number.end(); i++) {
			if (i == 0) {
				currentNumber *= *it;
			}
			else {
				currentNumber = currentNumber * 10 + *it;
			}
			if (division(currentNumber) != 0) {
				tempNumber.push_back(division(currentNumber));
				currentNumber %= 8;
			}
			else if (tempNumber.size() > 0) {
				tempNumber.push_back(0);
			}
			it++;
		}
		number = tempNumber;
		result.push_front(currentNumber);
		currentNumber = 1;
	}
	result.push_front(*number.begin());
	list<int>::iterator itResult = result.begin();
	while (itResult != result.end()) {
		cout << *itResult;
		itResult++;
	}
}	