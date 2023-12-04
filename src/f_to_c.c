// Print a Fahrenheit to Celsius table
#include <stdio.h>

#define UPPER 300
#define LOWER 0
#define STEP 20

float f_to_c(float fahrenheit)
{
  return (5.0 / 9.0) * (fahrenheit - 32);
}

int main(void)
{
  float fahr, celsius;

  printf("Fahrenheit to Celsius table conversion\n");
  printf("\tFahrenheit\tCelsius\n");
  for (fahr = 0.0; fahr <= UPPER; fahr += STEP) {
    printf("\t%.3f\t\t%.3f\n", fahr, f_to_c(fahr));
  }

  printf("Reverse table\n");
  printf("\tFahrenheit\tCelsius\n");
  for (fahr = 300.0; fahr >= LOWER; fahr -= STEP) {
    printf("\t%.3f\t\t%.3f\n", fahr, f_to_c(fahr));
  }

  return 0;
}
