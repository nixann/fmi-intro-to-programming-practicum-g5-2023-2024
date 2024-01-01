#include <iostream>

bool isPrime(unsigned n) {
	if (n <= 1) return false;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

bool helper(unsigned* arr, int length, int index) {
	if (index == length) return false;
	if (isPrime(arr[index])) return true;
	return helper(arr, length, index + 1);
}

bool hasPrime(unsigned* arr, int length) {
	return helper(arr, length, 0);
}

// Алтернативен начин:
/*
bool hasPrime(unsigned* arr, int length) {
	if (!length) return false;
	return isPrime(*arr) || hasPrime(arr + 1, length - 1);
}
*/

int main() {
	unsigned arr[] = { 1, 4, 101, 8 };
	std::cout << (hasPrime(arr, 4) ? "Contains a prime" : "Doesn't contain a prime") << std::endl;
}