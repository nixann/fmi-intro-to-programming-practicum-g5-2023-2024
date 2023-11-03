#include <iostream>

bool isPerfect(unsigned n) {

	// Edge case
	if (n == 0) return false;

	unsigned sumOfDivisors = 0;

	// Сбора на делителите на перфектното число не включва самото число, така че ще циклим не до самото n, а до n - 1
	// Затова неравенството в условието на цикъла е строго
	for (unsigned i = 1; i < n; i++) {
		if (n % i == 0) sumOfDivisors += i;
	}


	// Това е по-кратък вариант на:
	//		if(n == sumOfDivisors) return true;
	//		return false;
	return n == sumOfDivisors;
}

int main() {
	// В условието се предполага, че а и b са неотрицателни
	unsigned a, b;
	std::cin >> a >> b;

	for (unsigned i = a; i <= b; i++) {
		if (isPerfect(i)) std::cout << i << " ";
	}
	std::cout << std::endl;
}