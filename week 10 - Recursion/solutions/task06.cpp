#include <iostream>

int fastPow(int n, int m) {
	if (m == 0) return 1;
	if (m % 2 == 0) {
		return fastPow(n * n, m / 2);
	}
	else return n * fastPow(n * n, (m - 1) / 2);
}

int main() {
	std::cout << fastPow(6, 8) << std::endl;
}