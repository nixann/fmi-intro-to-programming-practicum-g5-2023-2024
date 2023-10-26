#include <iostream>

int main() {
	unsigned n;
	std::cin >> n;

	bool isPrime = true;
	for (unsigned i = 2; i <= n / 2; i++) {
		if (n % i == 0) {
			isPrime = false;
			break;
		}
	}

	// Алтернативно решение, което е по-бързо
	/*bool isPrime = true;
	for (unsigned i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			isPrime = false;
			break;
		}
	}*/

	if (isPrime) std::cout << "The number is prime" << std::endl;
	else std::cout << "The number is not prime" << std::endl;
}