// ------ 上交 - Simple Sorting ------- //
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
  int N;
  int a[1000];
  while (cin >> N) {
    for (int i = 0; i < N; i++) cin >> a[i];
    sort(a, a+N);
    cout << a[0];
    for (int i = 1; i < N; i++) {
      if (a[i] != a[i-1]) cout << ' ' << a[i];
    }
    cout << endl;
  }
  return 0;
}