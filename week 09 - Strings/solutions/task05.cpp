#include <iostream>
#include <cstring>

char** splitIntoWords(char* sentence) {
	int numWords = 0;
	// Първо си изчисляваме колко да ни е голям масивът от думи
	// Допускаме, че няма поредни интервали един след друг и че няма интервали в началото/края на изречението
	char* temp = sentence;
	while (*temp) {
		if (*temp == ' ') {
			numWords++;
		}
		temp++;
	}
	numWords += 1;

	char** wordDict = new char* [numWords];
	
	temp = sentence;
	for (int i = 0; i < numWords; i++) {
		char* endOfStr = std::strchr(temp, ' ');

		int neededSize;
		if (!endOfStr) { // т.е. ако не сме намерили интервал
			// Тогава просто ще копираме целия оставащ низ
			neededSize = std::strlen(temp);
		}
		else neededSize = endOfStr - temp;

		// Знаем размера и сме готови да заделим памет
		wordDict[i] = new char[neededSize + 1]();

		// Копираме
		for (int j = 0; j < neededSize; j++) {
			wordDict[i][j] = temp[j];
;		}

		temp = temp + neededSize + 1; // +1 за да прескочим интервала
	}
	return wordDict;
}

int main() {
	char sentence[] = "This is a valid sentence";
	char** wordDict = splitIntoWords(sentence);

	for (int i = 0; i < 5; i++) {
		std::cout << wordDict[i] << std::endl;
	}

	for (int i = 0; i < 5; i++) {
		delete[] wordDict[i];
	}
	delete[] wordDict;
}