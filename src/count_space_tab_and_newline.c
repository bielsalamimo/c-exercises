#include <stdio.h>

int main(void)
{
  char c;
  int ch_count = 0, newline_count = 0, space_count = 0, tab_count = 0;

  while ((c = getchar()) != EOF) {
    ch_count++;
    if (c == '\n') {
      newline_count++;
    } else if (c == ' ') {
      space_count++;
    } else if (c == '\t') {
      tab_count++;
    }
  }

  printf("Total characters: %d\n", ch_count);
  printf("\tSpace count: %d\n", space_count);
  printf("\tTab count: %d\n", tab_count);
  printf("\tNewline count: %d\n", newline_count);

  return 0;
}
