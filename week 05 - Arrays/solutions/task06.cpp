#include <iostream>

// Когато подаваме масив на функция и променим някой от елементите му,
// промените се отразяват на оригиналния масив. Така че тук няма нужда от допълнителни указатели.
// Това работи, защото самият масив вътрешно си е просто указател
void swap(int arr[], int i, int j) {
	int temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

void rotateArr(int arr[], int arrSize, int n) {
	for (int i = 1; i <= n; i++) {
		// Тук почваме от края и последователно "плъзгаме" последния елемент до началото, разменяйки го с всеки предходен
		for (int j = arrSize - 1; j >= 1; j--) {
			swap(arr, j, j - 1);
		}
	}
}

int main() {
	int arr[] = { 1, -5, 2, 0, 6, 9, 3 };
	rotateArr(arr, 7, 3);

	for (int i = 0; i < 7; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}