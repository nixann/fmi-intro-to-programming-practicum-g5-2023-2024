#include <iostream>


int main() {
  int a, b, c;

  std::cout << "ENTER A" << std::endl;
  std::cin >> a;

  std::cout << "ENTER B" << std::endl;
  std::cin >> b;

  std::cout << "ENTER C" << std::endl;
  std::cin >> c;

  if (a < b && a < c) {
    std::cout << "THE MIN NUMBER IS A: " << a << std::endl; 
  }
  else if (b < a && b < c) {
    std::cout << "THE MIN NUMBER IS B: " << b << std::endl; 
  }
  else {
    std::cout << "THE MIN NUMBER IS C: " << c << std::endl; 
  }

  return 0;
}