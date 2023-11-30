#include <iostream>

void resize(int*& arr, int& capacity) {
	int* temp = new int[capacity * 2];
	for (int i = 0; i < capacity; i++) {
		temp[i] = arr[i];
	}
	delete[] arr;
	arr = temp;
	capacity *= 2;
}

// Тук отново имаме същата схема като миналата задача относно подаването по референции
void insert(int*& arr, int element, int index, int& capacity, int& currentSize) {
	if (index < 0 || index > currentSize) throw std::runtime_error("Invalid index");
	
	if (currentSize == capacity) {
		resize(arr, capacity);
	}


	// За да вмъкнем елемент в масива, трябва да изместим следващите елементи
	// с 1 напред, за да освободим място за новия елемент
	for (int i = currentSize - 1; i >= index; i--) {
		arr[i + 1] = arr[i];
	}

	arr[index] = element;
	currentSize++;
}

int main() {
	int capacity = 10;
	int currentSize = 0;

	int* arr = new int[capacity];

	for (int i = 0; i < 41; i++) {
		insert(arr, i, i, capacity, currentSize);
	}

	for (int i = 0; i < 10; i++) {
		insert(arr, -1, 5, capacity, currentSize);
	}

	for (int i = 0; i < currentSize; i++) {
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

	delete[] arr;
}