
#include <iostream>


int main() {
  int n;

  std::cout << "ENTER N" << std::endl;
  std::cin >> n;

  // броя числа от 1 до n, които се делят на 7
  int k = n / 7;

  // броя числа от 1 до n, които се делят на 7 и на 3 (21 е НОД на 7 и 3)
  int p = n / 21;

  // броя числа от 1 до n, които се делят на 7 и на 8 (56 е НОД на 7 и 8)
  int q = n / 56;

  // Вадим от броя числа, които се делят на 7, броя на тези, които се делят едновременно на 7 и на 3, както и броя на тези, които се делят едновременно на 7 и на 8
  int count = k - p - q;


  std::cout << "COUNT: " << count << std::endl;
  return 0;
}