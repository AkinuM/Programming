#include "acutest.h"
#include "functions.h"
#include <math.h>

void testCountDecomposition() {
	TEST_CHECK_(countDecomposition(1,2) == 5/6, "countDecomposition(1,2) == %d", 5/6);
}

TEST_LIST = {
	{"countDecomposition(double x, int n)", testCountDecomposition},
	{0}
};