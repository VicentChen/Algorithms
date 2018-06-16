// ------ 浙大 - 统计同成绩学生人数 ------- //
#include <iostream>
#include <cstring>

using namespace std;

int T[101];

int main(int argc, char const *argv[]) {
  int N, S;
  while (cin >> N) {
    // early end
    if (N == 0) return 0;

    // initialize T
    memset(T, 0, sizeof(T));

    // compute count
    for (int i = 0; i < N; i++) {
      cin >> S;
      T[S]++;
    }

    cin >> S; // S is the expected score
    cout << T[S] << endl;
  }
  return 0;
}
