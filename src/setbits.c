#include <stdio.h>

unsigned int set_bits(unsigned int x, int p, int n, unsigned int y)
{
  // Get n right-most bits of y
  y = ~(~0 << n) & y;
  // Shift left those n bits p-n bits
  y = y << (p-n);
  // Zero out n bits of x starting at p
  x = x & ~((~(~0 << n)) << (p - n));
  return x | y;
}

int main(void)
{
  unsigned int z = set_bits(218, 3, 3, 170);
  printf("0x%X\n", z);
  return 0;
}
