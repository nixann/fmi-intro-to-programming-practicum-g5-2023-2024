#include <iostream>

const int MAX_ROWS = 50;
const int MAX_COLS = 50;

void multMatrices(int A[][MAX_COLS], int B[][MAX_COLS], int rowsA, int colsA, int rowsB, int colsB) {

	if (colsA != rowsB) throw std::runtime_error("Invalid dimensions");

	int c[MAX_ROWS][MAX_COLS] = {};

	// Ако А е NxM матрица, а B е MxK матрица, то AB е NxK матрица
	for (int cRow = 0; cRow < rowsA; cRow++) {
		for (int cCol = 0; cCol < colsB; cCol++) {
			for (int k = 0; k < colsA; k++) {
				c[cRow][cCol] += A[cRow][k] * B[k][cCol];
			}
		}
	}

	for (int i = 0; i < rowsA; i++) {
		for (int j = 0; j < colsB; j++) {
			std::cout << c[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main() {
	int A[MAX_ROWS][MAX_COLS] = {
		{1, 2, 3},
		{4, 5, 6 },
		{7, 8, 9}
	};

	int B[MAX_ROWS][MAX_COLS] = {
		{10, 11, 12, 13},
		{14, 15, 16, 17 },
		{18, 19, 20, 21}
	};

	multMatrices(A, B, 3, 3, 3, 4);
}