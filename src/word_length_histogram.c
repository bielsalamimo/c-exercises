#include <stdio.h>

#define HIST_LEN 45 // Longest word in english is 45 letters

typedef enum {
  false = (1 == 0),
  true = !false
} bool;

int main(void)
{
  char c;
  bool in_word = true;
  int word_length = 0;
  int words_hist[HIST_LEN];
  for (int i = 0; i < HIST_LEN; i++) {
    words_hist[i] = 0;
  }

  int word_lenght = 0;
  while ((c = getchar()) != EOF) {
    switch (c) {
    case ' ':
    case '\n':
    case '\t':
      in_word = false;
      break;
    default:
      in_word = true;
      break;
    }
    if (in_word) {
      word_length++;
    } else {
      if (word_length > 0) {
        words_hist[word_length]++;
      }
      word_length = 0;
    }
  }

  for (int i = 1; i < HIST_LEN; i++) {
    printf("Word length: %d | ", i);
    for (int j = 0; j < words_hist[i]; j++) {
      printf("*");
    }
    printf("\n");
  }

  return 0;
}
