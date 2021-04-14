#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include "functions.h"

int main()
{
	int m, n;
	printf("Enter m: ");
	while (1) {
		if (scanf("%d", &m) && m >= 0) {
			break;
		}
		else {
			while (getchar() != '\n');
			printf("Try again\n");
		}
	}
	printf("Enter n: ");
	while (1) {
		if (scanf("%d", &n) && n >= 0) {
			break;
		}
		else {
			while (getchar() != '\n');
			printf("Try again\n");
		}
	}
	int** matrix;
	matrix = (int**)malloc(m * sizeof(int*));
	if (matrix == NULL) {
		return 0;
	}
	int i, j;
	for (i = 0; i < m; i++) {
		matrix[i] = (int*)malloc(n * sizeof(int));
		if (matrix[i] == NULL) {
		return 0;
		}
		for (j = 0; j < n; j++) {
			printf("[%d][%d] = ", i, j);
			while (!scanf("%d", &matrix[i][j])) {
				while (getchar() != '\n');
				printf("Try again\n");
			}
		}
	}
	int k;
	for (i = 1; i < m; i++) {
		for (j = 0; j < i; j++) {
			int multiplier1 = matrix[i][j], multiplier2 = matrix[0][j];
			for (k = j; k < n; k++) {
				matrix[i][k] = countElement(matrix, i, k, multiplier1, multiplier2);
			}
		}
	}
	int rang = 0;
	for (i = 0; i < m; i++) {
		int sum = 0;
		for (j = 0; j < n; j++) {
			sum += matrix[i][j];
			if (sum != 0) {
			rang++;
			break;
			}
		}
	}
	printf("rang = %d\n", rang);
	for (i = 0; i < m; i++) {
			free(matrix[i]);
	}
	free(matrix);
	return 0;
}
