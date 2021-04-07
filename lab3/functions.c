int countElement(int** matrix, int i, int k, int multiplier1, int multiplier2) {
	return matrix[0][k] * multiplier1 - matrix[i][k] * multiplier2;
}