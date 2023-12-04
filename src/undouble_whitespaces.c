#include <stdio.h>

typedef enum {
  false = (1 == 0),
  true = !false
} bool;

int main(void)
{
  char c;

  bool was_space = false, was_tab = false, was_newline = false;

  while ((c = getchar()) != EOF) {
    if (was_space && c == ' ') {
      continue;
    } else if (was_tab && c == '\t') {
      continue;
    } else if (was_newline && c == '\n') {
      continue;
    } else {
      if (c == ' ') {
        was_space = true;
      }
      else if (c == '\t') {
        was_tab = true;
      } else if (c == '\n') {
        was_newline = true;
      } else {
        was_space = false; was_tab = false; was_newline = false;
      }

      printf("%c", c);
    }
  }
  
  return 0;
}
