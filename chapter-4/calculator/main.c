#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

#define MAXOP 100

int main() {
  int type;
  double op2;
  char s[MAXOP];

  while ((type = getop(s)) != EOF) {
    switch (type) {
      case NUMBER:
        push(atof(s));
        break;
      case LONG_COMMAND:
        handle_long_command(s);
        break;
      case '+':
        push(pop() + pop());
        break;
      case '*':
        push(pop() * pop());
        break;
      case '-':
        op2 = pop();
        push(pop() - op2);
        break;
      case '/':
        op2 = pop();
        if (op2 != 0.0)
          push(pop() / op2);
        else
          printf("error: zero divisor\n");
        break;
      case '%':
        op2 = pop();
        push((int) pop() % (int) op2);
        break;
      case '\n':
        last_printed = pop();
        printf("\t%.8g\n", last_printed);
        break;
      case '?':
        printf("\t%.8g\n", peek());
        break;
      default:
        printf("error: unknown command %s\n", s);
        break;
    }
  }
  return 0;
}
