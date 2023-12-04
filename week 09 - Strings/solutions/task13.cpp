#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

void swap(char*& arr1, char*& arr2, unsigned& freq1, unsigned& freq2) {
	char* tempRow = arr1;
	arr1 = arr2;
	arr2 = tempRow;
	unsigned tempFreq = freq1;
	freq1 = freq2;
	freq2 = tempFreq;
}

void selectionSort(char** keys, unsigned* vals, int size) {
	for (int i = 0; i < size; i++) {
		int maxIndex = i;
		for (int j = i + 1; j < size; j++) {
			if (vals[j] > vals[maxIndex]) {
				maxIndex = j;
			}
			else if (vals[j] == vals[maxIndex] && std::strlen(keys[j]) < std::strlen(keys[maxIndex])) {
				maxIndex = j;
			}
		}
		swap(keys[i], keys[maxIndex], vals[i], vals[maxIndex]);
	}
}

bool startsWith(char* haystack, char* needle) {
	while (*haystack && *needle) {
		if (*haystack != *needle) return false;
		haystack++;
		needle++;
	}
	if (!*needle && (!*haystack || *haystack == ' ')) return true;
	return false;
}

void addToHistogram(char** histogramKeys, unsigned* histogramVals, char* word, int& currentSize) {
	bool found = false;
	for (int i = 0; i < currentSize; i++) {
		if (!std::strcmp(histogramKeys[i], word)) {
			found = true;
			histogramVals[i]++;
		}
	}
	if (!found) {
		histogramKeys[currentSize] = new char[std::strlen(word) + 1];
		std::strcpy(histogramKeys[currentSize], word);
		currentSize++;
	}
}

void shiftRight(char* str) {
	char* end = str + std::strlen(str) + 1;
	*end = 0;
	end--;

	while (end != str) {
		*end = *(end - 1);
		end--;
	}
}

void shiftLeft(char* sentence) {
	for (int i = 0; sentence[i]; i++) {
		sentence[i] = sentence[i + 1];
	}
}

void weirdReplace(char* sentence) {
	// Тук първоначално нещата са точно както в 12-та задача

	if (!sentence || !std::strlen(sentence)) return;
	int maxLength = std::strlen(sentence);
	int currentHistogramSize = 0;
	char** histogramKeys = new char* [maxLength];
	unsigned* histogramVals = new unsigned[maxLength]();

	char* temp = sentence;
	while (*temp) {
		char* strToAdd = new char[maxLength]();
		int i = 0;
		for (; temp[i] && temp[i] != ' '; i++) {
			strToAdd[i] = temp[i];
		}
		addToHistogram(histogramKeys, histogramVals, strToAdd, currentHistogramSize);
		delete[] strToAdd;
		temp = temp + i;
		if (!*temp) break;
		temp++;
	}
	selectionSort(histogramKeys, histogramVals, currentHistogramSize);

	// Ето тук е промяната в 13-та задача
	// Ще приемем, че низът sentence е статичен и може да се побере в макс. размер след замените
	// Ако беше динамичен, просто си слагваме новите думи в нов низ и присвояваме sentence на него

	temp = sentence;
	while (*temp) {
		char* replaceWith = nullptr, *toReplace = nullptr;
		for (int i = 0; i < currentHistogramSize; i++) {
			// т.е. в началото на коя дума сме в момента
			if (startsWith(temp, histogramKeys[i])) {
				toReplace = histogramKeys[i];

				// Сега ще видим с коя дума ще заменим текущата в нашия низ
				int n = std::strlen(histogramKeys[i]);

				// Ако n е твърде голямо, заменяме с последната дума
				// Сортирали сме си хистограмата => знаем коя е n-тата най-често срещата дума
				if (n > currentHistogramSize) {
					replaceWith = histogramKeys[currentHistogramSize - 1];
				}
				else {
					replaceWith = histogramKeys[n - 1];
				}
			}
		}

		// Тук имаме гаранция, че сме намерили дума, с която да заменим текущата

		int newLength = std::strlen(replaceWith);
		int oldLength = std::strlen(toReplace);

		// Идеята е проста
		// Ако новата дума (т.е. тази, с която ще заменим текущата) е с по-голям размер от старата,
		// избутваме елементите на низа надясно, докато не се освободи достатъчно място
		// Иначе ще изтрием достатъчно елементи, за да не презаписваме върху останалата част от низа

		if (newLength > oldLength) {
			for (int i = 1; i <= newLength - oldLength; i++) shiftRight(temp);
		}
		else {
			for (int i = 1; i <= oldLength - newLength; i++) shiftLeft(temp);
		}

		// Сега вече презаписваме
		while (*replaceWith) {
			*temp = *replaceWith;
			replaceWith++;
			temp++;
		}

		if (!*temp) break;
		temp++; // +1 за прескачане на интервала
	}

	for (int i = 0; i < currentHistogramSize; i++) delete[] histogramKeys[i];
	delete[] histogramKeys;
	delete[] histogramVals;
}

int main() {
	char str[1024] = "this is a is this is";
	weirdReplace(str); 
	std::cout << str << std::endl;
}