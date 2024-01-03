#include <iostream>

// Това е просто задача 13 от седмица 5 - от 2 сортирани масива да построим нов сортиран масив
void splitAndMerge(int*& arr, int length) {
	int* arr1 = arr;
	int length1 = length / 2;
	int* arr2 = arr + length / 2;
	int length2 = length - length / 2;

	int* temp = new int[length];
	int i = 0, j = 0, k = 0;
	while (i < length1 && j < length2) {
		if (arr1[i] <= arr2[j]) {
			temp[k] = arr1[i];
			i++;
		}
		else {
			temp[k] = arr2[j];
			j++;
		}
		k++;
	}

	while (i < length1) {
		temp[k++] = arr1[i++];
	}

	while (j < length2) {
		temp[k++] = arr2[j++];
	}

	
	for (int i = 0; i < length; i++) {
		arr[i] = temp[i];
	}
	delete[] temp;
}

// Може да работим с индекси, но този начин е сякаш по-елегантен
void mergeSort(int* arr, int length) {
	if (length <= 1) return;
	mergeSort(arr, length / 2);
	mergeSort(arr + length / 2, length - length / 2);
	splitAndMerge(arr, length);
}

int main() {
	int* arr = new int[]{ -1, 5, 3, 7, 0, -5, 1, 1, -5 };
	mergeSort(arr, 9);
	for (int i = 0; i < 9; i++) std::cout << arr[i] << " ";
	delete[] arr;
}