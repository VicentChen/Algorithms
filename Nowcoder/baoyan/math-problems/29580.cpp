// ------ 浙大 - 还是A+B ------- //
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int t[9] = { 
    1, 10, 100, 1000, 10000, 
    100000, 1000000, 10000000, 100000000 
  };
  int A, B, K, mod;
  int modA, modB;
  while (cin >> A >> B >> K) {
    if (A == 0 && B == 0) break;

    mod = t[K];
    modA = A % mod; modB = B % mod;
    if (modA == modB) cout << -1 << endl;
    else cout << A + B << endl;
  }

  return 0;
}