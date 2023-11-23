﻿#include <iostream>

const int MAX_SIZE = 50;

void swap(int& a, int& b) {
	int temp = a;
	a = b;
	b = temp;
}

void deleteFromColumn(int matrix[][MAX_SIZE], int row, int col, int size) {
	// За да "изтрием" елемент, просто ще го преместим в края на масива
	// и след като намалим размера с 1, то все едно този елемент никога го е нямало

	// Да се внимава с индекса !!!, тъй като в масива ще достъпваме елемент с индекс i + 1, то трябва i да не е size - 1
	// иначе ще достъпим елемент извън паметта, заделена за масива
	for (int i = row; i < size - 1; i++) {
		// Разменяме текущия елемент със следващия, избутвайки оригиналния елемент през итерациите в края на колоната
		// Можеше и просто на текущия елемент да присвоим следващия
		swap(matrix[i][col], matrix[i + 1][col]);
	}
}

void deleteReverseDiag(int matrix[][MAX_SIZE], int size) {
	// Щом ще трием от обратния диагонал, трябва първо да видим как ще обхождаме обратния диагонал
	// Логиката е симетрична спрямо тази за главния диагонал
	// Напр. за 4x4 матрица елементите по обратния диагонал ще имат индекси (0, 3), (1, 2), (2, 1), (3, 0)
	// Забелязваме, че когато сме на ред i, j е равно на size - 1 - i

	for (int i = 0; i < size; i++) {
		deleteFromColumn(matrix, i, size - 1 - i, size);
	}
}

int main() {
	int matrix[][MAX_SIZE] = {
		{1,  7,  3,  11},
		{5,  22,  6,  4},
		{0,  24,  62,  1},
		{21,  2,  3,  13}
	};

	deleteReverseDiag(matrix, 4);

	// Отпечатване на матрицата
	// Намаляваме горната граница на i с 1, защото на последния ред ще съхраняваме изтритите елементи
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 4; j++) {
			std::cout << matrix[i][j] << " ";
		}
		std::cout << std::endl;
	}
}