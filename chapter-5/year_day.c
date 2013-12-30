#include <stdio.h>
#include <stdlib.h>

void month_day(
    int year, int yearday, int *pmonth, int *pday, int *err_code, char **err_str
    );
int day_of_year(int year, int month, int day, int *err_code, char **err_str);

int main(int argc, char **argv) {
  int err_code;
  char *err_str;
  if (argc == 3) {
    int year = atoi(argv[1]);
    int yearday = atoi(argv[2]);
    int month;
    int day;
    month_day(year, yearday, &month, &day, &err_code, &err_str);
    if (err_code == 0)
      printf("%d %d\n", month, day);
    else
      printf("%s\n", err_str);
  } else if (argc == 4) {
    int year = atoi(argv[1]);
    int month = atoi(argv[2]);
    int day = atoi(argv[3]);
    int result = day_of_year(year, month, day, &err_code, &err_str);
    if (err_code == 0)
      printf("%d\n", result);
    else
      printf("%s\n", err_str);
  }
}

static char daytab[2][13] = {
  {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
  {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

int day_of_year(int year, int month, int day, int *err_code, char **err_str) {
  int i, leap;
  *err_code = 0;

  if (year < 0) {
    *err_code = -1;
    *err_str = "error: year can't be negative";
    return -1;
  }
  if (month < 1) {
    *err_code = -1;
    *err_str = "error: month can't be negative or zero";
    return -1;
  }
  if (day < 1) {
    *err_code = -1;
    *err_str = "error: day can't be negative or zero";
    return -1;
  }
  if (month > 12) {
    *err_code = -1;
    *err_str = "error: month can't be greater than 12";
    return -1;
  }

  leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;

  if (day > *(*(daytab + leap) + month)) {
    *err_code = -1;
    *err_str = "error: day of month too big";
    return -1;
  }
  for (i = 1; i < month; i++)
    day += *(*(daytab + leap) + i);
  return day;
}

void month_day(
    int year, int yearday, int *pmonth, int *pday, int *err_code, char **err_str
    ) {
  int i, leap;
  *err_code = 0;

  if (year < 0) {
    *err_code = -1;
    *err_str = "error: year can't be negative";
    return;
  }
  if (yearday < 0) {
    *err_code = -1;
    *err_str = "error: year day can't be negative";
    return;
  }

  leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;

  if ((leap && yearday > 366) || (!leap && yearday > 365)) {
    *err_code = -1;
    *err_str = "error: year day too big";
    return;
  }

  for (i = 1; yearday > *(*(daytab + leap) + i); i++)
    yearday -= *(*(daytab + leap) + i);
  *pmonth = i;
  *pday = yearday;
}
