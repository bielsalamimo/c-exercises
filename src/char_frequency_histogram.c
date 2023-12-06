#include <stdio.h>

int main(void)
{
  int c;
  int hist[95] = {0};
  while ((c = getchar()) != EOF) {
    hist[c - ' ']++;
  }
  
  for (int i = 0; i < 95; i++) {

    printf("Char: %c, amount: %d  ", i + ' ', hist[i]);
    for (int j = 0; j < hist[i]; j++) {
      printf("*");
    }
    printf("\n");

  }

  return 0;
}
