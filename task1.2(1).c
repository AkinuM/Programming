#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	int number;
	scanf("%d", &number);
	if (number < 100 || number > 9999) {
		printf("Invalid expression");
		return 1;
	}
	if (number / 1000 == 0) {
		int result = (number % 10)*((number / 10) % 10)*(number / 100);
		printf("%d", result);
	}
	else {
		int result = (number % 10) + ((number / 10) % 10) + ((number / 100) % 10) + (number / 1000);
		printf("%d", result);
	}
}