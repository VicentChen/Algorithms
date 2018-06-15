// ------ 浙大 - EXCEL排序 ------- //
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cstring>

using namespace std;

struct Student {
  int no;
  int score;
  string name;
};
Student s[100000];

bool C1(Student &s1, Student &s2) {
  return s1.no < s2.no;
}

bool C2(Student &s1, Student &s2) {
  return s1.name.compare(s2.name) <= 0;
}

bool C3(Student &s1, Student &s2) {
  if (s1.score == s2.score) return s1.no < s2.no;
  else return s1.score <= s2.score;
}

int main(int argc, char const *argv[]) {

  int N; // number of record
  int C; // sort type

  while (cin >> N >> C) {
    // N = 0 end program
    if (N == 0) break;

    // input
    for (int i = 0; i < N; i++) {
      cin >> s[i].no >> s[i].name >> s[i].score;
    }
    
    // sort
    if (C == 1) {
      sort(s, s+N, C1);
    }
    else if (C == 2) {
      sort(s, s+N, C2);
    }
    else if (C == 3) {
      sort(s, s+N, C3);
    }

    // output
    cout << "Case:" << endl;
    for (int i = 0; i < N; i++) {
      cout << setfill('0') << setw(6) << s[i].no;
      cout << ' ' << s[i].name << ' ' << s[i].score << endl;
    }
  }

  return 0;
}
