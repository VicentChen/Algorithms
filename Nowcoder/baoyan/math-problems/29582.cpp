// ------ 浙大 - 又一版A+B ------ //
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int m, A, B;
  int res[32], i;
  long long sum;

  while(cin >> m) {
    if (m == 0) return 0;

    cin >> A >> B;
    sum = 0; sum += A; sum += B; i = 0;
    for (sum; sum >= m; sum /= m)
      res[i++] = sum % m;
    res[i] = sum;
    for (i; i >= 0; i--)
      cout << res[i];
    cout << endl;
  }

  return 0;
}
