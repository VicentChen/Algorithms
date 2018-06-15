// ------ 浙大 - EXCEL排序 ------- //
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
  int no;
  int score;
  char name[10];
} Student;
Student s[100000];

int C1(const void* t1, const void* t2) {
  Student s1 = *(Student*)t1;
  Student s2 = *(Student*)t2;
  return s1.no < s2.no;
}

int C2(const void* t1, const void* t2) {
  Student s1 = *(Student*)t1;
  Student s2 = *(Student*)t2;
  return strcmp(s1.name, s2.name) <= 0;
}

int C3(const void* t1, const void* t2) {
  Student s1 = *(Student*)t1;
  Student s2 = *(Student*)t2;
  if (s1.score == s2.score) return s1.no < s2.no;
  else return s1.score <= s2.score;
}

int main(int argc, char const *argv[]) {
  int N, C;
  while(scanf("%d%d", &N, &C) == 2) {
    if (N == 0) break;

    for (int i = 0; i < N; i++)
      scanf("%d %s %d", &(s[i].no), s[i].name, &(s[i].score));
    
    if (C == 1) qsort(s, N, sizeof(Student), C1);
    else if (C == 2) qsort(s, N, sizeof(Student), C2);
    else if (C == 3) qsort(s, N, sizeof(Student), C3);

    printf("Case:\n");
    for (int i = N-1; i >= 0; i--)
      printf("%06d %s %d\n", s[i].no, s[i].name, s[i].score);
  }
  return 0;
}
