// ------ 北大 - 打印极值点下标 ------- //
#include <iostream>
#include <cstring>

using namespace std;

int main() {

  int k, t;
  int a[80], f[80];

  while(cin >> k) {
    memset(f, 0, sizeof(f));

    for (int i = 0; i < k; i++) cin >> a[i];
    // first element
    if (a[0] != a[1]) f[0] = 1;

    // middle elements
    for (int i = 1; i < k - 1; i++) {
      t = (a[i] - a[i-1]) * (a[i] - a[i+1]);
      if (t > 0) f[i] = 1;
    }

    // last element
    if (a[k-1] != a[k-2]) f[k-1] = 1;

    for (t = 0; t < k; t++)
      if (f[t]) { cout << t; break; }
    for (++t; t < k; t++)
      if (f[t]) cout << ' ' << t ;
    cout << endl;
  }

  return 0;
}