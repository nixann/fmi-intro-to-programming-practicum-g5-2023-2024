﻿#include <iostream>

// Тази функция проверява дали след като сме записали цифра на дадена клетка, 
// судокуто е валидно или не
bool isGood(int i, int j, char board[][9]) {
    // Проверка дали има повторение по същата колона
    for (int row = 0; row < 9; row++) {
        if (row != i && board[row][j] == board[i][j]) return false;
    }

    // Проверка дали има повторение по същия ред
    for (int col = 0; col < 9; col++) {
        if (col != j && board[i][col] == board[i][j]) return false;
    }

    // Проверка дали има повторение в същата 3х3 кутия
    
    // Това са координатите на горния ляв край на кутията
    int boxRow = 3 * (i / 3);
    int boxCol = 3 * (j / 3);
    for (int boxRowOffset = 0; boxRowOffset < 3; boxRowOffset++) {
        for (int boxColOffset = 0; boxColOffset < 3; boxColOffset++) {
            if ((boxRow + boxRowOffset != i || boxCol + boxColOffset != j)
                && board[boxRow + boxRowOffset][boxCol + boxColOffset] == board[i][j]) return false;
        }
    }
    return true;
}

bool solve(int i, int j, char board[][9]) {
    // Ако сме свършили със судокуто, вече е решено
    if (i > 8) return true;

    // Ако не сме на празно квадратче, отиваме на следващата позиция
    // Обхождаме судокуто ред по ред
    if (board[i][j] != '.') {
        i = i + (j + 1) / 9;
        j = (j + 1) % 9;
        return solve(i, j, board);
    }

    // Ще проверим за всяка цифра дали ако я сложим на текущата позиция, 
    // след това ще получим решение
    for (int num = 1; num <= 9; num++) {
        board[i][j] = '0' + num;

        // За да е валидно текущото решение,
        // трябва текущата цифра да не нарувашава правилата на судоку
        // и също така да можем нататък да попълним судокуто
        if (isGood(i, j, board) && solve(i, j, board)) return true;

        // Причината да връщаме булеви стойности е, че
        // ако намерим валидно решение, не искаме след това да тръгнем да търсим друго
        // и да променяме вече вярното судоку, а директно се връщаме назад към началото
    }
    // !!!
    // Това е ключово
    // Ако на някоя позиция забием и не намерим цифра, с която да продължим,
    // значи, сме объркали някъде преди това и трябва да се върнем назад и да се поправим
    // Ако го няма този ред, то board[i][j] ще бъде равно на '9' и има вероятност
    // като се върнем назад, това че сме оставили тази девятка да развали и решението, което иначе би било вярно
    // т.е. все едно "почистваме" след себе си
    board[i][j] = '.';
    return false;
}

void solveSudoku(char board[][9]) {
    bool res = solve(0, 0, board);
}

int main() {
    char sudoku[][9] = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };
    //char sudoku[][9] = {
    //    {'.', '.', '.', '2', '.', '.', '.', '6', '3'},
    //    {'3', '.', '.', '.', '.', '5', '4', '.', '1'},
    //    {'.', '.', '1', '.', '.', '3', '9', '8', '.'},
    //    {'.', '.', '.', '.', '.', '.', '.', '9', '.'},
    //    {'.', '.', '.', '5', '3', '8', '.', '.', '.'},
    //    {'.', '3', '.', '.', '.', '.', '.', '.', '.'},
    //    {'.', '2', '6', '3', '.', '.', '5', '.', '.'},
    //    {'5', '.', '3', '7', '.', '.', '.', '.', '8'},
    //    {'4', '7', '.', '.', '.', '1', '.', '.', '.'}
    //};
    solveSudoku(sudoku);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            std::cout << sudoku[i][j] << ' ';
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}