// ------ 清华 - 今年的第几天 ------- //
#include <stdio.h>
#include <string.h>
#define IS_LEAP(year) (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? 1 : 0)

int month_acc_table[2][14] = {
  0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365, // flat
  0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366  // leap
};

int main() {

  int Y, M, D;

  while (scanf("%d %d %d", &Y, &M, &D) == 3) {
    printf("%d\n", month_acc_table[IS_LEAP(Y)][M] + D);
  }

  return 0;
}