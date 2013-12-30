#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define NUMBER '0'
#define MAXOP 100

int getop(char []);
void push(double);
double pop(void);

char **commands;

int main(int argc, char **argv) {
  int type;
  double op2;
  char s[MAXOP];

  commands = &argv[1];

  while ((type = getop(s)) != EOF) {
    switch (type) {
      case NUMBER:
        push(atof(s));
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
      default:
        printf("error: unknown command %s\n", s);
        break;
    }
  }
  printf("\t%.8g\n", pop());
  return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f) {
  if (sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n", f);
}

double pop(void) {
  if (sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

int getop(char s[]) {
  if (*commands == NULL)
    return EOF;
  strcpy(s, *commands++);

  if ((strlen(s) > 1 && isdigit(s[1])) || isdigit(s[0])) {
    return NUMBER;
  } else {
    return s[0];
  }
}
