// ------ 北邮 - 查找 ------- //
#include <iostream>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
  int N, M;
  int a[100], b[100];
  int l, r, m, t;

  while (cin >> N) {
    // input
    for (int i = 0; i < N; i++) cin >> a[i];
    cin >> M;
    for (int i = 0; i < M; i++) cin >> b[i];

    // sort
    sort(a, a+N);

    // find
    for (int i = 0; i < M; i++) {
   // left   right
      l = 0; r = N - 1;
      while( l <= r) {
        m = (l + r) / 2;
        if (a[m] < b[i]) l = m + 1;
        else if (a[m] > b[i]) r = m - 1;
        else {
          cout << "YES" << endl;
          break;
        }
      }
      if (l > r) cout << "NO" << endl;
    }
  }

  return 0;
}
