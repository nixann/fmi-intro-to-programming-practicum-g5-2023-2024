#include <iostream>

int** groupBy(int* numbers, int size, int p) {
	int** remainderGroups = new int* [p];

	// Циклим по редовете, като техните индекси съвпадат със съответния остатък при деление на p
	for (int remainder = 0; remainder < p; remainder++) {
		// !!! Тук редовете на двумерния масив по условие имат различен брой елементи т.е. това не е обикновена матрица 
		// Тъй като имат различен размер, то трябва първо да изчислим размера на всеки ред
		// Размерът на i-тия ред са броят на числата от numbers с остатък i при деление на p
		int countCandidates = 0;
		for (int i = 0; i < size; i++) {
			if (numbers[i] % p == remainder) {
				countCandidates++;
			}
		}

		// Вече като имаме размера, чак сега си заделяме подходящия брой елементи
		// Ако нямахме този предварителен размер, нямаше как да знаем първоначално колко елемента ще има реда
		remainderGroups[remainder] = new int[countCandidates];

		// Пазим си брояч, който ни казва докъде сме стигнали с попълването на съответния ред
		int currentCol = 0;
		for (int i = 0; i < size; i++) {
			if (numbers[i] % p == remainder) {
				remainderGroups[remainder][currentCol++] = numbers[i];
			}
		}
	}
	return remainderGroups;
}

int main() {
	int* arr = new int[5];
	for (int i = 0; i < 5; i++) {
		arr[i] = i + 1;
	}
	int** rm = groupBy(arr, 5, 2);

	std::cout << rm[0][0] << " " << rm[0][1] << std::endl;
	std::cout << rm[1][0] << " " << rm[1][1] << " " << rm[1][2] << std::endl;

	delete[] rm[0];
	delete[] rm[1];
	delete[] rm;
	delete[] arr;	
}