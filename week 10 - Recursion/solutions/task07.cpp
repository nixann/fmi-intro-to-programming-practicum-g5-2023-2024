#include <iostream>

void reverse(const char* str) {
	if (!*str) return;
	// Първо обръщаме останалата част от низа и чак след това отпечатваме текущия символ
	reverse(str + 1);
	std::cout << *str;
}

int main() {
	reverse("hello! ");
	std::cout << std::endl;
	reverse("");
	std::cout << std::endl;
	reverse("racecar?");
	std::cout << std::endl;
}