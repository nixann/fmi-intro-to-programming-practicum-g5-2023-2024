#include <iostream>

const int MAX_SIZE = 50;
int getMaxAboveMainDiag(int matrix[][MAX_SIZE], int size) {
	if (size == 1 || size == 0) throw std::runtime_error("Invalid size for matrix");

	int currentMax = matrix[0][1];

	// Знаем, че елементите по главния диагонал имат равни i и j
	// Тогава индексът на колоната на елементите над главния диагонал ще бъде избързал спрямо този на редовете т.е. j > i
	// А самото j започва от i + 1, а не от i, защото по условие не гледаме елементите по главния диагонал
	// Напр. ако сме на ред 0, елементът по главния диагонал на този ред има позиция (0, 0)
	// Елементите над главния диагонал (или отдясно на него) ще се намират отдясно на (0, 0),
	// т.е. това са елементите с позиции (0, 1), (0, 2), (0, 3), ..., (0, size-1), или тези елементи с индекс на колоната по-голям от 0
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (matrix[i][j] > currentMax) {
				currentMax = matrix[i][j];
			}
		}
	}

	return currentMax;
}

int main() {
	int matrix[][MAX_SIZE] = {
		{1,  7,  3,  11},
		{5,  22,  6,  4},
		{5,  24,  62,  1},
		{21,  2,  3,  13}
	};
	std::cout << "Max above main diagonal: " << getMaxAboveMainDiag(matrix, 4) << std::endl;
}