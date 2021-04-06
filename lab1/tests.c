#include "acutest.h"
#include "functions.h"

void testThree() {
	TEST_CHECK_(threeDigit(123) == 6, "threeDigit(%d) == %d", 123, 6);
}

void testFour() {
	TEST_CHECK_(fourDigit(5235)==15, "fourDigit(%d)==%d", 5235, 15);
}

TEST_LIST = {
	{"threeDigit(int);", testThree},
	{"fourDigit(int);", testFour},
	{0}
};
