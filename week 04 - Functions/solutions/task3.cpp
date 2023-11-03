#include <iostream>

int pow(int p, int n) {
	int result = 1;
	for (int i = 1; i <= n; i++) {
		result *= p;
	}
	return result;
}

int main() {
	int p, n;
	std::cin >> p;

	// Валидация на n. Цикълът ще се повтаря, докато потребителят спре да въвежда невалидни стойности за n
	do {
		std::cin >> n;
	} while (n <= 0);

	std::cout << "p^n: " << pow(p, n) << std::endl;
}