#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXOP 100
#define NUMBER '0'
#define LONG_COMMAND '~'

int getop(char []);
void push(double);
double pop(void);
double peek(void);
void clear(void);
void handle_long_command(char command[]);
void var_set(char var_name, double value);
double var_get(char var_name);

double last_printed = 0.0;

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

void handle_long_command(char command[]) {
  if (strncmp(command, "set", 3) == 0) {
    var_set(command[3], pop());
  } else if (strncmp(command, "get", 3) == 0) {
    push(var_get(command[3]));
  } else if (strcmp(command, "last") == 0) {
    push(last_printed);
  } else if (strcmp(command, "duplicate") == 0) {
    push(peek());
  } else if (strcmp(command, "swap") == 0) {
    double op1, op2;
    op1 = pop();
    op2 = pop();
    push(op1);
    push(op2);
  } else if (strcmp(command, "clear") == 0) {
    clear();
  } else if (strcmp(command, "sin") == 0) {
    push(sin(pop()));
  } else if (strcmp(command, "cos") == 0) {
    push(cos(pop()));
  } else if (strcmp(command, "tan") == 0) {
    push(tan(pop()));
  } else if (strcmp(command, "exp") == 0) {
    push(exp(pop()));
  } else if (strcmp(command, "pow") == 0) {
    double op2 = pop();
    push(pow(pop(), op2));
  } else {
    printf("error: unknown long command %s\n", command);
  }
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

double peek(void) {
  if (sp > 0)
    return val[sp - 1];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

void clear(void) {
  sp = 0;
}

double variables[256];

void var_set(char var_name, double value) {
  variables[var_name] = value;
}

double var_get(char var_name) {
  return variables[var_name];
}

#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[]) {
  int i, c;
  i = 0;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;
  if (c == '\n')
    return c;
  while ((c = getch()) && c != ' ' && c != '\n' && c != EOF)
    s[++i] = c;
  if (c != EOF)
    ungetch(c);
  s[i + 1] = '\0';

  if ((strlen(s) > 1 && isdigit(s[1])) || isdigit(s[0])) {
    return NUMBER;
  } else if (strlen(s) > 1) {
    return LONG_COMMAND;
  } else {
    return s[0];
  }
}

#define BUFSIZE 100

int buf = -1;

int getch(void) {
  if (buf == -1) {
    return getchar();
  } else {
    int tmp = buf;
    buf = -1;
    return tmp;
  }
}

void ungetch(int c) {
  if (c == EOF)
    printf("ungetch: can't push back EOF\n");
  else if (buf != -1)
    printf("ungetch: already storing a character\n");
  else
    buf = c;
}
