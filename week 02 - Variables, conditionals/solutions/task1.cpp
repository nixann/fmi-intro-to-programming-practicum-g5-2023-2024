#include <iostream>


int main() {
  int year;

  std::cout << "ENTER YEAR" << std::endl;

  std::cin >> year;


  bool is_leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

  if (is_leap) {
    std::cout << "THE YEAR IS LEAP" << std::endl;
  }
  else {
    std::cout << "THE YEAR IS NOT LEAP" << std::endl;
  }
  return 0;
}