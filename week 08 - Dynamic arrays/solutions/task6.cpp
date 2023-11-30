#include <iostream>

// Както при нормалната swap функция, тук пак подаваме по референции, заради присвояването на указатели и размяната на числа
void swap(int*& arr1, int*& arr2, int& size1, int& size2) {
	int* tempRow = arr1;
	arr1 = arr2;
	arr2 = tempRow;

	// Логично е, че щом разменяме масивите, трябва да разменим и дължините им
	int tempSize = size1;
	size1 = size2;
	size2 = tempSize;
}

void selectionSort(int** arr, int* rowSizes, int numRows) {

	// Ето я реализацията на selectionSort за масиви с числа:
		//	for (int i = 0; i < n; i++) {
		//		int minIndex = i;
		//		for (int j = i + 1; j < n; j++) {
		//			if (arr[j] < arr[minIndex]) {
		//				minIndex = j;
		//			}
		//		}
		//		swap(arr[i], arr[minIndex]);
		//	}
	// Нашето сортиране ще има абсолютно същата структура
	// Единственото, което трябва да променим обаче е как ще сравняваме масивите и как ще ги разменяме
	// Сравняването е ясно, то ни е дадено по условие - ще им сравняваме дължините
	// Разменянето също е лесно, защото ако си нарисува човек как изглежда двумерната матрица, заделена динамично,
	// то може да види, че за да размени 2 реда просто трябва да размени двата указателя, които сочат към тези редове
	for (int i = 0; i < numRows; i++) {
		int minIndex = i;
		for (int j = i + 1; j < numRows; j++) {
			if (rowSizes[j] < rowSizes[minIndex]) {
				minIndex = j;
			}
		}
		swap(arr[i], arr[minIndex], rowSizes[i], rowSizes[minIndex]);
	}
}

int** subdivide(int* pool, int poolSize, int*& sizes, int numSizes) {
	// numSizes е броят на парчетата, на които ще разбием pool
	// т.е. това ще ни бъде броят редове
	int** staircase = new int* [numSizes];

	// Тази задача е обобщение на предишната
	// В предишната редовете бяха с еднаква дължина и тогава
	// нямаше нужда от допълнителен брояч
	// Тук обаче са с различна дължина и при попълване не можем да се измъкнем от допълнителния брояч
	int overallCounter = 0;
	for (int i = 0; i < numSizes; i++) {
		// Всеки ред ще има толкова елементи, колкото е голямо i-тото парче, на което ще разбиваме
		staircase[i] = new int[sizes[i]];

		// Това е същата логика, като миналата задача
		// Просто наслагваме последователно елементите от масива в двумерния масив
		for (int j = 0; j < sizes[i]; j++) {
			staircase[i][j] = pool[overallCounter++];
		}
	}

	// Сега ще сортираме staircase по размера на редовете му
	selectionSort(staircase, sizes, numSizes);
	return staircase;
}

int main() {
	int* sizes = new int[] {2, 5, 4, 7, 1};
	int* pool = new int[] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19};

	int** staircase = subdivide(pool, 19, sizes, 5);

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < sizes[i]; j++) {
			std::cout << staircase[i][j] << " ";
		}
		std::cout << std::endl;
	}

	for (int i = 0; i < 5; i++) {
		delete[] staircase[i];
	}
	delete[] staircase;
	delete[] sizes;
	delete[] pool;
}