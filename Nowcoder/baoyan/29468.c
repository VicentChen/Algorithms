// ------ 上交 - 日期差值 ------- //
#include <stdio.h>

#define IS_LEAP(year) (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? 1 : 0)

int month_acc_table[2][14] = {
  0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365, // flat
  0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366  // leap
};

typedef struct {
  int Y; int M; int D;
} Date;

int diffFirstDay(Date d) {
  // year
  d.Y -= 1;
  int leap_count = d.Y / 4 - d.Y / 100 + d.Y / 400;
  int accY = 365 * d.Y + leap_count;
  d.Y += 1;

  // month;
  int accM = month_acc_table[IS_LEAP(d.Y)][d.M];

  // day;
  int accD = d.D;
  return accY + accM + accD;
}

int main(int argc, char const *argv[]) {
  int d1, d2;
  Date begin, end; int diff;
  while(scanf("%d%d", &d1, &d2) == 2) {

    begin.Y = d1 / 10000;  end.Y = d2 / 10000;
    d1 %= 10000;           d2 %= 10000;
    begin.M = d1 / 100;    end.M = d2 / 100;
    d1 %= 100;             d2 %= 100;
    begin.D = d1;          end.D = d2;

    diff = diffFirstDay(end) - diffFirstDay(begin) + 1;
    printf("%d\n", diff);
  }
  return 0;
}
