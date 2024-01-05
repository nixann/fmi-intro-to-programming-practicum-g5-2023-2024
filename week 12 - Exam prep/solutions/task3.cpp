#include <iostream>
#include <iomanip>

bool helper(int** dungeon, int rows, int cols, int i, int j, int currHp) {
	// Ако сме умрели на някоя стъпка, не може да продължим нататък
	if (currHp <= 0) return false;
	// Ако сме излезли от матрицата
	if (i >= rows || j >= cols) return false;
	// Ако сме в долния десен край на матрицата, сме готови
	if (i == rows - 1 && j == cols - 1) return true;

	// Пробваме 3-те посоки, като от текущия живот вадим или прибавяме живот според числото от текущата клетка
	// Искаме дали изобщо има път, затова ползваме оператора ||, т.е. търсим дали има път надясно ИЛИ надолу ИЛИ надолу и надясно
	return helper(dungeon, rows, cols, i + 1, j, currHp + dungeon[i][j]) ||
		helper(dungeon, rows, cols, i, j + 1, currHp + dungeon[i][j]) ||
		helper(dungeon, rows, cols, i + 1, j + 1, currHp + dungeon[i][j]);

	// Забележете, че тук не ни трябва матрица visited, защото ако сме на дадена клетка,
	// тъй като можем само да се движим надолу и надясно, не можем да я повторим по-нататък по пътя
}

bool canSurvive(int** dungeon, int rows, int cols, int startingHp) {
	return helper(dungeon, rows, cols, 0, 0, startingHp);
}

int main() {
	int** dungeon = new int* [4];
	dungeon[0] = new int[] {-2, -3, 3, -5};
	dungeon[1] = new int[] {-5, 10, -30, -7};
	dungeon[2] = new int[] {-30, -30, -30, 1};
	dungeon[3] = new int[] {-30, -30, 5, 0};

	for (int i = 1; i <= 10; i++) {
		std::cout << std::boolalpha << canSurvive(dungeon, 4, 4, i) << std::endl;
	}

	for (int i = 0; i < 4; i++) delete[] dungeon[i];
	delete[] dungeon;
}