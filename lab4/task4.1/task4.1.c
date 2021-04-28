#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include "functions.h"

typedef struct
{
	int strSize;
	char str[101];
} myPair;

int main()
{
	int countStrs;
	printf("Enter count of strings: ");
	while (1) {
		if (scanf("%d", &countStrs)) {
			break;
		}
		else {
			while (getchar() != '\n');
			printf("Try again\n");
		}
	}
	getchar();
	myPair* strs = (myPair*)malloc(countStrs * sizeof(myPair));
	if (strs == NULL) {
		return 0;
	}
	if (countStrs != 0) {
		printf("Enter text:\n");
	}
	int i, j;
	for (i = 0; i < countStrs; i++) {
		gets(strs[i].str);
		strs[i].strSize = countSize(strs[i].str);
	}
	for (i = 0; i < countStrs - 1; i++) {
		for (j = i + 1; j < countStrs; j++) {
			if (strs[i].strSize < strs[j].strSize) {
				myPair temp = strs[i];
				strs[i] = strs[j];
				strs[j] = temp;
			}
		}
	}
	for (i = 0; i < countStrs; i++) {
		int j = 0;
		while (strs[i].str[j] != 0) {
			printf("%c", strs[i].str[j]);
			j++;
		}
		printf("\n");
	}
}