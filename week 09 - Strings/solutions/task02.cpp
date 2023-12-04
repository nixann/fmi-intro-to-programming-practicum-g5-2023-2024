#include <iostream>

int strToNum(char* str) {
	int num = 0;
	while (*str) {
		int digit = *str - '0';
		num = num * 10 + digit;
		str++;
	}
	return num;

	/*
	Алтернативно решение:
	for(int i = 0; str[i] != 0; i++) {
		int digit = str[i] - '0';
		num = num * 10 + digit;
	}
	*/
}

int main() {
	unsigned n;
	std::cin >> n;
	if (n > 100) throw std::runtime_error("Invalid input");
	std::cin.ignore();

	char str[101] = {};
	std::cin.getline(str, n + 1);

	int ans = strToNum(str);
	std::cout << ans << std::endl;
}