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

int count_negative(int* arr, unsigned arr_size) {
  int count = 0;

  for (int i = 0; i < arr_size; i++) {
    if (arr[i] < 0) {
      count++;
    }
  }

  return count;
}

int count_positive(int* arr, unsigned arr_size) {
  int count = 0;

  for (int i = 0; i < arr_size; i++) {
    if (arr[i] >= 0) {
      count++;
    }
  }

  return count;
}

int main() {
  int arr[MAX_SIZE];

  unsigned arr_size = read_array_size(MAX_SIZE);

  read_array(arr, arr_size);

  int negative_count = count_negative(arr, arr_size);
  int positive_count = count_positive(arr, arr_size);

  if (negative_count > positive_count) {
    std::cout << "Negative numbers are more than the positive" << std::endl;
  }
  else {
    std::cout << "Negative numbers are less than the positive" << std::endl;
  }

  return 0;
}