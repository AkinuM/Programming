#include "acutest.h"
#include "functions.h"

void testInputCheck() {
	TEST_CHECK_(inputCheck(2) == 2, "inputCheck(int i) == %d", 2);
}

TEST_LIST = {
	{"inputCheck(int i)", testInputCheck},
	{0}
};	