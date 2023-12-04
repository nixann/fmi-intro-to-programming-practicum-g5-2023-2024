#include <iostream>
#include <cstring>
#include <cassert>

void shiftLeft(char* sentence) {
	for (int i = 0; sentence[i]; i++) {
		sentence[i] = sentence[i + 1];
	}
}

void deleteIntruder(char* sentence, char* intruder) {
	// Този assert е, за да се махнат предупрежденията от компилатора, не е съществен
	assert(sentence != nullptr);

	while (*sentence) {
		// т.е. ако намерим търсената дума и тя започва от мястото, където сме в момента
		if (sentence == std::strstr(sentence, intruder)) {
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
	char str[] = "noot now this noot noot sentence noot is normal noot";
	char intruder[] = "noot";
	deleteIntruder(str, intruder);
	std::cout << str << std::endl;
}