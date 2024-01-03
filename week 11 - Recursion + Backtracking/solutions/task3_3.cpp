#include <iostream>

// !!
// В условието на тази подточка примерът е сбъркан.
// Трябва пътищата, които завършват на (0, 5) да ги няма, тъй като те са излишни

void printWayOut(int** currWay, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << "(" << currWay[i][0] << ", " << currWay[i][1] << ") ";
	}
	std::cout << std::endl;
}

void helper(bool** lab, int numRows, int numCols, int currRow, int currCol, int** currWay, int currIndex) {
	if (!lab[currRow][currCol]) return;
	currWay[currIndex++] = new int[] {currRow, currCol};

	if (currRow == 0 || currCol == 0 || currCol == numCols - 1 || currRow == numRows - 1) {
		printWayOut(currWay, currIndex);
		return;
	}

	lab[currRow][currCol] = false;

	helper(lab, numRows, numCols, currRow + 1, currCol, currWay, currIndex);
	helper(lab, numRows, numCols, currRow, currCol + 1, currWay, currIndex);
	helper(lab, numRows, numCols, currRow - 1, currCol, currWay, currIndex);
	helper(lab, numRows, numCols, currRow, currCol - 1, currWay, currIndex);

	// "Почистваме" след себе си (за да може да ползваме същата клетка с друг път)
	lab[currRow][currCol] = true;
}

void allWaysOut(bool** lab, int numRows, int numCols, int startingRow, int startingCol) {
	int** currWay = new int* [numRows * numCols]();

	helper(lab, numRows, numCols, startingRow, startingCol, currWay, 0);

	for (int i = 0; i < numRows * numCols; i++) {
		if (!currWay[i]) delete[] currWay[i];
	}
	delete[] currWay;
}

int main() {
	bool** labyrinth = new bool* [6];
	labyrinth[0] = new bool[] {0, 1, 0, 0, 0, 1};
	labyrinth[1] = new bool[] {0, 1, 1, 1, 1, 1};
	labyrinth[2] = new bool[] {0, 0, 1, 1, 0, 0};
	labyrinth[3] = new bool[] {0, 0, 0, 1, 1, 0};
	labyrinth[4] = new bool[] {0, 0, 0, 1, 1, 1};
	labyrinth[5] = new bool[] {0, 0, 0, 1, 0, 0};

	allWaysOut(labyrinth, 6, 6, 3, 3);

	for (int i = 0; i < 6; i++) delete[] labyrinth[i];
	delete[] labyrinth;
}