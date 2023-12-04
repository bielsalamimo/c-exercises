#include <stdio.h>

int main(void)
{
  char c;

  while ((c = getchar()) != EOF) {
    switch (c) {
    case ' ':
      printf("*");
      continue;
      break;

    case '\t':
      printf("\\t");
      continue;
      break;

    case '\b':
      printf("\\b");
      continue;
      break;

    case '\\':
      printf("\\\\");
      continue;
      break;

    default:
      printf("%c", c);
      break;
    }
  }

  return 0;
}
