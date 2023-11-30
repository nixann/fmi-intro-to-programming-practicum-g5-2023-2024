#include <iostream>

int main() {
	unsigned N, M;
	std::cin >> N >> M;

	unsigned** matrix = new unsigned* [N];
	for (unsigned i = 0; i < N; i++) {
		matrix[i] = new unsigned[M];

		for (unsigned j = 0; j < M; j++) {
			std::cin >> matrix[i][j];
			if (matrix[i][j] < 0 || matrix[i][j] >= M) throw std::runtime_error("Invalid input");
		}
	}

	// Тъй като всяка верижка започва от първи ред, но от различна колона, циклим по стартиращата колона
	for (unsigned startingCol = 0; startingCol < M; startingCol++) {
		// Пазим си следващата колона в променлива
		unsigned currentCol = startingCol;
		for (unsigned numRow = 0; numRow < N; numRow++) {
			std::cout << matrix[numRow][currentCol] << " ";
			// Update-ваме си променливата с индекса на новата колона
			currentCol = matrix[numRow][currentCol];
		}
		std::cout << std::endl;
	}


	for (unsigned i = 0; i < N; i++) {
		delete[] matrix[i];
	}
	delete[] matrix;
}