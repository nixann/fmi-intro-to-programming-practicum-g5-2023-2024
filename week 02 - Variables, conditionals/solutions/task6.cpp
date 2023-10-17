
#include <iostream>


int main() {
  int a, b, c;

  std::cout << "ENTER A" << std::endl;
  std::cin >> a;

  std::cout << "ENTER B" << std::endl;
  std::cin >> b;

  std::cout << "ENTER C" << std::endl;
  std::cin >> c;


  if (a + b > c && a + c > b && b + c > a) {
    std::cout << "THE SIDES LENGHTS ARE VALID" << std::endl;
  }
  else {
    std::cout << "THE SIDES LENGHTS ARE NOT VALID" << std::endl;
  }
  return 0;
}