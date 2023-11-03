#include <iostream>

const int MAX_SIZE = 1024;

void read_array(int *arr, unsigned arr_size) {
  for (int i = 0; i < arr_size; i++) {
    std::cout << "Enter element at arr[" << i << "]: " << std::endl;
    std::cin >> arr[i];
  }
}

unsigned read_array_size(const unsigned max_size) {
  unsigned arr_size;

  do {
    std::cout << "Enter array size: " << std::endl;

    std::cin >> arr_size;
  } while (arr_size > max_size);

  return arr_size;
}

bool is_member(int *arr, unsigned arr_size, int n) {
  for (int i = 0; i < arr_size; i++) {
    if (arr[i] == n)
    {
      return true;
    }
  }

  return false; 
}

int main()
{
  int arr[MAX_SIZE];
  int n;

  unsigned arr_size = read_array_size(MAX_SIZE);

  read_array(arr, arr_size);

  std::cout << "Enter n: " << std::endl;

  std::cin >> n;

  bool is_mem = is_member(arr, arr_size, n);

  if (is_mem)
  {
    std::cout << n << " is contained inside of the array " << std::endl;
  }
  else
  {
    std::cout << n << " is NOT contained inside of the array " << std::endl;
  }

  return 0;
}