
#include <iostream>


int main() {
  int n;

  std::cout << "ENTER N" << std::endl;
  std::cin >> n;

  int sum = n * (n + 1) / 2;


  std::cout << "SUM: " << sum << std::endl;
  return 0;
}