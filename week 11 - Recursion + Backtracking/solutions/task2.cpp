#include <iostream>

// Тази задача е много сходна с 10-та зад. от седмица 10
// Тук обаче не искаме да генерираме просто всички изрази, съдържащи скоби, а имаме и някакво условие - те да са валидни
// Израз от скоби е валиден, ако има равен брой отварящи и затварящи скоби и отварящите скоби са преди затварящите
// т.е. затварящите скоби никога не надминават отварящите и накрая се изравняват
// Затова на всяка стъпка си пазим в променливата diff разликата между отварящите и затварящите скоби
void bracketsHelper(unsigned length, int diff, char* curr, unsigned currIndex) {
	// Дъно - вече няма какво да генерираме
	if (!length) {
		// Преди да отпечатаме израза, гледаме дали броят на затварящите и отварящите скоби е равен
		if (diff != 0) return;
		// Отпечатваме си натрупаният досега низ
		std::cout << curr << std::endl;
		return;
	}
	// За да е валиден израз не трябва затварящите в никой момент да надминават отварящите скоби
	// Затова ако някъде по средата на генерирането се изравни броят, принудени сме да сложим отваряща скоба
	// Ако не проверим това, може накрая броят да е равен, но затварящите да са преди отварящите
	if (diff == 0) {
		curr[currIndex] = '(';
		bracketsHelper(length - 1, diff + 1, curr, currIndex + 1);
		return;
	}
	curr[currIndex] = ')';
	bracketsHelper(length - 1, diff - 1, curr, currIndex + 1);
	curr[currIndex] = '(';
	bracketsHelper(length - 1, diff + 1,curr, currIndex + 1);
}

void printBrackets(unsigned length) {
	char* curr = new char[length + 1]();
	bracketsHelper(length, 0, curr, 0);
	delete[] curr;
}

int main() {
	printBrackets(10);
}