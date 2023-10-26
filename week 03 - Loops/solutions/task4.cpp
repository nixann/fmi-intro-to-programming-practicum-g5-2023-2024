#include <iostream>

int main() {
	int n;
	std::cin >> n;

	int temporary = n;
	int powerOf10 = 1;

	while (temporary > 9) {
		temporary /= 10;
		powerOf10 *= 10;
	}

	int firstDigit = temporary;
	int lastDigit = n % 10;

	// Why no unsigned here?
	n = n + (-firstDigit + lastDigit) * powerOf10;
	n = n + (-lastDigit + firstDigit);

	std::cout << "Swapped digit number: " << n << std::endl;
}