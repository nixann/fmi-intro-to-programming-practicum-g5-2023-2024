#include <iostream>

unsigned pow(unsigned n, unsigned m) {
	if (m == 0) return 1;
	return n * pow(n, m - 1);
}

int main() {
	std::cout << pow(2, 0) << std::endl;
}