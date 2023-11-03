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

int longest_arithmetic_progression_len(int* arr, unsigned arr_size, int d) {
  int longest_len = 1;
  for (int i = 0; i < arr_size - 1; i++) {
    int current_len = 1;
    int j = i + 1;
    while (j < arr_size && arr[j] == arr[j - 1] + d) {
      current_len++;
      j++;
    }

    if (current_len > longest_len) {
      longest_len = current_len;
    }
  }

  return longest_len;
}

int main() {
  int arr[MAX_SIZE];
  int d;

  unsigned arr_size = read_array_size(MAX_SIZE);

  read_array(arr, arr_size);

  std::cout << "ENTER d: " << std::endl;
  std::cin >> d;

  int longest_length = longest_arithmetic_progression_len(arr, arr_size, d);

  std::cout << "The longest arithmetic progression has length: " << longest_length << std::endl;
  return 0;
}