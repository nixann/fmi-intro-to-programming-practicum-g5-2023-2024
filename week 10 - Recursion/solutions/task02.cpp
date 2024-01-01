#include <iostream>

// Използване на индекс както в цикъл
bool helper(int* arr, int length, int ele, int index) {
	if (index == length) return false;
	if (arr[index] == ele) return true;
	return helper(arr, length, ele, index + 1);
}

bool member(int* arr, int length, int ele) {
	return helper(arr, length, ele, 0);
}

// Алтернативен начин без използване на индекс:
/*
bool member(int* arr, int length, int ele) {
	if (!length) return false;
	return *arr == ele || member(arr + 1, length - 1, ele);
}
*/

int main() {
	int arr[] = { 1, 3, 5, -3, 7 };
	std::cout << (member(arr, 5, 2) ? "Is a member" : "Is not a member") << std::endl;
}
