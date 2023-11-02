#include <iostream>

int main() {
	char operation;
	double result = 0;

	double nextNumber;
	std::cout << "Enter an operation and a number: ";
	std::cin >> operation;

	while(operation != 'q') {

		// Тук въвеждаме следващото число от потребителя, след като знам, че операцията е валидна
		// По този начин, ако операцията е невалидна, не се изисква въвеждане на число
		switch (operation) {
			case '+':
				std::cin >> nextNumber;
				result = result + nextNumber; 
				break;

			case '-':
				std::cin >> nextNumber;
				result = result - nextNumber;
				break;

			case '*':
				std::cin >> nextNumber;
				result = result * nextNumber;
				break;

			case '/':
				std::cin >> nextNumber;
				if (nextNumber == 0) throw std::invalid_argument("Division by 0");
				result = result / nextNumber;
				break;

			default:
				throw std::invalid_argument("Invalid operation");
				break;

		}
		std::cout << "Current result: " << result << std::endl;

		std::cout << "Enter an operation and a number: ";
		std::cin >> operation;
	}
}