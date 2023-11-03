#include <iostream>


const unsigned MAX_SIZE = 1024;

int find_min_index(int* arr, unsigned arr_size) {
  int min_index = 0;
  for (int i = 0; i < arr_size; i++) {
    if (arr[i] < arr[min_index]) {
      min_index = i;
    }
  }

  return min_index;
}

int find_max_index(int* arr, int arr_size) {
  int max_index = 0;
  for (int i = 0; i < arr_size; i++) {
    if (arr[i] > arr[max_index]) {
      max_index = i;
    }
  }

  return max_index;
}

float exclusive_average(int* arr, unsigned arr_size) {
  int min_index = find_min_index(arr, arr_size);
  int max_index = find_max_index(arr, arr_size);
  int sum = 0;

  if (arr_size < 3) {
    return sum;
  }

  for (int i = 0; i < arr_size; i++) {
    if (i != min_index && i != max_index) {
      sum += arr[i];
    }
  }

  return (float)sum / (arr_size - 2);
}

unsigned read_array_size(const unsigned max_size) {
  unsigned arr_size;

  do {
    std::cout << "Enter array size: " << std::endl;

    std::cin >> arr_size;
  } while (arr_size > max_size);

  return arr_size;
}

void read_array(int* arr, unsigned arr_size) {
  for (int i = 0; i < arr_size; i++) {
    std::cout << "Enter element at arr[" << i << "]: " << std::endl;
    std::cin >> arr[i];
  }
}

int main() {
  int arr[MAX_SIZE];

  unsigned arr_size = read_array_size(MAX_SIZE);

  read_array(arr, arr_size);

  std::cout << "AVG: " << exclusive_average(arr, arr_size) << std::endl;

  return 0;
}