#include <iostream>

bool isPrime(unsigned n) {
	if (n <= 1) return false;

	for (unsigned i = 2; i <= n / 2; i++) {
		if (n % i == 0) {
			// Ако намерим делител, директно излизаме от функцията и останалият код в нея няма да се изпълни
			return false;
		}
	}
	// Ще сме стигнали дотук само ако не сме намерили делител на n
	// В противен случай щяхме да сме приключили с тази функция още някъде по средата на цикъла и тук нямаме нужда от проверки
	return true;
}

int main() {
	unsigned a, b;
	std::cin >> a >> b;

	for (unsigned i = a; i <= b; i++) {
		if (isPrime(i)) std::cout << i << " ";
	}
	std::cout << std::endl;
}