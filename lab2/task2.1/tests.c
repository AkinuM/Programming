#include "acutest.h"
#include "functions.h"
#include <math.h>

int lengthEdge = 6;

void testEdgeSum() {
	TEST_CHECK_(fabs(outputEdgeSum(&lengthEdge)) == 36, "outputEdgeSum(&lengthEdge) == %d", 36);
}

void testAreaFace() {
	TEST_CHECK_(fabs(15.6 - outputAreaFace(&lengthEdge)) < 0.1, "outputAreaFace(&lengthEdge) == %.1f", 15.6);
}

void testVolumeTetrahedron() {
	TEST_CHECK_(fabs(25.5 - outputVolumeTetrahedron(&lengthEdge)) < 0.1 , "outputVolumeTetrahedron(&lengthEdge) == %.1f", 25.5);
}

void testLengthHeight() {
	TEST_CHECK_(fabs(5.8 - outputLengthHeight(&lengthEdge)) < 0.1, "outputLengthHeight(&lengthEdge) == %.1f", 5.8);
}

void testRadiusInscribedSphere() {
	TEST_CHECK_(fabs(1.2 - outputRadiusInscribedSphere(&lengthEdge)) < 0.1, "outputRadiusInscribedSphere(&lengthEdge) == %.1f", 1.2);
}

TEST_LIST = {
	{"outputEdgeSum(int *lengthEdge);", testEdgeSum},
	{"outputAreaFace(int *lengthEdge);", testAreaFace},
	{"outputVolumeTetrahedron(int *lengthEdge);", testVolumeTetrahedron},
	{"outputLengthHeight(int *lengthEdge);", testLengthHeight},
	{"outputRadiusInscribedSphere(int *lengthEdge);", testRadiusInscribedSphere},
	{0}
};