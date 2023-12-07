#include <stdio.h>
#include <string.h>

int _getline(char *str, size_t size)
{
  char c;
  int i = 0;
  while ((i < size - 1) && ((c = getchar()) != EOF)) {
    if (c != '\n') {
      str[i] = c;
      i++;
    } else {
      str[i] = '\0';
      i++;
      return i;
    }
  }
}

void detab(char *to, char *from, int tabstop) // Substitutes every tab in a given c_str for the correct amount of spaces
{
  int next_tabstop = tabstop;
  size_t from_size = strlen(from);

  int to_i = 0;
  int from_i = 0;

  while (from_i < from_size) {
    if (from[from_i] != '\t') {
      to[to_i] = from[from_i];
      next_tabstop--;
      to_i++;
      from_i++;
    } else {
      for (int i = 0; i <= next_tabstop; i++) {
        to[to_i + i] = ' ';
      }
      to_i += next_tabstop;
      from_i++;
      next_tabstop = tabstop;
    }

    if (next_tabstop == 0) {
      next_tabstop = tabstop;
    }
  }

  to[to_i] = '\0';
}

#define MAX_SIZE 1000
#define TABSTOP 8

int main(void)
{
  int len = 0;
  char line[MAX_SIZE] = {0};
  char detabbed[MAX_SIZE] = {0};
  
  while ((len = _getline(line, MAX_SIZE)) > 0) {
    detab(detabbed, line, TABSTOP);
    printf("%s\n", detabbed);
  }

  return 0;
}
