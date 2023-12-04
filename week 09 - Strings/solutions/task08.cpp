#include <iostream>

int non_repeating_substr_len(char* str, int start) {
  int hist[26] = {};
  int len = 0;

  for (int i = start; str[i]; i++) {
    hist[str[i] - 'a']++;
    if (hist[str[i] - 'a'] > 1) {

      return len;
    }

    len++;
  }

  return len;
}

int main() {
  int n;
  std::cin >> n;
  std::cin.ignore();

	char str[101];
	std::cin.getline(str, n + 1);

  int max_len = 0;
  for (int i = 0; str[i]; i++) {
    int current_len = non_repeating_substr_len(str, i);

    if (current_len > max_len) {
      max_len = current_len;
    }
  }

  std::cout << "Longest non repeating subst len: " << max_len << std::endl;
}