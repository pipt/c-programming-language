#include <stdio.h>
#include <ctype.h>
#include <math.h>

double atof(char *input);

int main(int argc, char **argv) {
  printf("%.16f\n", atof(argv[1]));
}

double atof(char *input) {
  double val, power, exponent;
  int i, sign, exponent_sign;

  for (i = 0; isspace(input[i]); i++)
    ;

  sign = (input[i] == '-') ? -1 : 1;
  if (input[i] == '+' || input[i] == '-')
    i++;
  for (val = 0.0; isdigit(input[i]); i++)
    val = 10.0 * val + (input[i] - '0');

  if (input[i] == '.')
    i++;
  for (power = 1.0; isdigit(input[i]); i++) {
    val = 10.0 * val + (input[i] - '0');
    power *= 10.0;
  }

  if (input[i] == 'e' || input[i] == 'E') {
    i++;
    exponent_sign = (input[i] == '-') ? -1 : 1;
    if (input[i] == '+' || input[i] == '-')
      i++;
    for (exponent = 0.0; isdigit(input[i]); i++)
      exponent = 10.0 * exponent + (input[i] - '0');
  }

  return (sign * val / power) * pow(10, exponent * exponent_sign);
}
