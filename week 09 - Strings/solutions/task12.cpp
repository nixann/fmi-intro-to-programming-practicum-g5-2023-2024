#define _CRT_SECURE_NO_WARNINGS // Ако не сложим това, програмата ще даде грешка
#include <iostream>
#include <cstring>

void swap(char*& arr1, char*& arr2, unsigned& freq1, unsigned& freq2) {
	char* tempRow = arr1;
	arr1 = arr2;
	arr2 = tempRow;

	// Ако ще разменяме масивите, трябва да разменим и честотите им, за да продължи да ни е валидна хистограмата
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
			// Трябва да сортираме и според дължината тези, които се срещат еднакъв брой пъти
			else if (vals[j] == vals[maxIndex] && std::strlen(keys[j]) < std::strlen(keys[maxIndex])) {
				maxIndex = j;
			}
		}
		swap(keys[i], keys[maxIndex], vals[i], vals[maxIndex]);
	}
}

void addToHistogram(char** histogramKeys, unsigned* histogramVals, char* word, int& currentSize) {
	bool found = false;
	for (int i = 0; i < currentSize; i++) {
		// Ако сме намерили същата дума вече в хистограмата
		if (!std::strcmp(histogramKeys[i], word)) {
			found = true;
			histogramVals[i]++;
		}
	}
	// Ако не сме намерили думата, добавяме я в хистограмата
	if (!found) {
		histogramKeys[currentSize] = new char[std::strlen(word) + 1];
		std::strcpy(histogramKeys[currentSize], word);
		currentSize++;
	}
}

char* sortByFreq(char* sentence) {
	// Хващаме някои гранични случаи
	if (!sentence || !std::strlen(sentence)) return new char[1]();

	// Тази задача е нещо като обобщение на идеята за хистограма
	// Тук ще пазим колко пъти се срещат дадени думи
	// т.е. ще знаем, че думата записана на индекс i в histogramKeys,
	// се среща histogramVals[i] на брой пъти

	// Тук можем по принцип да подходим с преоразмеряващ се масив, но това е много работа
	// Затова можем да си заделим някакъв максимален размер първоначално и да ползваме само определен брой от елементите му
	// Не можем за тази задача обаче да ползваме статичен масив, тъй като размерът ще зависи от дължината на подаденото изречение
	int maxLength = std::strlen(sentence);
	int currentHistogramSize = 0;
	char** histogramKeys = new char*[maxLength];
	unsigned* histogramVals = new unsigned[maxLength]();

	char* temp = sentence;
	// Попълване на хистограмата
	while (*temp) {

		// Копираме намерената дума в нов временен низ
		char* strToAdd = new char[maxLength]();
		int i = 0;
		for (; temp[i] && temp[i] != ' '; i++) {
			strToAdd[i] = temp[i];
		}
		// Ще добавим временния низ към хистограмата или ще увеличим брояча на даден индекс ако вече думата я има
		addToHistogram(histogramKeys, histogramVals, strToAdd, currentHistogramSize);

		delete[] strToAdd;

		temp = temp + i;
		if (!*temp) break;
		temp++; // +1 за да прескочим интервала
	}

	// Сега ще сортираме хистограмата според това всяка дума колко често се среща
	// Този трик сме го правили и преди (6-та задача, 8-ма седмица)
	selectionSort(histogramKeys, histogramVals, currentHistogramSize);

	//for (int i = 0; i < currentHistogramSize; i++) {
	//	std::cout << histogramKeys[i] << std::endl;
	//}

	// Готови сме да наслагаме всичко в новия низ
	// Трябва първо, както обикновено, да изчислим размера му
	int ansSize = 0;
	for (int i = 0; i < currentHistogramSize; i++) {
		ansSize += std::strlen(histogramKeys[i]) + 1; // +1 заради интервала 
	}
	ansSize -= 1; // -1, за да махнем последния интервал

	char* ans = new char[ansSize + 1]();
	int currentIndex = 0;
	for (int i = 0; i < currentHistogramSize; i++) {
		int currentWordLength = std::strlen(histogramKeys[i]);
		for (int j = 0; j < currentWordLength; j++) {
			ans[currentIndex++] = histogramKeys[i][j];
		}
		ans[currentIndex++] = ' ';
	}
	ans[currentIndex - 1] = 0; // Презаписваме си терминиращата нула

	// Вече хистограмите не ни трябват и трябва да ги изтрием
	for (int i = 0; i < currentHistogramSize; i++) delete[] histogramKeys[i];
	delete[] histogramKeys;
	delete[] histogramVals;

	return ans;
}

int main() {
	//char str[] = "this is not what it is";
	char str[] = "Have you ever had a dream that you, um, you had, your, you- you could, you’ll do, you- you wants, you, you could do so, you- you’ll do, you could- you, you want, you want him to do you so much you could do anything?";
	char* newStr = sortByFreq(str);
	std::cout << newStr << std::endl;
	delete[] newStr;
}