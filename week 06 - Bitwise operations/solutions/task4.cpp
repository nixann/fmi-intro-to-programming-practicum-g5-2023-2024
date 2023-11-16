#include <iostream>

int main() {
	unsigned n;
	std::cin >> n;

	unsigned counter = 0;
	while (n) {
		// Ако последният бит на n е 1, добавяме 1 към counter
		// Иначе добавяме 0
		counter += n & 1;
		// След всяка стъпка местим числото надясно, което все едно премахва най-десният бит
		// Продължаваме така докато не "стопим" числото до 0
		n = n >> 1;
	}
	std::cout << "Number of set bits: " << counter << std::endl;
}