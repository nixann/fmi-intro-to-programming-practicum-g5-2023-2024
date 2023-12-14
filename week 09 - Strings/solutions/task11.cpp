#include <iostream>
#include <cstring>

char* join(char words[][20], int words_count, char joiner) {
  int len;

  for (int i = 0; i < words_count; i++) {
    len += strlen(words[i]);
  }

  char* result = new char[len + 1];

  for (int i = 0; i < words_count; i++) {
    strcat(result, words[i]);
    if (i < words_count - 1) {
      // това е нужно, за да можем да изполваме strcat
      char joiner_to_str[2] = {joiner, '\0'};
      strcat(result, joiner_to_str);
    }
  }

  return result;
}

int main() {
  char words[10][20];
  int words_count;

  std::cin >> words_count;

  int current_word_len;
  for (int i = 0; i < words_count; i++) {
    std::cin >> current_word_len;

    std::cin.ignore();

	  std::cin.getline(words[i], current_word_len + 1); 
  }
  

  char* result = join(words, words_count, ' ');

  for (int i = 0; result[i]; i++) {
    std::cout <<result[i];
  }
  std::cout <<std::endl;

  delete[] result;
  return 0;
}