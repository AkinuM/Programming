#include "acutest.h"
#include "functions.h"

bst<int, int> test;
bst<int, int> input() {
	test.insert(2, 2);
	test.insert(1, 1);
	test.insert(3, 3);
	return test;
}


void testCountLevel() {
	TEST_CHECK_(countLevel(input(), 2) == 2, "countLevel(bst<int, int> numbers, int level) == %d", 2);
}

TEST_LIST = {
	{"countLevel(bst<int, int> numbers, int level)", testCountLevel},
	{0}
};	