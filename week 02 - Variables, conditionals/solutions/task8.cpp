
#include <iostream>

int main() {
  // координати за върховете на първия правоъгълник
  float r1_dx, r1_dy, r1_bx, r1_by;

  // координати за върховете на втория правоъгълник
  float r2_dx, r2_dy, r2_bx, r2_by;

  // first rectangle coordinates
  std::cout << "ENTER R1 DX" << std::endl;
  std::cin >> r1_dx;

  std::cout << "ENTER R1 DY" << std::endl;
  std::cin >> r1_dy;

  std::cout << "ENTER R1 BX" << std::endl;
  std::cin >> r1_bx;

  std::cout << "ENTER R1 BY" << std::endl;
  std::cin >> r1_by;


  std::cout << "ENTER R2 DX" << std::endl;
  std::cin >> r2_dx;

  std::cout << "ENTER R2 DY" << std::endl;
  std::cin >> r2_dy;

  std::cout << "ENTER R2 BX" << std::endl;
  std::cin >> r2_bx;

  std::cout << "ENTER R2 BY" << std::endl;
  std::cin >> r2_by;

  // Забелязваме, че е по-лесно да проверим отрицателните случаи, т.е. кога правоъгълниците няма да се застъпват:

  // правоъгълниците са един под друг
  if (r1_by > r2_dy || r2_by > r1_dy) {
    std::cout << "The rectangles do not overlap" << std::endl;   
  }
  // правоъгълниците са един до друг
  else if (r1_dx > r2_bx || r2_dx > r1_bx) {
    std::cout << "The rectangles do not overlap" << std::endl;   
  }
  
  else {
    std::cout << "The rectangles overlap" << std::endl;   
  }


  return 0;
}