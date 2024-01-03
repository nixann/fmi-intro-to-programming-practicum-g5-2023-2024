#include <iostream>

void copy(int**& dest, int** src, int& oldSize, int& newSize) {
	if (dest) {
		for (int i = 0; i < oldSize; i++) delete[] dest[i];
		delete[] dest;
	}

	dest = new int* [newSize];
	for (int i = 0; i < newSize; i++) {
		dest[i] = new int[2];
		dest[i][0] = src[i][0];
		dest[i][1] = src[i][1];
	}
	oldSize = newSize;
}

void helper(bool** lab, int numRows, int numCols, int currRow, int currCol, int** currWay, int currIndex, int& minSize, int**& minWay) {
	if (!lab[currRow][currCol]) return;
	currWay[currIndex++] = new int[] {currRow, currCol};

	if (currRow == 0 || currCol == 0 || currCol == numCols - 1 || currRow == numRows - 1) {
		// Единствената промяна е тук
		// Когато намерим изход от лабиринта, сравняваме с текущия минимален път
		// и променяме минимума, ако е нужно

		// Тъй като ще променяме пътят и размерът му, затова ги подаваме във функцията по референция
		if (currIndex < minSize) {
			copy(minWay, currWay, minSize, currIndex);
		}
		return;
	}

	lab[currRow][currCol] = false;

	helper(lab, numRows, numCols, currRow + 1, currCol, currWay, currIndex, minSize, minWay);
	helper(lab, numRows, numCols, currRow, currCol + 1, currWay, currIndex, minSize, minWay);
	helper(lab, numRows, numCols, currRow - 1, currCol, currWay, currIndex, minSize, minWay);
	helper(lab, numRows, numCols, currRow, currCol - 1, currWay, currIndex, minSize, minWay);

	lab[currRow][currCol] = true;
}

int** shortestWayOut(bool** lab, int numRows, int numCols, int startingRow, int startingCol, int& resultingSize) {
	int** currWay = new int* [numRows * numCols]();
	int** minWay = nullptr;
	int minSize = numRows * numCols + 1;
	helper(lab, numRows, numCols, startingRow, startingCol, currWay, 0, minSize, minWay);
	
	if (minSize == numRows * numCols + 1) {
		resultingSize = 0;
	}
	else resultingSize = minSize;
	
	for (int i = 0; i < numRows * numCols; i++) {
		if (!currWay[i]) delete[] currWay[i];
	}
	delete[] currWay;

	return minWay;
}

int main() {
	bool** labyrinth = new bool* [6];
	labyrinth[0] = new bool[] {0, 1, 0, 0, 0, 1};
	labyrinth[1] = new bool[] {0, 1, 1, 1, 0, 1};
	labyrinth[2] = new bool[] {0, 0, 1, 1, 0, 0};
	labyrinth[3] = new bool[] {0, 0, 0, 1, 0, 0};
	labyrinth[4] = new bool[] {0, 0, 0, 0, 1, 1};
	labyrinth[5] = new bool[] {0, 0, 0, 1, 0, 0};

	int size;
	int** path = shortestWayOut(labyrinth, 6, 6, 3, 3, size);

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