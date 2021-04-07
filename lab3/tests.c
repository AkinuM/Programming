#include "acutest.h"
#include "functions.h"
#include <malloc.h>

static int** getMatrix() {
	int** matrix;
	matrix = (int**)malloc(2 * sizeof(int*));
	int i;
	for (i = 0; i < 2; i++) {
		matrix[i] = (int*)malloc(2 * sizeof(int));
	}
	matrix[0][0] = 1;
	matrix[0][1] = 1;
	matrix[1][0] = 1;
	matrix[1][1] = 1;
	return matrix;
}

void testCountElement() {
	TEST_CHECK_(countElement(getMatrix(), 1, 1, 1, 1) == 0, "countElement(matrix, 1, 1, 1, 1) == %d", 0);
}

TEST_LIST = {
	{"countElement(int** matrix, int i, int k, int multiplier1, int multiplier2)", testCountElement},
	{0}
};
