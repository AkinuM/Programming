#include <stdio.h>

void invalidExpression() {
	printf("Invalid expression");
}

int threeDigit(int number) {
	return (number % 10)*((number / 10) % 10)*(number / 100);
}

int fourDigit(int number) {
	return (number % 10) + ((number / 10) % 10) + ((number / 100) % 10) + (number / 1000);
}
