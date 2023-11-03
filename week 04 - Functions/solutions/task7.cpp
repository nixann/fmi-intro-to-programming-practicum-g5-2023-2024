#include <iostream>

unsigned transformToBase10(unsigned x, unsigned y) {
	unsigned result = 0;
	unsigned powOfY = 1;
	while (x) {
		result += powOfY * (x % 10);
		powOfY *= y;
		x /= 10;
	}
	return result;
}

unsigned transformFromBase10(unsigned x, unsigned z) {
	unsigned powOf10 = 1;
	unsigned result = 0;
	while (x) {
		result += powOf10 * (x % z);
		x = x / z;
		powOf10 *= 10;
	}
	return result;
}

unsigned transformNumber(unsigned x, unsigned y, unsigned z) {

	// transformToBase10(x, y) връща числото x от y-ична в 10-ична бройна система
	// transformFromBase10(x, z) връща числото x от 10-ична в z-ична бройна система
	return transformFromBase10(transformToBase10(x, y), z);
}

int main() {
	unsigned x, y, z;

	std::cin >> x >> y >> z;

	// Валидация на входа
	if (y < 2 || y > 10 || z < 2 || z > 10) throw std::invalid_argument("Invalid input");

	// Сега ще проверим дали x е валидно число в бройната система y
	unsigned temp = x;
	while (temp) {
		// Няма как някоя цифра на число в y-ична бройна система да е поне колкото y
		if (temp % 10 >= y) throw std::invalid_argument("Invalid input");
		temp /= 10;
	}

	// Може ако пробвате за някои по-големи числа да не излезе правилен отговор
	// Това се получава, защото променливите започват да се препълват, тъй като в 4 байта не могат да се поберат страшно големи числа
	// За да работи програмата с повече числа, може навсякъде да се смени типът от unsigned на unsigned long long, който побира 8 байта
	std::cout << x << " in base " << y << " is equal to " << transformNumber(x, y, z) << " in base " << z;
}