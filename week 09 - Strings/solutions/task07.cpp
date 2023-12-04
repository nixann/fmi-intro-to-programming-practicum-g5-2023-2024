#include <iostream>
#include <cstring>

// Тази функция е ако dest и src са статични
void concat(char* dest, char* src) {
	int startingIndex = std::strlen(dest);
	int i = 0;
	do {
		dest[startingIndex + i] = src[i];
		i++;
	} while (src[i]);
}

// Тази функция е ако dest и src са динамични
void dynamicConcat(char*& dest, char* src) {
	int length1 = std::strlen(dest);
	int length2 = std::strlen(src);

	// Идеята е да си заделим нов низ с правилната дължина и после да го присвоим на dest
	int newLength = length1 + length2 + 1;
	char* result = new char[newLength]();

	// Копираме 2-та низа последователно в result
	for (int i = 0; i < length1; i++) {
		result[i] = dest[i];
	}
	for (int i = 0; i < length2; i++) {
		result[length1 + i] = src[i];
	}

	// Същият трик като преоразмеряването
	delete[] dest;
	dest = result;
}

int main() {
	char* dest1 = new char[] {"con"};
	char* src1 = new char[] {"catenate"};

	char dest2[10] = "pre";
	char src2[] = "dicate";

	dynamicConcat(dest1, src1);
	concat(dest2, src2);

	std::cout << dest1 << std::endl;
	std::cout << dest2 << std::endl;
	delete[] dest1;
	delete[] src1;
}