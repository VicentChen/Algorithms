// ------ 华科 - 打印日期 ------- //
#include <stdio.h>
#include <string.h>

#define IS_LEAP(year) \
  (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? 1 : 0)

int month_acc_table[2][14] = {
    0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365,  // flat
    0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366   // leap
};

int main(int argc, char const *argv[]) {
  int Y, M, D, N;
  while (scanf("%d %d", &Y, &N) == 2) {
    int* M_acc_table = month_acc_table[IS_LEAP(Y)];
    for (M = 1; N > M_acc_table[M]; M++); // find M
    D = N - M_acc_table[--M]; // find D
    printf("%4d-%02d-%02d\n", Y, M, D);
  }
  return 0;
}
