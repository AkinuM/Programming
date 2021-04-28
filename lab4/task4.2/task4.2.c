#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "functions.h"

int main()
{
	FILE* text = fopen("text.txt", "r");
	char currentWord[100], nextWord[100];
	int countChars = 0;
	while (1) {
		fscanf(text, "%s", currentWord);
		countChars += countSize(currentWord);
		while (1) {
			fscanf(text, "%s", nextWord);
			if (countSize(currentWord) == countSize(nextWord)) {
				int i;
				for (i = 0; i < countSize(currentWord); i++) {
					if (currentWord[i] != nextWord[countSize(currentWord) - i - 1]) {
						break;
					}
				}
				if (i == countSize(currentWord)) {
					printf("%s  %s\n", currentWord, nextWord);
				}
			}
			if (fgetc(text) == EOF) {
				break;
			}
		}
		fseek(text, countChars, SEEK_SET);
		if (fgetc(text) == EOF) {
			break;
		}
	}
}