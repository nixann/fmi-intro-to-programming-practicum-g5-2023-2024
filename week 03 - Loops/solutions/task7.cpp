#include <iostream>

int main() {
	unsigned n;
	std::cin >> n;

	unsigned currentNumber = 1;
	for (unsigned i = 1; i <= n; i++) {
		for (unsigned j = 1; j <= i; j++) {
			std::cout << currentNumber << " ";
			currentNumber += 1;
		}
		std::cout << std::endl;
	}
}