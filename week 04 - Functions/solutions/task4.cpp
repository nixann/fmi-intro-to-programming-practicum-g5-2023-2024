#include <iostream>

unsigned fact(unsigned x) {
	unsigned result = 1;
	for (unsigned i = 1; i <= x; i++) {
		result *= i;
	}
	return result;
}

int main() {
	unsigned n, k;
	std::cin >> n >> k;

	// Валидация
	if (k > n) throw std::invalid_argument("Invalid input");

	unsigned binomialCoeff = fact(n) / (fact(k) * fact(n - k));
	std::cout << "n choose k: " << binomialCoeff << std::endl;
}