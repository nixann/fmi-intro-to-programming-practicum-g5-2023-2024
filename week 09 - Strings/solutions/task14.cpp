#include <iostream>

void getOffset(int dir, int& offsetR, int& offsetC) {
	switch (dir) {
	case 0:
		offsetR = -1;
		offsetC = -1;
		break;
	case 1:
		offsetR = +1;
		offsetC = -1;
		break;
	case 2:
		offsetR = +1;
		offsetC = +1;
		break;
	case 3:
		offsetR = -1;
		offsetC = +1;
		break;
	default:
		throw std::runtime_error("Invalid direction");
		break;
	}
}

int updateDir(int dir, int i, int j, int r, int c) {
	// i == 0 -> Излезли сме отгоре
	// j == 0 -> Излезли сме отляво
	// i >= r - 1 -> Излезли сме отдолу
	// j >= c - 1 -> Излезли сме отдясно
	// !!! Трябва да проверим и дали не сме излезли по някой от диагоналите
	// т.е. напр. дали не е едновременно вярно, че i == 0 && j == 0, т.е. дали не сме уцелили горният ляв ъгъл
	// Тогава трябва да обърнем посоката
	
	switch (dir)
	{
	case 0:
		if (i == 0 && j == 0) return 2;
		if (i == 0) return 1;
		if (j == 0) return 3;
		break;
	case 1:
		if (i >= r - 1 && j == 0) return 3;
		if (i >= r - 1) return 0;
		if (j == 0) return 2;
		break;
	case 2:
		if (i >= r - 1 && j >= c - 1) return 0;
		if (i >= r - 1) return 3;
		if (j >= c - 1) return 1;
		break;
	case 3:
		if (i == 0 && j >= c - 1) return 1;
		if (i == 0) return 2;
		if (j >= c - 1) return 0;
		break;
	}
}

int traverseDiag(bool** matrix, int& startingR, int& startingC, int& dir, int numRows, int numCols, int& numMoves) {
	// За по-лесно ще си пазим 2 променливи, които ще ни дават изменението по редовете/колоните
	// Можеше да ползваме и 4 вложени цикъла с доста if-ове, които да ни проверяват диагонала и посоката на ходене по диагонала,
	// но мисля, че това решение е малко по-чисто
	int offsetI, offsetJ;
	getOffset(dir, offsetI, offsetJ);

	int ans = 0;
	int currentI = startingR;
	int currentJ = startingC;

	// Обхождаме, докато не стигнем някоя стена/таван/под на матрицата
	do {
		// Ако сме намерили небоядисано поле, боядисваме го и го отчитаме в бройката
		if (!matrix[currentI][currentJ]) {
			matrix[currentI][currentJ] = true;
			ans++;
		}
		// Може да си мислите за (offsetI, offsetJ) като двумерен вектор, който прибавяме към (currentI, currentJ)
		// и така получаваме нова точка в нашата равнина
		currentI += offsetI;
		currentJ += offsetJ;

		// Не забравяме да намалим броя на ходовете и да проверим дали сме приключили предварително преди да обходим целия диагонал
		numMoves--;
		if (!numMoves) return ans;
	} while (currentI > 0 && currentJ > 0 && currentI < numRows - 1 && currentJ < numCols - 1);
	// Сега трябва да си подновим променливите за посока и позиция в началото,
	// за да ги преизползваме със същата функция

	startingR = currentI;
	startingC = currentJ;

	// Сега, за да изчислим новата посока няма сякаш лесен начин да избягаме от if-овете
	dir = updateDir(dir, currentI, currentJ, numRows, numCols);
	return ans;
}

// Подаваме булева матрица, в която с false отбелязваме немаркирани полета, а с true - маркирани
// По принцип няма нужда от подаване на цяла матрица, може да се подадат и само размери, но уви... така пише в условието
int findNumPainted(bool** matrix, int numRows, int numCols, int i, int j, int dir, int numMoves) {

	// Валидация
	if (numRows < 0 || numCols < 0 || i < 0 || j < 0 || i >= numRows || j >= numCols || dir < 0 || dir > 3 || numMoves < 0) {
		throw std::runtime_error("Invalid input");
	}

	int finalAns = 0;
	while (numMoves > 0) {
		finalAns += traverseDiag(matrix, i, j, dir, numRows, numCols, numMoves);
	}
	return finalAns;
}

int main() {
	bool** matrix = new bool*[7]();
	for (int i = 0; i < 7; i++) matrix[i] = new bool[16]();

	int numRows = 7;
	int numCols = 16;
	int i = 5;
	int j = 5;
	int dir = 3;
	int numMoves = 19;
	std::cout << findNumPainted(matrix, numRows, numCols, i, j, dir, numMoves);

	for (int i = 0; i < 7; i++) delete[] matrix[i];
	delete[] matrix;
}