
#include <iostream>


int main() {
  int a, b;

  std::cout << "ENTER A" << std::endl;
  std::cin >> a;

  std::cout << "ENTER B" << std::endl;
  std::cin >> b;

  int d1_a  = a % 10;
  int d2_a  = (a / 10) % 10;
  int d3_a  = (a / 100) % 10;
  int d4_a  = (a / 1000) % 10;

  int d1_b  = b % 10;
  int d2_b  = (b / 10) % 10;
  int d3_b  = (b / 100) % 10;
  int d4_b  = (b / 1000) % 10;

  int sum = int(d1_a > d1_b) + int(d2_a > d2_b) + int(d3_a > d3_b) + int(d4_a > d4_b);


  std::cout << "SUM: " << sum << std::endl;


  return 0;
}