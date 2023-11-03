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

void print_array(int* arr, unsigned arr_size) {
  for (int i = 0; i < arr_size; i++) {
    std::cout << arr[i] << std::endl;
  }
}

void swap_elements_in_array(int* arr, int el_1_idx, int el_2_idx) {
  int temp = arr[el_1_idx];
  arr[el_1_idx] = arr[el_2_idx];
  arr[el_2_idx] = temp;
}

void sort_array(int* arr, unsigned arr_size) {
  // bubble sort
  for (int i = 0; i < arr_size - 1; i++) {
    for (int j = i + 1; j < arr_size; j++) {
      if (arr[i] > arr[j]) {
        swap_elements_in_array(arr, i, j);
      }
    }
  }
}

int main() {
  int arr[MAX_SIZE];

  unsigned arr_size = read_array_size(MAX_SIZE);

  read_array(arr, arr_size);

  sort_array(arr, arr_size);

  print_array(arr, arr_size);
  return 0;
}