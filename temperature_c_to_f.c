#include <stdio.h>

int main() {
  float fahr, celsius;
  int lower, upper, step;

  lower = 0; /* lower limit of temperature table */
  upper = 100; /* upper limit */
  step = 10; /* step size */

  celsius = lower;
  printf("Celsius Farenheit\n");
  while (celsius <= upper) {
    fahr = ((9.0 / 5.0) * celsius) + 32.0;
    printf("%7.0f %9.1f\n", celsius, fahr);
    celsius = celsius + step;
  }
}
