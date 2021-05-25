#include "acutest.h"
#include "functions.h"

void testDivision() {
	TEST_CHECK_(division(16) == 2, "division(int currentNumber) == %d", 2);
}

TEST_LIST = {
	{"division(int currentNumber)", testDivision},
	{0}
};