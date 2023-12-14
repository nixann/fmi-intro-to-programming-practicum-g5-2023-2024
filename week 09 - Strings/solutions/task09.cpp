#include <iostream>

int common_substr_len(char* str_1, int start, char* str_2) {
  int len = 0;

  int start_2 = -1;

  for (int j = 0; str_2[j]; j++) {
    if (str_2[j] == str_1[start]) {
      start_2 = j;
    }
  }

  if (start_2 == -1) {
    return 0;
  }

  while (str_1[start] && str_2[start_2] && str_1[start] == str_2[start_2]) {
    len++;
    start++;
    start_2++;
  }

  return len;
}

char* longest_common_substr(char* str_1, char* str_2) {
  int max_len = 0;
  int substr_start = -1;
  for (int i = 0; str_1[i]; i++) {
    int current_len = common_substr_len(str_1, i, str_2);

    if (current_len > max_len) {
      max_len = current_len;
      substr_start = i;
    }
  }

  char* result = new char[max_len + 1];

  int k = 0;
  if (substr_start != -1) {
    for (int i = substr_start; i <= max_len; i++) {
      result[k++] = str_1[i];
    }
  }

  return result;
}

int main() {
  int n;
  std::cin >> n;
  std::cin.ignore();

	char str_1[101];
	std::cin.getline(str_1, n + 1);

  std::cin >> n;
  std::cin.ignore();
  char str_2[101];
	std::cin.getline(str_2, n + 1);

  char* result = longest_common_substr(str_1, str_2);

  for (int i = 0; result[i]; i++) {
    std::cout << result[i];
  }

  std::cout << std::endl;

  delete[] result;
}