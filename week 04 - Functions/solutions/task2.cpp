#include <iostream>

// Ако тук не използвахме указатели, нямаше как да разменим стойностите на оригиналните m и n
void swap(unsigned* first, unsigned* second) {
	unsigned temporary = *first;
	*first = *second;
	*second = temporary;
}

int main() {
	unsigned m, n;
	std::cin >> m >> n;

	// Ако в условието пишеше, че m и n са неотрицателни, то тук нямаше да има нужда от валидация, защото m и n са от тип unsigned
	// Обаче в условието пише, че m и n не могат да бъдат 0
	if (!m || !n) throw std::invalid_argument("Invalid input");

	// Тъй като работим с указатели, тук подаваме адресите на m и n
	swap(&m, &n);

	std::cout << m << " " << n;
}