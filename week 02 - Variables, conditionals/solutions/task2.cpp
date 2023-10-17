#include <iostream>


int main() {
  int n;
  char c;

  std::cout << "ENTER N" << std::endl;

  std::cin >> n;


  std::cout << "ENTER C" << std::endl;

  std::cin >> c;


  std::cout << char(c + n) << std::endl;
  return 0;
}