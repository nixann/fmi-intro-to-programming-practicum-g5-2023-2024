#include <iostream>

const int MAX_ROWS = 50;
const int MAX_COLS = 50;

void subtract(int A[][MAX_COLS], int B[][MAX_COLS], int rowsA, int colsA, int rowsB, int colsB) {
	if (rowsA != rowsB || colsA != colsB) throw std::runtime_error("Invalid dimensions");

	int C[MAX_ROWS][MAX_COLS];

	for (int i = 0; i < rowsA; i++) {
		for (int j = 0; j < colsA; j++) {
			C[i][j] = A[i][j] - B[i][j];
			std::cout << C[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

int main() {
	int A[MAX_ROWS][MAX_COLS] = {
		{5, 0, 1},
		{11, -8, 31},
		{6, 6, 10}
	};
	int B[MAX_ROWS][MAX_COLS] = {
		{2, 5, 3},
		{8, 17, -25},
		{60, 81, 11}
	};

	subtract(A, B, 3, 3, 3, 3);
}