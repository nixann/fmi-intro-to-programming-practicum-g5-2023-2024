#include <iostream>

int main() {
	unsigned sumAll = 0;
	unsigned sumRemainder = 0;
	unsigned countDivisible = 0;

	unsigned n;
	std::cin >> n;

	for (unsigned i = 1; i <= n; i++) {
		sumAll = sumAll + i;
	}

	for (unsigned i = 1; i <= n; i++) {
		if (i % 5 == 2) {
			sumRemainder = sumRemainder + i;
		}
	}

	// Втората подточка може също така да бъде решена така:
	/*for (unsigned i = 2; i <= n; i += 5) {
		sumRemainder += i;
	}*/

	for (unsigned i = 1; i <= n; i++) {
		if (i % 7 == 0 && i % 3 != 0 && i % 8 != 0) {
			countDivisible = countDivisible + 1;
			// coundDivisible += 1;
			// countDivisible++;
		}
	}

	std::cout << "Sum of all: " << sumAll << std::endl;
	std::cout << "Sum of those with 2(mod 5): " << sumRemainder << std::endl;
	std::cout << "Count of divisible by 7 and not by 3 and 8: " << countDivisible << std::endl;
}