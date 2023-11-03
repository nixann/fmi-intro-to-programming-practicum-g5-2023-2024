#include <iostream>

int findMax(int arr[], int arrSize) {
	if (arrSize == 0) throw std::runtime_error("No elements");

	int maxElement = arr[0];

	for (int i = 1; i < arrSize; i++) {
		if (arr[i] > maxElement) {
			maxElement = arr[i];
		}
	}
	return maxElement;
}


int main() {
	unsigned n;
	std::cin >> n;

	// В масива idFrequencies елементът с индекс i ще съхранява колко пъти е чекирано id-то с номер i+1
	// Можеше да направим и нещо такова:
	//		int idFrequencies[101] = {};
	// 
	//		Тогава може на индекс i да съхраняваме броя чекирания на i-тото id 
	//		Индексиранията в следващите цикли обаче щяха да са малко по-различни. И 2-та варианта са напълно валидни

	// За да инициализираме масив само с нули, пишем след него "= {};"
	int idFrequencies[100] = {};

	for (unsigned i = 1; i <= n; i++) {
		int id;
		std::cin >> id;
		if (id < 1 || id > 100) throw std::runtime_error("Invalid id");

		idFrequencies[id - 1] += 1;
	}

	int maxFrequency = findMax(idFrequencies, 100);

	for (int i = 0; i < 100; i++) {
		if (idFrequencies[i] == maxFrequency) std::cout << (i + 1) << " ";
	}
	std::cout << std::endl;
}