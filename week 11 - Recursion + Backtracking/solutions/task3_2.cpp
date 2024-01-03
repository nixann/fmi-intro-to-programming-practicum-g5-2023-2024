#include <iostream>

// Идеята е сходна с тази от миналата подточка, тук обаче се търси и конкретен път
// Значи, трябва да си пазим текущия път до момента
// В resultingSize ще запишем крайната дължина на пътя, затова я подаваме по референция
void helper(bool** lab, int numRows, int numCols, int currRow, int currCol, int** currWay, int currIndex, int& resultingSize) {
	if (!lab[currRow][currCol]) return;

	// Ако resultingSize е 0, все още не е открит път (можеше да се ползва и булева променлива)
	// Ако не е 0, значи вече знаем как да излезем от лабиринта и не променяме текущия път
	if(!resultingSize) currWay[currIndex++] = new int[] {currRow, currCol};

	if (currRow == 0 || currCol == 0 || currCol == numCols - 1 || currRow == numRows - 1) {
		// Ако сме открили за първи път изход, записваме дължината
		if (!resultingSize) resultingSize = currIndex;
		return;
	}

	lab[currRow][currCol] = false;

	helper(lab, numRows, numCols, currRow + 1, currCol, currWay, currIndex, resultingSize);
	helper(lab, numRows, numCols, currRow, currCol + 1, currWay, currIndex, resultingSize);
	helper(lab, numRows, numCols, currRow - 1, currCol, currWay, currIndex, resultingSize);
	helper(lab, numRows, numCols, currRow, currCol - 1, currWay, currIndex, resultingSize);
}

int** someWayOut(bool** lab, int numRows, int numCols, int startingRow, int startingCol, int& resultingSize) {
	// Пътищата могат да бъдат най-много дълги, колкото са всички клетки в матрицата
	int** currWay = new int* [numRows * numCols];
	resultingSize = 0;
	helper(lab, numRows, numCols, startingRow, startingCol, currWay, 0, resultingSize);
	if (resultingSize == 0) return nullptr;
	return currWay;
}

int main() {
	bool** labyrinth = new bool* [6];
	labyrinth[0] = new bool[] {0, 1, 0, 0, 0, 1};
	labyrinth[1] = new bool[] {0, 0, 1, 1, 0, 1};
	labyrinth[2] = new bool[] {0, 0, 1, 1, 0, 0};
	labyrinth[3] = new bool[] {0, 1, 0, 1, 0, 0};
	labyrinth[4] = new bool[] {0, 1, 0, 1, 0, 1};
	labyrinth[5] = new bool[] {0, 0, 0, 0, 0, 0};
	int size;
	int** path = someWayOut(labyrinth, 6, 6, 3, 3, size);

	if (!size) std::cout << "No way" << std::endl;
	else {
		for (int i = 0; i < size; i++) {
			std::cout << "(" << path[i][0] << ", " << path[i][1] << ") ";
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < 6; i++) delete[] labyrinth[i];
	delete[] labyrinth;
	for (int i = 0; i < size; i++) delete[] path[i];
	delete[] path;
}