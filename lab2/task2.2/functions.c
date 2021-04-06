#include <math.h>

double countDecomposition(double x, int n) {
	int i, fact = 1;
	double decomposition = 0;
	for (i = 1; i < 2 * n - 1; i++) {
		fact *= i;
	}
	for (i = 1; i <= n; i++) {
		decomposition += pow(-1, i - 1) * pow(x, 2 * i - 1) / fact;
	}
	return decomposition;
}