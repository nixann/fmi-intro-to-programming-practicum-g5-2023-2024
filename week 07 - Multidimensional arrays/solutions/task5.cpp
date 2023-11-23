﻿#include <iostream>

const int MAX_SIZE = 50;
int getMaxElement(int matrix[][MAX_SIZE], int size) {
	int maxEle = matrix[0][0];
	// Тук ключовото е, че като искаме да обхождаме елементите само по главния диагонал, не ни е нужен вложен цикъл
	// Това е така, защото на тези елементи номерът на реда и номерът на колоната винаги ще бъдат равни.
	for (int i = 1; i < size; i++) {
		if (maxEle < matrix[i][i]) {
			maxEle = matrix[i][i];
		}
	}
	return maxEle;
}

bool isPrime(int n) {
	if (n <= 1) return false;

	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

// Нужен ни е само един размер, тъй като матрицата е квадратна
void printPrimeDivisors(int matrix[][MAX_SIZE], int size) {

	// Тук може да се възползваме от това, че няма как да имаме делител на някой от елементите по главния диагонал
	// и той да е по-голям от най-големият елемент по главния диагонал
	// Напр. ако диагоналът има елементи 4, 60, 0, 72, то най-големият делител може да бъде най-много 72
	int m = getMaxElement(matrix, size);

	// Циклим по всички възможни делители
	for (int i = 2; i <= m; i++) {
		// Тъй като търсим само простите делители, в този if ще проверяваме първо дали делителят е прост
		// и чак след това ще правим неща с него
		if (isPrime(i)) {
			// Булевата променлива ще ни пази дали текущият делител се среща някъде по диагонала
			bool foundDiv = false;
			// Обхождаме елементите по диагонала
			for (int j = 0; j < size; j++) {
				// Ако намерим елемент, който се дели на i, вече сме готови да го отпечатаме и на сила излизаме от цикъла
				if (matrix[j][j] % i == 0) {
					foundDiv = true;
					break;
				}
			}
			if (foundDiv) {
				std::cout << i << " ";
			}
		}
	}
}

int main() {
	int mat[MAX_SIZE][MAX_SIZE] = {
		{24, 7, 3, 11},
		{5, 22, 6, 4},
		{5, 24, 8, 1},
		{21, 2, 3, 13}
	};
	printPrimeDivisors(mat, 4);
}