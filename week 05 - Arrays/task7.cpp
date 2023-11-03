#include <iostream>

int main() {
	unsigned n;
	std::cin >> n;

	// Тук seen ни съхранява на всяка позиция колко пъти сме срещнали съответната цифра в n
	int seen[10] = {};

	unsigned temp = n;
	while (temp) {
		seen[temp % 10] += 1;
		temp /= 10;
	}

	bool foundRepeating = false;
	for (int i = 0; i < 10; i++) {
		if (seen[i] > 1) { // Тоест ако сме срещнали цифрата i повече от веднъж
			foundRepeating = true;
			break;
		}
	}

	std::cout << (foundRepeating ? "Not with unique digits" : "With unique digits") << std::endl;
}