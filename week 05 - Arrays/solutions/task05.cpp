#include <iostream>

int abs(int x) {
	if (x < 0) return -x;
	return x;
}

int main() {
	int n;
	std::cin >> n;

	const int MAX_SIZE = 100;

	if (n < 0 || n > MAX_SIZE) throw std::runtime_error("Invalid input");

	int arr[MAX_SIZE];

	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}

	int oscillation = 0;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {

			// Ако тук беше написано така: (Тоест без вземане на модул)
			//		if (oscillation < arr[i] - arr[j]) {
			//			oscillation = arr[i] - arr[j];
			//		}
			// Тогава трябваше променливата j да започва да итерира от 0, помислете защо

			if (oscillation < abs(arr[i] - arr[j])) {
				oscillation = abs(arr[i] - arr[j]);
			}
		}
	}

	// Разбира се, можеше и просто да се извади стойността на минималния елемент на масива от стойността на максималния елемент

	std::cout << "Осцилация: " << maxOscillation << std::endl;
}