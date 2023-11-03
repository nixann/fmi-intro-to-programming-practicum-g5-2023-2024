#include <iostream>

const int MAX_SIZE = 1024;

void read_array(int* arr, unsigned arr_size) {
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

bool has_duplicates(int* arr, unsigned arr_size) {
  for (int i = 0; i < arr_size - 1; i++) {
    for (int j = i + 1; j < arr_size; j++) {
      if (arr[i] == arr[j]) {
        return true;
      }
    }
  }

  return false;
}

int main() {
  int arr[MAX_SIZE];

  unsigned arr_size = read_array_size(MAX_SIZE);

  read_array(arr, arr_size);

  if (has_duplicates(arr, arr_size)) {
    std::cout << "The array has duplicates" << std::endl;
  }
  else {
    std::cout << "The array does not have duplicates" << std::endl;
  }

  return 0;
}