#include <iostream>

void countSymbols(char* str) {
	unsigned smallLetters = 0, bigLetters = 0, digits = 0, others = 0;
	while (*str) {
		if (*str >= '0' && *str <= '9') digits++;
		else if (*str >= 'a' && *str <= 'z') smallLetters++;
		else if (*str >= 'A' && *str <= 'Z') bigLetters++;
		else others++;
		str++;
	}

	std::cout << "Number of digits: " << digits << std::endl;
	std::cout << "Number of small letters: " << smallLetters << std::endl;
	std::cout << "Number of big letters: " << bigLetters << std::endl;
	std::cout << "Number of other symbols: " << others << std::endl;

	/*
	Алтернативно решение:
	for(int i = 0; str[i] != 0; i++) {
		if (str[i] >= '0' && str[i] <= '9') digits++;
		if (str[i] >= 'a' && str[i] <= 'z') smallLetters++;
		if (str[i] >= 'A' && str[i] <= 'Z') bigLetters++;
		else others++;
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

	countSymbols(str);
}