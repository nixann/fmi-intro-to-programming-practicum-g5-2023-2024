﻿#include <iostream>

int main() {
	/*
	Условието за допълнителната подточка на 7-ма не е правилно написано в заданието(В главното repo на групата вече е оправено)
	Първоначалната ми идея беше програмата да връща дали n съдържа всички цифри от 0 до 9 включително.
	Разбира се, тази подточка не е съществена като знания за курса и е само за хора, на които им е интересно как може да се направи чрез побитови операции.
	Ето го и кода за поправеното условие:
	*/

	unsigned n;
	std::cin >> n;

	unsigned mask = 0;
	while (n) {
		// Тук напр. ако n съдържа 5, то ние вдигаме 5-тия бит отдясно наляво в двоичния запис на променливата mask
		mask = mask | (1 << (n % 10));
		n /= 10;
	}
	// Ако n съдържа всички цифри от 0 до 9, то накрая mask ще има следния двоичен запис: 000...0001111111111
	// Това са много нули + 10 единици накрая, отговарящи на това, че сме срещнали 10-те цифри от 0 до 9 в n
	// Ако се замислите, това число всъщност е 2^10 - 1
	std::cout << ((mask == (1 << 10) - 1) ? "Has all digits" : "Does not have all digits") << std::endl;


	/*
	Оригиналното условие(тоест дали n има различни цифри) също може да се реши само чрез 1 помощна променлива. Ето как може да стане за тези, на които им е любопитно:
	*/

	unsigned n;
	std::cin >> n;

	unsigned mask = 0;
	while (n) {
		// Тук ако се опитаме да сетнем вече сетнат бит, то XOR ще ни го занули
		// Тогава винаги ще бъде вярно, че новото число е по-малко от старото и можем това да го засечем
		if ((mask ^ (1 << (n % 10))) < mask) {
			std::cout << "Not with unique digits" << std::endl;
			return 0;
		}
		mask = mask ^ (1 << (n % 10));
		n /= 10;
	}
	std::cout << "With unique digits" << std::endl;
}