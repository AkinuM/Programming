#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <locale.h>
#include <Windows.h>
#include "functions.h"

int main() {
	setlocale(LC_ALL, "Rus");
	int choice, lengthEdge = 0;
	while (1) {
		system("cls");
		printf("1. Ввод длины ребра тетраэдра.\n2. Вывод общей длины всех ребер тетраэдра.\n3. Вывод площади всех граней тетраэдра.\n4. Вывод объема тетраэдра.\n5. Вывод высоты тетраэдра.\n6. Вывод радиуса вписанного шара.\n7. Информация о версии и авторе программы.\n8. Выход из программы.\n\nВыберите пункт: ");
		if (scanf("%d", &choice)) {
			switch (choice) {
			case 1:
				system("cls");
				printf("Введите длину ребра тетраэдра: ");
				inputLengthEdge(&lengthEdge);
				break;
			case 2:
				system("cls");
				if (lengthEdge == 0) {
					printf("Сперва введите длину ребра тэтраэдра.");
					Sleep(2500);
					break;
				}
				else {
					printf("Общая длина всех ребёр тэтраэдра: %.1f", outputEdgeSum(&lengthEdge));
					Sleep(2500);
					break;
				}
			case 3:
				system("cls");
				if (lengthEdge == 0) {
					printf("Сперва введите длину ребра тэтраэдра.");
					Sleep(2500);
					break;
				}
				else {
					printf("Площадь всех граней тэтраэдра: %.1f", outputAreaFace(&lengthEdge));
					Sleep(2500);
					break;
				}
			case 4:
				system("cls");
				if (lengthEdge == 0) {
					printf("Сперва введите длину ребра тэтраэдра.");
					Sleep(2500);
					break;
				}
				else {
					printf("Объём тэтраэдра: %.1f", outputVolumeTetrahedron(&lengthEdge));
					Sleep(2500);
					break;
				}
			case 5:
				system("cls");
				if (lengthEdge == 0) {
					printf("Сперва введите длину ребра тэтраэдра.");
					Sleep(2500);
					break;
				}
				else {
					printf("Высота тэтраэдра: %.1f", outputLengthHeight(&lengthEdge));
					Sleep(2500);
					break;
				}
			case 6:
				system("cls");
				if (lengthEdge == 0) {
					printf("Сперва введите длину ребра тэтраэдра.");
					Sleep(2500);
					break;
				}
				else {
					printf("Радиус вписанного шара: %.1f", outputRadiusInscribedSphere(&lengthEdge));
					Sleep(2500);
					break;
				}
			case 7:
				system("cls");
				printf("Информация о версии и авторе программы:\n");
				outputInfo(&lengthEdge);
				Sleep(5000);
				break;
			case 8:
				end();
			default:
				system("cls");
				printf("Ошибка в выборе пункта");
				Sleep(2500);
			}
		}
		else {
			while (getchar() != '\n');
			system("cls");
			printf("Некорректный ввод");
			Sleep(2500);
		}
	}
}