#include <iostream>

int helper(int* arr, int length, int index) {
	if (index == length) return 0;
	return arr[index] + helper(arr, length, index + 1);
}

int sum(int* arr, int length) {
	return helper(arr, length, 0);
}

int main() {
	int arr[] = { 1, 5, -3, 8, 10 };
	std::cout << sum(arr, 5) << std::endl;
}