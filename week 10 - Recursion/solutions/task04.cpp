#include <iostream>
#include <iomanip>

unsigned getDigitSum(int n) {
	unsigned res = 0;
	while (n) {
		res += n % 10;
		n /= 10;
	}
	return res;
}

bool helper(int* arr, int length, int index, unsigned n) {
	// В празния масив очевидно условието "за всяко число..." е удовлетворено
	if (index == length) return true;
	// Ако някъде е нарушено условието, директно връщаме лъжа
	if (getDigitSum(arr[index]) % n != 0) return false;
	return helper(arr, length, index + 1, n);
}

bool sat(int* arr, int length, unsigned n) {
	return helper(arr, length, 0, n);
}

int main() {
	int arr[] = { 2, 6, 15, 28, 11 };
	std::cout << std::boolalpha << sat(arr, 5, 2) << std::endl;
}