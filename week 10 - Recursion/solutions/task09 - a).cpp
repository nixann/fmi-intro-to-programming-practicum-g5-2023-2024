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
	int i = 0;
	// Ако сме в този случай, преди средната операция имаме скобуван израз
	// Тогава трябва да намерим неговия край и точно след него е търсената операция

	// ! Първата обратна скоба невинаги е краят на скобуван израз
	// Напр: ((5 + 3) / 2) - тук първата скоба ')' е краят на вложения скобуван израз, а не на най-външният

	// Идеята е да броим отварящите и затварящите скоби и ако се изравнят, значи сме стигнали края на най-външните скоби
	// Помислете защо това работи (разпишете си примерчета, за да се убедите)

	int numOpening = 0;
	while (i < length) {
		if (expr[i] == '(') {
			numOpening++;
		}
		else if (expr[i] == ')') {
			numOpening--;
			// Ако са се изравнили, спираме да броим
			if (!numOpening) break;
		}
		i++;
	}
	// Връщаме i + 2, защото в момента expr[i] == ')', т.е. трябва да изместим с 1, за да отидем на интервала,
	// и с още 1, за да отидем на индекса на операцията
	return i + 2;
}

double evalExpr(const char* expr, int length) {
	// Всеки израз е скобуван, значи трябва първо да махнем двете външни скоби
	expr += 1;
	length -= 2;

	// Дъно - ако нямаме операция т.е. ако имаме число
	if (!hasOp(expr, length)) {
		// Конвертиране на низ към число (можеше да се ползва и atoi)
		return getNumber(expr, length);
	}

	// Ако сме тук, значи не сме уцелили дъното => имаме някаква операция
	// Трябва сега да намерим "средната" операция, т.е. тази, която не е в скоби
	// и тогава ще можем да разцепим израза на 2, извиквайки рекурсивно оценката на двете части отляво и отдясно
	// Не можеше директно да вземем първата срещната операция, защото тя може да се среща в първия аргумент
	// Напр: (3 + 5) - 7: първата срещната операция е +, а ние искаме да разцепим спрямо -
	// С други думи изразът изглежда така: (...) + (...) - и сега викаме функцията да оцени двата скобувани израза отляво и отдясно
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
	std::cout << eval("(((8) / ((3) + (2))) + ((25) - ((3) * (9))))") << std::endl;
}