#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "functions.h"

int main() {
	int number, result;
	if (scanf("%d", &number)) {
		if (number < 100 || number > 9999) {
			invalidExpression();
			return 1;
		}
		if (number / 1000 == 0) {
			result = threeDigit(number);
			printf("%d", result);
		}
		else {
			result = fourDigit(number);
			printf("%d", result);
		}
		return 0;
	}
	else {
		invalidExpression();
		return 1;
	}
}
