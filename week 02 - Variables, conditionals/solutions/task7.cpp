
#include <iostream>


int main() {
  float a, b, c;

  std::cout << "ENTER A" << std::endl;
  std::cin >> a;

  std::cout << "ENTER B" << std::endl;
  std::cin >> b;

  std::cout << "ENTER C" << std::endl;
  std::cin >> c;

  float longest_side;
  float shorter_side_1, shorter_side_2;

  if (a > b && a > c) {
    longest_side = a;
    shorter_side_1 = b;
    shorter_side_2 = c;
  }
  else if (b > a && b > c) {
    longest_side = b;
    shorter_side_1 = a;
    shorter_side_2 = c;
  }
  else {
    longest_side = c;
    shorter_side_1 = a;
    shorter_side_2 = b;
    
  }

  float short_sides_sq_sum = shorter_side_1 * shorter_side_1 + shorter_side_2 * shorter_side_2;
  float longest_side_sq = longest_side * longest_side;
  if (short_sides_sq_sum == longest_side_sq) {
    std::cout << "The triangle is right angled" << std::endl;
  }
  else if (short_sides_sq_sum > longest_side_sq) {
    std::cout << "The triangle is acute angled" << std::endl;
  }
  else {
    std::cout << "The triangle is obtuse angled" << std::endl;
  }
  return 0;
}