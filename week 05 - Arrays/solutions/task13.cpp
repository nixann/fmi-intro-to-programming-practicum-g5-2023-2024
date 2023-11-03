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

void merge_arrays(int* arr_1, unsigned arr_1_size, int* arr_2, unsigned arr_2_size, int* merged_array) {
  int i = 0, j = 0, k = 0;

  while (i < arr_1_size || j < arr_2_size) {
    if (i >= arr_1_size) {
      merged_array[k] = arr_2[j];
      k++;
      j++;
    }
    else if (j >= arr_2_size) {
      merged_array[k] = arr_1[i];
      k++;
      i++;
    }
    else {
      int current_el_1 = arr_1[i];
      int current_el_2 = arr_2[j];

      if (current_el_1 < current_el_2) {
        merged_array[k] = current_el_1;
        k++;
        i++;
      }
      else {
        merged_array[k] = current_el_2;
        k++;
        j++;
      }
    }
  }

}

int main() {
  int arr_1[MAX_SIZE];
  int arr_2[MAX_SIZE];
  int merged_array[MAX_SIZE * 2];

  std::cout << "Enter first array" << std::endl;
  unsigned arr_1_size = read_array_size(MAX_SIZE);

  read_array(arr_1, arr_1_size);

  unsigned arr_2_size = read_array_size(MAX_SIZE);

  std::cout << "Enter second array" << std::endl;
  read_array(arr_2, arr_2_size);

  merge_arrays(arr_1, arr_1_size, arr_2, arr_2_size, merged_array);

  print_array(merged_array, arr_1_size + arr_2_size);

  return 0;
}