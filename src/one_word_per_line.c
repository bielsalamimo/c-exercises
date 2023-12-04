#include <stdio.h>

typedef enum {
  false = (1 == 0),
  true = !false
} bool;

int main(void)
{

  bool in_word = true;
  char c;
  while ((c = getchar()) != EOF) {
    switch (c) {
    case ' ':
    case '\t':
    case '\n':
      in_word = false;
      break;
    default:
      in_word = true;
      break;
    }

    if (in_word) {
      printf("%c", c);
    } else {
      printf("\n");
    }
  }

  return 0;
}
