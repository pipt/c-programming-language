#include <stdio.h>

float farenheit_to_celsius(float fahr);

/* print Fahrenheit-Celsius table
 * for fahr = 0, 20, ..., 300 */
int main() {
  float fahr, celsius;
  int lower, upper, step;

  lower = 0; /* lower limit of temperature table */
  upper = 300; /* upper limit */
  step = 20; /* step size */

  fahr = lower;
  printf("Farenheit Celsius\n");
  while (fahr <= upper) {
    printf("%9.0f %7.1f\n", fahr, farenheit_to_celsius(fahr));
    fahr = fahr + step;
  }
}

float farenheit_to_celsius(float fahr) {
  return (5.0 / 9.0) * (fahr - 32.0);
}
