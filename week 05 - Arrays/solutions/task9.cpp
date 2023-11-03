#include <iostream>

const int MAX_SIZE = 1024;

unsigned read_array_size(const unsigned max_size) {
  unsigned arr_size;

  do {
    std::cout << "Enter array size: " << std::endl;

    std::cin >> arr_size;
  } while (arr_size > max_size);

  return arr_size;
}

void read_array(char* arr, unsigned arr_size) {
  for (int i = 0; i < arr_size; i++) {
    std::cout << "Enter element at arr[" << i << "]: " << std::endl;
    std::cin >> arr[i];
  }
}

char find_missing_char(char *arr, int arr_size) {
  for (int i = 0; i < arr_size - 1; i++) {
    if (arr[i + 1] - arr[i] > 1) {
      return (char) (arr[i] + 1);
    }
  }
}

int main() {
  char arr[MAX_SIZE];
  unsigned arr_size = read_array_size(MAX_SIZE);

  read_array(arr, arr_size);

  std::cout << "The missing char is: " << find_missing_char(arr, arr_size) << std::endl;

  return 0;
}