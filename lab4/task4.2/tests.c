#include "acutest.h"
#include "functions.h"

void testCountSize() {
	TEST_CHECK_(countSize("fsdfvs") == 6, "countSize(char[]) == %d", 6);
}

TEST_LIST = {  
	{"countSize(char[])", testCountSize},
	{0}
};