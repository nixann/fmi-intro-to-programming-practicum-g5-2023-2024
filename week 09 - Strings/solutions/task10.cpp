#include <iostream>
#include <cstring>

void print_longest_and_shortest_word(char* sentence) {
  int longest_word_start = 0, longest_word_end = 0;
  int longest_word_len = 0;
  int i = 0;

  int sentence_len = strlen(sentence);
  while (i <= sentence_len) {
    int current_len = 0;
    for (int j = i; sentence[j] != ' ' && j < sentence_len; j++) {
      current_len++;
    }

    if (current_len >= longest_word_len) {
      longest_word_len = current_len;
      longest_word_start = i;
      longest_word_end = i + longest_word_len;
      
    }
    i += current_len + 1; 
  }

  for (int i = longest_word_start; i <= longest_word_end; i++) {
    std::cout << sentence[i];
  }

  std::cout << std::endl;


  int shortest_word_start = 0, shortest_word_end = 0;
  int shortest_word_len = sentence_len;
  int k = 0;

  while (k <= sentence_len) {
    int current_len = 0;
    for (int j = k; sentence[j] != ' ' && j < sentence_len; j++) {
      current_len++;
    }

    if (current_len > 0 && current_len <= shortest_word_len) {
      shortest_word_len = current_len;
      shortest_word_start = k;
      shortest_word_end = k + shortest_word_len;
    }

    k += current_len + 1; 
  }

  for (int i = shortest_word_start; i <= shortest_word_end; i++) {
    std::cout << sentence[i];
  }

  std::cout << std::endl;
}

int main() {
  int n;
  std::cin >> n;
  std::cin.ignore();

	char sentence[101];
	std::cin.getline(sentence, n + 1); 

  print_longest_and_shortest_word(sentence);
  return 0;
}


