#include <stdio.h>

char lower(char c)
{
  return (c >= 'A' && c <= 'Z') ? (c - 'A' + 'a') : c;
}

int main(void)
{
  for (int i = 'A'; i <= 'z'; i++) {
    printf("%c", lower(i));
    printf("%c", (i != 'z') ? ' ' : '\n');
  }
  return 0;
}
