#include <iostream>
#include <fstream>
#include "functions.h"
using namespace std;

int main() {
	ifstream fin("input.txt");
	bst<int, int> numbers;
	int number;
	for (int i = 1; fin >> number; i++) {
		numbers.insert(i, number);
	}
	cout << "Program successfully completed\n";
}