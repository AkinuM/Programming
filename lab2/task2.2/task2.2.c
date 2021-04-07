#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include "functions.h"

int main()
{
	double x, e;
	printf("Enter x: ");
	while (!scanf("%lf", &x)) {
		while (getchar() != '\n');
		printf("Try again\n");
	}
	printf("Enter e: ");
	while (!scanf("%lf", &e)) {
		while (getchar() != '\n');
		printf("Try again\n");
	}
	int n = 1;
	double decomposition = countDecomposition(x, n);
	while (fabs(sin(x) - decomposition) > e) {
		decomposition = countDecomposition(x, ++n);
	}
	printf("n: %d\n", n);
	return 0;
}
