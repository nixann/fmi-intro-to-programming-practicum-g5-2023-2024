#include <iostream>
#include <iomanip>
#include <cstring>

// left започва от началото на думата и се движи надясно
// right започва от края на думата и се движи наляво
// На всеки ход трябва символите на позиции left и right да са равни, за да имаме палиндром
bool helper(const char* str, int left, int right) {
	// Ако левият индекс е равен на десния, ние сме точно на средата на думата (ако тя е с нечетна дължина)
	// Ако левият индекс е по-голям от десния, ние сме минали "двете среди" на дума, която е с четна дължина
	if (left >= right) return true;
	if (str[left] != str[right]) return false;
	return helper(str, left + 1, right - 1);
}

bool isPalindrome(const char* str) {
	return helper(str, 0, std::strlen(str) - 1);
}

int main() {
	std::cout << std::boolalpha << isPalindrome("racecar") << std::endl;
	std::cout << std::boolalpha << isPalindrome("abba") << std::endl;
	std::cout << std::boolalpha << isPalindrome("abaa") << std::endl;
}