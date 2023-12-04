#include <iostream>
#include <cstring>
#include <cassert>

void shiftLeft(char* sentence) {
	for (int i = 0; sentence[i]; i++) {
		sentence[i] = sentence[i + 1];
	}
}

bool startsWith(char* haystack, char* needle) {
	while (*haystack && *needle) {
		if (*haystack != *needle) return false;
		haystack++;
		needle++;
	}

	// !!!
	if (!*needle && (!*haystack || *haystack == ' ')) return true;
	return false;
}

void deleteIntruder(char* sentence, char* intruder) {
	// Този assert е, за да се махнат предупрежденията от компилатора, не е съществен
	assert(sentence != nullptr);

	while (*sentence) {
		// Тук ще проверяваме дали сме намерим търсената дума и дали тя започва от мястото, където сме в момента
		
		// !!! Помислете защо няма да бъде вярно, ако напишем:
		//		if (sentence == std::strstr(sentence, intruder)) { ... }

		// Hint: ако текущата дума е напр. carpenter, а търсената е car, програмата ще изтрие част от carpenter, което не е вярно по условие

		if (startsWith(sentence, intruder)) {
			int numLettersToDelete = std::strlen(intruder) + 1;
			// Нали искаме да изтрием и интервала след дадената дума
			// Затова гледаме ако се натъкнем след думата на края на низа, не трием повече от дължината
			if (!sentence[numLettersToDelete]) numLettersToDelete--;

			// Трием дума с n символа като изтрием n символа от началото на текущата позиция
			for (int i = 1; i <= numLettersToDelete; i++) {
				shiftLeft(sentence);
			}
		}
		else sentence++;
	}
}

int main() {
	char str[] = "no now this no no sentence no is normal no";
	char intruder[] = "no";
	deleteIntruder(str, intruder);
	std::cout << str << std::endl;
}