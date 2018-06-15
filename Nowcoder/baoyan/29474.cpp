// ------ 清华 - 成绩排序 ------- //
#include <iostream>
#include <algorithm>
 
using namespace std;
 
int type = 0;
 
struct Student {
  int score;
  char name[100];
 
  bool operator < (const Student &b) const {
    if (type)
      return score < b.score;
    else
      return score > b.score;
  }
};
 
int main(int argc, char const *argv[]) {
  int N;
  Student s[1000];
  while (scanf("%d%d", &N, &type) == 2) {
    for (int i = 0; i < N; i++) scanf("%s %d", s[i].name, &(s[i].score));
 
    stable_sort(s, s+N);
 
    for (int i = 0; i < N; i++) printf("%s %d\n", s[i].name, s[i].score);
  }
  return 0;
}