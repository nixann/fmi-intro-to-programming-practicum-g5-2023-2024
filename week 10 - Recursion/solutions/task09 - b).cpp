#include <iostream>

bool hasOp(const char* expr, int length) {
	for (int i = 0; i < length; i++) {
		if (expr[i] == '+' || expr[i] == '-' || expr[i] == '/' || expr[i] == '*') return true;
	}
	return false;
}

double getNumber(const char* expr, int length) {
	double res = 0;
	for (int i = 0; i < length; i++) {
		int digit = expr[i] - '0';
		res = res * 10 + digit;
	}
	return res;
}

int findOp(const char* expr, int length) {
	// Единственото нещо, което променяме тук е как намираме "средната" операция
	// Тук вече не е гарантирано, че изразът, който искаме да прескочим е скобуван (може да е само число)
	// Значи просто предварително трябва да проверим дали имаме число или някакъв скобуван израз

	// Имаме скоба -> имаме скобуван израз, т.е. можем да си преизползваме кода от миналата подточка
	if (*expr == '(') {
		int i = 0;

		int numOpening = 0;
		while (i < length) {
			if (expr[i] == '(') {
				numOpening++;
			}
			else if (expr[i] == ')') {
				numOpening--;
				if (!numOpening) break;
			}
			i++;
		}
		return i + 2;
	}
	// Нямаме скоба -> имаме число. В този случай е достатъчно да намерим първата срещната операция
	int i = 0;
	for (; expr[i] != '+' && expr[i] != '-' && expr[i] != '*' && expr[i] != '/'; i++) {}
	return i;
}

double evalExpr(const char* expr, int length) {

	if (!hasOp(expr, length)) {
		return getNumber(expr, length);
	}

	// Махаме външните скоби този път само ако имаме операция, защото в тази подточка самите числа не са заградени със скоби
	expr += 1;
	length -= 2;

	int opIndex = findOp(expr, length);
	char op = expr[opIndex];

	double leftEval = evalExpr(expr, opIndex - 1);
	double rightEval = evalExpr(expr + opIndex + 2, length - (opIndex - 1) - 3);
	switch (op) {
	case '+':
		return leftEval + rightEval;
	case '*':
		return leftEval * rightEval;
	case '/':
		return leftEval / rightEval;
	case '-':
		return leftEval - rightEval;
	default:
		throw std::runtime_error("Invalid operation");
	}
}

double eval(const char* expr) {
	return evalExpr(expr, std::strlen(expr));
}

int main() {
	std::cout << eval("((5 + (3 * ((2 - 5) / 3))) + 10)") << std::endl;
}