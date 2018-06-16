// ------ 上交 - Day of Week ------- //
#include <stdio.h>
#include <math.h>
#include <string.h>

#define IS_LEAP(year) (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) ? 1 : 0)

int month_acc_table[2][14] = {
  0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365, // flat
  0, 0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335, 366  // leap
};

char month_str[13][12] = {
  "", "January", "February", "March", "April", "May", "June",
  "July", "August", "September", "October", "November", "December"
};

char day_of_week_str[8][12] = {
  "", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"
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
  char M_str[12];
  Date d, today;

  // compute last Monday
  today.Y = 2018; today.M = 6; today.D = 18;
  int acc_today = diffFirstDay(today);

  while(scanf("%d %s %d", &d.D, M_str, &d.Y) == 3) {
    for (int i = 1; i < 13; i++) {
      if (strcmp(M_str, month_str[i]) == 0) {
        d.M = i; break;
      }
    }

    int diff = diffFirstDay(d) - acc_today;
    if (diff < 0) diff = 7 - (-diff % 7);
    else diff = diff % 7;

    printf("%s\n", day_of_week_str[diff % 7 + 1]);
  }
  return 0;
}
