#include <iostream>
#include <cstring>

const unsigned MAX_SIZE = 34;

unsigned getDigitCount(int num) {
	unsigned count = 0;
	while (num) {
		count++;
		num /= 10;
	}
	return count;
}

void shiftRight(char* str) {
	char* end = str + std::strlen(str) + 1;
	// Записваме си терминиращата нула
	// Този граничен случай по принцип се хваща от цикъла
	*end = 0;
	end--;

	while (end != str) {
		*end = *(end - 1);
		end--;
	}
	
	/*Алтернативен начин :
	int length = std::strlen(str);
	for(int i = length + 1; i > 0; i--) {
		str[i] = str[i - 1];
	}
	*/
}

void writeToStr(char* str, int numToWrite, int numDigits) {
	int index = numDigits - 1;
	while (numToWrite) {
		int digitToWrite = numToWrite % 10;
		str[index--] = (char)(digitToWrite + '0');
		numToWrite /= 10;
	}
}

bool convertToStrNumber(char* str) {
	unsigned histogram[26] = {};

	// Попълване на хистограмата
	char* temp = str;
	while (*temp) {
		histogram[*temp - 'a']++;
		temp++;
	}

	// Проверка дали нужното място е по-голямо от максималното налично
	unsigned neededSize = 0;
	for (int i = 0; i < 26; i++) {
		neededSize += histogram[i] * getDigitCount(histogram[i]);
	}

	// Неравенството е нестрого, защото трябва да оставим и 1 място за терминиращата нула
	if (neededSize >= MAX_SIZE) return false;

	while(*str) {
		int numToWrite = histogram[*str - 'a'];
		int numDigits = getDigitCount(numToWrite);

		// Отместваме надясно, за да си освободим място за записване
		for (int j = 1; j < numDigits; j++) {
			shiftRight(str);
		}
		writeToStr(str, numToWrite, numDigits);

		str += numDigits;
	}
	return true;
}

int main() {
	char str[MAX_SIZE] = "aaabcaadcsmaabbbbsaaacc";
	if (convertToStrNumber(str)) std::cout << str << std::endl;
	else std::cout << "Not enough space" << std::endl;
}