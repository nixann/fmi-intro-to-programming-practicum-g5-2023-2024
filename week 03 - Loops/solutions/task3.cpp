#include <iostream>

int main() {
	unsigned n;
	std::cin >> n;

	unsigned fact = 1;
	for (unsigned i = 1; i <= n; i++) {
		fact = fact * i;
	}

	std::cout << "n!: " << fact << std::endl;
}