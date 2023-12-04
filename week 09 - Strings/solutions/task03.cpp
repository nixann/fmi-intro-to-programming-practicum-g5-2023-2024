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
	std::cin.ignore();

	// Нищо не е променено по функциите, буквално са копирани от миналите 2 задачи
	// Единствено отначало низът е заделен динамично
	char* str = new char[n + 1]();
	std::cin.getline(str, n + 1);

	countSymbols(str);
	std::cout << strToNum(str) << std::endl;

	delete[] str;
}