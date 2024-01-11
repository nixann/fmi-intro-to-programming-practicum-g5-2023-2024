﻿#include <iostream>

int minNumSquares(int n, int m) {
	// Ако едната размерност на правоъгълника е 0, очевидно са нужни 0 квадрати
	if (!n || !m) return 0;

	// Ако едната размерност на правоъгълника е нечетна,
	// ние сме принудени да покрием единия ред/колона с 1х1 квадратчета
	// Защо?
	// Ами тъй като квадратчетата имат само четни дължини/ширини,
	// няма как да получим нечетно число, като ги съберем
	// Затова е нужно да покрием поне една колона с 1х1 кв. 
	// (в примера това са червените квадратчета, тъй като първоначално m е нечетно)
	if (n % 2 != 0) return m + minNumSquares(n - 1, m);
	if (m % 2 != 0) return n + minNumSquares(n, m - 1);

	// Тук идва интересната връзка - ако и двете размерности са четни
	// Оказва се, че минималният брой квадрати, за да покрием правоъгълник с четни измерения,
	// е равен на броя квадрати, с които можем да покрием една четвърт от него

	// Това може да се види по-лесно отзад напред
	// Ако имате някакъв правоъгълник вече покрит с квадратчета и 
	// ако уголемите размерите на всяко квадратче 2 пъти (представете си, че все едно upscale-вате някакво изображение)
	// то ще получите същия правоъгълник, но с двойно по-големи размери
	return minNumSquares(n / 2, m / 2);
}

int main() {
	std::cout << minNumSquares(6, 5) << std::endl;
}