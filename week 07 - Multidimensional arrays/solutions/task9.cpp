﻿#include <iostream>

const int MAX_SIZE = 50;

void traverseReverseDiag(int matrix[][MAX_SIZE], int size) {

	// Нека напр. имаме следната матрица:
	//  1 2 3 4
	//	5 1 7 9
	//	3 8 0 0
	//	2 4 6 1

	// Като тръгнем да обхождаме по обратни диагонали имаме следните индекси:
	// (0, 0)
	// (1, 0) -> (0, 1)
	// (2, 0) -> (1, 1) -> (0, 2)
	// (3, 0) -> (2, 1) -> (1, 2) -> (0, 3)

	// Какво забелязваме?
	// Ами за всеки нов диагонал i-то започва от един ред по-надолу
	// и започва да намалява, докато не стане 0, а
	// j-то започва все от 0 и се увеличава

	// Тоест на всяка стъпка от i вадим някакво число k (в кода е наречено offset), а на j прибавяме същото число k
	// Тогава ако напр. i е 2, то ние ще циклим по k, докато 2 - k не стане по-малко от 0 (за да не излезем отгоре извън на матрицата)
	
	// Това беше само горната половина от матрицата. За долната нещата са обърнати
	// Като тръгнем да обхождаме долната половина имаме:
	// (тук j почва от 1, защото вече сме минали през обратния диагонал по средата)
	// (3, 1) -> (2, 2) -> (1, 3)
	// (3, 2) -> (2, 3)
	// (3, 3)

	// Отново, забелязваме, че i винаги почва от 3 (разбира се в общия случай това е size - 1), а j започва всеки път от следващата колона отдясно
	// След това като обхождаме даден диагонал, j се увеличава, докато не стане 3 (т.е. size - 1), а i намалява
	// На всяка стъпка ще вадим от i числото k, а към j отново ще прибавяме k
	// k ще цикли докато j + k < size - 1 (за да не изхвърчим отдясно на матрицата)

	int totalSum = 0;

	// Обхождане на горната половина + средният диагонал
	for (int i = 0; i < size; i++) {
		int currentNumber = 0;
		for (int offset = 0; i - offset >= 0; offset++) {
			// Образуваме новото число, като умножим старото по 10, което все едно мести цифрите му наляво и добавяме новата цифра в края
			currentNumber = 10 * currentNumber + matrix[i - offset][offset];
		}
		totalSum += currentNumber;
		std::cout << currentNumber << " ";
	}

	// Обхождане на долната половина
	for (int j = 1; j < size; j++) {
		int currentNumber = 0;
		for (int offset = 0; j + offset < size; offset++) {
			currentNumber = 10 * currentNumber + matrix[size - 1 - offset][j + offset];
		}
		totalSum += currentNumber;
		std::cout << currentNumber << " ";
	}

	std::cout << std::endl << "Sum: " << totalSum << std::endl;
}

int main() {
	int matrix[][MAX_SIZE] = {
		{1, 2, 3, 4},
		{5, 1, 7, 9},
		{3, 8, 0, 0},
		{2, 4, 6, 1}
	};
	traverseReverseDiag(matrix, 3);
}