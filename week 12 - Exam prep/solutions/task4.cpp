#include <iostream>
#include <iomanip>

int min(int a, int b, int c) {
	if (a <= b && a <= c) return a;
	if (b <= c) return b;
	return c;
}

int helper(int** dungeon, int rows, int cols, int i, int j, int currHp, int healthBank) {
	// Ако сме излезли от матрицата, слагаме максималната стойност за int
	// По-правилно щеше да бъде, ако си бяхме изчислили предварително максималният живот, който може да загубим (т.е. сборът на всички отрицателни клетки)
	// и да ползваме него за невалидна стойност, но и така може
	if (i >= rows || j >= cols) return INT_MAX;
	if (i == rows - 1 && j == cols - 1) return currHp;

	// Идеята е на всеки момент currHp ще ни пази минималният живот, нужен, за да стигнем до текущата клетка
	// Поддържаме си и променливата healthBank, която ни казва колко живот сме натрупали досега от "лечебните" клетки

	// Ако срещнем опасност (т.е. числото е отрицателно)
	if (dungeon[i][j] < 0) {
		// Ако ще загубим живот, повече от натрупания от "лечебни" клетки досега
		if (-dungeon[i][j] > healthBank) {
			// Тук ще си изгубим всичкия натрупан живот
			// и за да не ни убие останалата част, трябва да си увеличим минималния живот, нужен за прекосяването на тази клетка
			currHp += -dungeon[i][j] - healthBank;
			healthBank = 0;
		}
		// Ако опасността е твърде малка, няма да си променяме минималния живот, защото
		// дори и да сме започнали с живот 1, "лечебните" клетки са ни вдигнали живота достатъчно високо,
		// че да не умрем от текущата клетка
		else healthBank += dungeon[i][j];
	}
	// Ако ще получаваме живот, минималният живот, нужен за стигане дотук няма да се промени
	// Трябва само да си обновим живота, който сме натрупали от "лечебните" клетки
	else healthBank += dungeon[i][j];

	return min(helper(dungeon, rows, cols, i + 1, j, currHp, healthBank), 
				helper(dungeon, rows, cols, i, j + 1, currHp, healthBank),
				helper(dungeon, rows, cols, i + 1, j + 1, currHp, healthBank));
}

int minSurvive(int** dungeon, int rows, int cols) {
	return helper(dungeon, rows, cols, 0, 0, 1, 0);
}

int main() {
	int** dungeon = new int* [4];
	dungeon[0] = new int[] {-2, -3, 3, -5};
	dungeon[1] = new int[] {-5, 10, -30, -7};
	dungeon[2] = new int[] {-30, -30, -30, 1};
	dungeon[3] = new int[] {-30, -30, 5, 0};

	std::cout << std::boolalpha << minSurvive(dungeon, 4, 4) << std::endl;

	for (int i = 0; i < 4; i++) delete[] dungeon[i];
	delete[] dungeon;
}