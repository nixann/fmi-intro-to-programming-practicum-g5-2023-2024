#include <iostream>


int main() {
  char c;

  std::cout << "ENTER C" << std::endl;

  std::cin >> c;


  if (c >= '0' && c <= '9') {
    std::cout << "THE SYMBOL IS A DIGIT" << std::endl;
  }
  else if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
    std::cout << "THE SYMBOL IS A LETTER" << std::endl;
  }

  else {
    std::cout << "THE SYMBOL IS NEITHER A LETTER NOR A DIGIT" << std::endl;
  }

  return 0;
}