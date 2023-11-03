#include <iostream>

int main() {
	int n;
	std::cin >> n;

	const int MAX_SIZE = 1024;
	if (n < 0 || n > MAX_SIZE) throw std::runtime_error("Invalid n");
	int arr[MAX_SIZE];

	for (int i = 0; i < n; i++) {
		int input;
		std::cin >> input;
		if (input < 1 || input > 10) throw std::runtime_error("Invalid input");

		arr[i] = input;
	}

	// Selection sort
	for (int i = 0; i < n; i++) {
		// Тук постоянно си пазим освен максималната стойност, и максималния индекс, за да можем накрая да знаем кой елемент да сложим отпред
		int maxEl = arr[i];
		int maxIndex = i;
		for (int j = i + 1; j < n; j++) {
			if (maxEl < arr[j]) {
				maxEl = arr[j];
				maxIndex = j;
			}
		}
		arr[maxIndex] = arr[i];
		arr[i] = maxEl;
	}

	int desiredNumber = 0;
	for (int i = 0; i < n; i++) {
		desiredNumber = desiredNumber * 10 + arr[i];
	}
	std::cout << desiredNumber << std::endl;
}