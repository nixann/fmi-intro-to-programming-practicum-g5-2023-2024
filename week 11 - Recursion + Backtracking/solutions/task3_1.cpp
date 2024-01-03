#include <iostream>

// Тази задача е просто имплементация на алгоритъма за търсене в дълбочина (DFS)
// Приемаме, че булевата матрица е граф, в който децата на всеки връх са 4-те съседни клетки
// В DFS ни е нужен масив от вече срещнатите върхове, в тази задача матрицата lab изпълнява тази роля,
// тъй като дали една клетка е проходима или вече посетена, няма особено значение (и в двата случая няма как да имаме път от нея до границата)

bool canEscape(bool** lab, int numRows, int numCols, int currRow, int currCol) {
	// Първо ще се погрижим за дъната на рекурсията

	// Ако текущата клетка е непроходима или вече посетена, няма как да имаме път до края (във втория случай няма да имаме път, защото ще зациклим)
	if (!lab[currRow][currCol]) return false;

	// Ако всичко досега е наред и сме на границата, връщаме истина
	if (currRow == 0 || currCol == 0 || currCol == numCols - 1 || currRow == numRows - 1) return true;

	// Вече сме посетили текущата клетка и я маркираме като такава (за да не я повторим по-нататък)
	lab[currRow][currCol] = false;

	bool result = false;
	result = canEscape(lab, numRows, numCols, currRow + 1, currCol) ||
		canEscape(lab, numRows, numCols, currRow, currCol + 1) ||
		canEscape(lab, numRows, numCols, currRow - 1, currCol) ||
		canEscape(lab, numRows, numCols, currRow, currCol - 1);

	return result;
}

int main() {
	bool** labyrinth = new bool* [6];
	labyrinth[0] = new bool[] {0, 1, 0, 0, 0, 1};
	labyrinth[1] = new bool[] {0, 1, 1, 1, 0, 1};
	labyrinth[2] = new bool[] {0, 0, 1, 1, 0, 0};
	labyrinth[3] = new bool[] {0, 0, 0, 1, 0, 0};
	labyrinth[4] = new bool[] {0, 0, 0, 1, 0, 0};
	labyrinth[5] = new bool[] {0, 0, 0, 0, 0, 0};
	std::cout << std::boolalpha << canEscape(labyrinth, 6, 6, 3, 3) << std::endl;

	for (int i = 0; i < 6; i++) delete[] labyrinth[i];
	delete[] labyrinth;
}