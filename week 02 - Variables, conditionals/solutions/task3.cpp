#include <iostream>


int main() {
  char c;

  std::cout << "ENTER C" << std::endl;

  std::cin >> c;


  bool is_digit = c >= '0' && c <= '9';

  if (is_digit) {
    std::cout << "THE SYMBOL IS A DIGIT" << std::endl;
  }
  else {
    std::cout << "THE SYMBOL IS NOT A DIGIT" << std::endl;
  }

  return 0;
}