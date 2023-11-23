#include <iostream>

const int MAX_ROWS = 50;
const int MAX_COLS = 50;

// Транспониране в нова матрица
void transpose(int mat[][MAX_COLS], int rows, int cols) {
	int transposedMat[MAX_ROWS][MAX_COLS];

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			transposedMat[j][i] = mat[i][j];
		}
	}

	for (int i = 0; i < cols; i++) {
		for (int j = 0; j < rows; j++) {
			std::cout << transposedMat[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

// Транспонира същата матрица
// Тя е квадратна => само едни размер е достатъчен
void transpose(int mat[][MAX_COLS], int size) {
	// Ще обхождаме само горната половина на матрицата
	// т.е. частта над главния диагонал (повече обяснения за това обхождане има в решението на 6-та задача)
	// Ако не направим така, то след като разменим елементите (i, j) и (j, i)
	// след определен брой итерации ще се озовем на (j, i), пак ще ги разменим и накрая все едно не сме направили нищо
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			swap(mat[i][j], mat[j][i]);
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			std::cout << mat[i][j] << " ";
		}
		std::cout << std::endl;
	}
}

int main() {

	int A[MAX_ROWS][MAX_COLS] = {
		{5, 0, 1, 4},
		{11, -8, 31, 9},
		{6, 6, 10, 15}
	};

	int B[MAX_ROWS][MAX_COLS] = {
		{2, 5, 3},
		{8, 17, -25},
		{60, 81, 11}
	};

	transpose(A, 3, 4);
	std::cout << std::endl;
	transpose(B, 3);
}