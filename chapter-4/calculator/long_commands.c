#include <stdio.h>
#include <string.h>
#include <math.h>
#include "calc.h"

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
