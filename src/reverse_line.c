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

void str_reverse(char *to, char *from)
{
  size_t size = strlen(from);
  for (int i = 0; i < size; i++) {
    to[i] = from[size - 1 - i];
  }
  to[size] = '\0';
}

#define MAX_SIZE 1000

int main(void)
{
  char line[MAX_SIZE] = {0};
  char reversed[MAX_SIZE] = {0};
  int len = 0;
  while (_getline(line, MAX_SIZE) > 0) {
    str_reverse(reversed, line);
    printf("%s\n", reversed);
  }

  return 0;
}
