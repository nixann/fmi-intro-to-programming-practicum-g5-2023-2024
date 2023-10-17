
#include <iostream>
#include <cmath>


int main() {
  int a, b, c;

  std::cout << "ENTER A" << std::endl;
  std::cin >> a;

  std::cout << "ENTER B" << std::endl;
  std::cin >> b;

  std::cout << "ENTER C" << std::endl;
  std::cin >> c;

  int discriminant = b * b - 4 * a * c;

  if (discriminant < 0) {
    std::cout << "Cannot be decomposed to multipliers" << std::endl;
    return 0;
  }


  float sqrt_discriminant = sqrt(discriminant);

  float x1 = (-b + sqrt_discriminant) / 2 * a;
  float x2= (-b - sqrt_discriminant) / 2 * a;

  std::cout << "DECOMPOSITION: " << a << "(x - " << x1 << ")(x - " << x2 << ")" <<std::endl; 


  return 0;
}