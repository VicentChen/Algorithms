// ------ 清华 - 查找学生信息 ------- //
#include <iomanip>
#include <cstring>
#include <iostream>

using namespace std;

struct Student {
  int no;
  string no_str;
  string name;
  string sex;
  string age;

  void print() {
    cout << no_str << ' ' << name << ' ' << sex << ' ' << age << endl;
  }
};

int main(int argc, char const *argv[]) {
  int N, M;
  Student s[1000]; Student *p[1000];
  int no[10000];
  while (cin >> N) {
    memset(p, NULL, sizeof(p));
    for (int i = 0; i < N; i++) {
      cin >> s[i].no_str >> s[i].name >> s[i].sex >> s[i].age;
      s[i].no = atoi(s[i].no_str.c_str());
      p[s[i].no] = s + i;
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
      cin >> no[i];
    }
    for (int i = 0; i < M; i++) {
      if (p[no[i]] != NULL) (*p[no[i]]).print();
      else cout << "No Answer!" << endl;
    }
  }
  return 0;
}
