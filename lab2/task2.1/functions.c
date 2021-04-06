#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void inputLengthEdge(int *lengthEdge) {
	scanf("%d", lengthEdge);
}

double outputEdgeSum(int *lengthEdge) {
	return *lengthEdge * 6;
}

double outputAreaFace(int *lengthEdge) {
	return pow(*lengthEdge, 2) * sqrt(3) / 4;
}

double outputVolumeTetrahedron(int *lengthEdge) {
	return pow(*lengthEdge, 3) * sqrt(2) / 12;
}

double outputLengthHeight(int *lengthEdge) {
	return sqrt(pow(*lengthEdge, 2) - 2 * sqrt(pow(*lengthEdge, 2) / 2) / 3);
}

double outputRadiusInscribedSphere(int *lengthEdge) {
	return *lengthEdge * sqrt(6) / 12;
}

void outputInfo() {
	printf("Автор: Акиншев Дмитрий, студент гр. 053501\nВерсия программы: v1.0.0");
}

void end() {
	exit(0);
}