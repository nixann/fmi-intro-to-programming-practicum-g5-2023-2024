#include <iostream>
#include <cstdlib>
#include <ctime>

int getRandom(int min, int max) {
    srand(time(0));
    return min + (rand() % (max - min + 1));
}

int pow(int base, int exp) {
    int res = 1;
    for (int i = 0; i < exp; i++) {
        res *= base;
    }
    return res;
}

bool hasDifferentDigits(int n) {
    bool seen[10] = {};
    
    while (n) {
        if (seen[n % 10]) return false;
        seen[n % 10] = true;
        n /= 10;
    }
    return true;
}

// Тук имаме референции, за да може промяната на променливите да се отрази в main функцията
// Можеше да се използват и указатели
void handleGuess(int guess, int mysteryNum, int& bullCounter, int& cowCounter) {
    // Ето каква е логиката:
    //      Имаме 2 масива, които ще съхраняват коя цифра къде се среща в съответното число:
    //          guessIndices[5] == 0 -> Цифрата 6 не се среща в числото guess
    //          guessIndices[5] == 3 -> Цифрата 6 се среща в 3-тата цифра отдясно наляво
    // Аналогично е и за масива mysteryIndices
    
    // Ще имаме бик, когато и в двата масива съответната цифра се среща и ако се среща на еднаква позиция
    // Примерно ако guessIndices[5] != 0 && guessIndices[5] == mysteryIndices[5], то
    // това ни казва, че цифрата 6 се среща както в guess, така и в mysteryNum и е на една и съща позиция
    // За крава пък е достатъчно само guessIndices[5] != 0 && mysteryIndices[5] != 0
    // Тоест когато и в двете числа се среща цифрата 6

    int guessIndices[10] = {};
    int mysteryIndices[10] = {};
    
    for (int index = 1; guess; index++) {
        guessIndices[guess % 10] = index;
        mysteryIndices[mysteryNum % 10] = index;
        guess /= 10;
        mysteryNum /= 10;
    }

    for (int i = 0; i < 10; i++) {
        if (guessIndices[i] != 0 && guessIndices[i] == mysteryIndices[i]) {
            bullCounter++;
        }
        else if (guessIndices[i] != 0 && mysteryIndices[i] != 0) {
            cowCounter++;
        }
    }
}

int main() {
    int n;
    std::cin >> n;

    int mysteryNumber;
    int correctDigitInterval = pow(10, n - 1);
    do {
        // Генерираме число в интервала [10^(n-1), (10^n) - 1]
        // То е гарантирано да има n на брой цифри
        mysteryNumber = getRandom(correctDigitInterval, correctDigitInterval * 10 - 1);

    } while (!hasDifferentDigits(mysteryNumber));
    // Циклим, докато успешно генерираме число с различни цифри

    int i = 1;
    for(; i <= n; i++) {
        int guess;
        std::cin >> guess;

        int bullCounter = 0, cowCounter = 0;
        handleGuess(guess, mysteryNumber, bullCounter, cowCounter);

        if (bullCounter == n) {
            std::cout << "You correctly guessed the number!" << std::endl;
            break;
        }

        std::cout << "Number of bulls: " << bullCounter << std::endl;
        std::cout << "Number of cows: " << cowCounter << std::endl;
    }
    if (i == n + 1) {
        std::cout << "You lose. The mystery number was: " << mysteryNumber << std::endl;
    }
}