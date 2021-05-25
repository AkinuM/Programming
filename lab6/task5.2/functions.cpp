#include "bst.cpp"
int countLevel(bst<int, int> numbers, int level) {
	int count = 0;
	for (int i = 1; i <= numbers.size(); i++) {
		if (numbers.find(i)->level == level) {
			count++;
		}
	}
	return count;
}