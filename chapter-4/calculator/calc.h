#define NUMBER '0'
#define LONG_COMMAND '~'

int getop(char []);
void push(double);
double pop(void);
double peek(void);
void clear(void);
int getch(void);
void ungetch(int);
void handle_long_command(char command[]);
void var_set(char var_name, double value);
double var_get(char var_name);

double last_printed;
