#include <iostream>

int main() {
	const int MAX_SIZE = 50;
	int n, m;
	std::cin >> n >> m;

	if (n > 50 || m > 50) throw std::runtime_error("Invalid input");

	// Инициализация
	int matrix[MAX_SIZE][MAX_SIZE];

	// Въвеждане
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> matrix[i][j];
		}
	}

	int sum = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			sum += matrix[i][j];
		}
	}

	std::cout << "Sum: " << sum << std::endl;
}