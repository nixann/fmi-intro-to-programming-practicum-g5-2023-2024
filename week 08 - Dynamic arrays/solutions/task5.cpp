#include <iostream>

int** order(int* numbers, int size, int k) {
	int numRows = size / k;
	int** mat = new int*[numRows];

	// overallCounter ще ни казва кой елемент от numbers трябва да сложим в matrix[i][j]
	// Можеше да се мине и без тази променлива като в цикъла щеше да бъде numbers[i * k + j]
	int overallCounter = 0;
	for(int i = 0; i < numRows; i++) {
		mat[i] = new int[k];
		for (int j = 0; j < k; j++) {
			mat[i][j] = numbers[overallCounter++];
		}
	}

	return mat;
}

int main() {
	int* arr = new int[9];
	for (int i = 0; i < 9; i++) arr[i] = i + 1;

	int** mat = order(arr, 9, 3);

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			std::cout << mat[i][j] << " ";
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < 3; i++) delete[] mat[i];
	delete[] mat;
}