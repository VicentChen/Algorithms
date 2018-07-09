// ------ 清华 - 约数的个数 ------ //
#include <cmath>
#include <iostream>

using namespace std;

bool isPrime(int N) {
  int bound = (int)sqrt(N);
  for (int i = 2; i <= bound; i++)
    if (N % i == 0) return false;
  return true;
}

int main(int argc, char const *argv[]) {
  int N, Num, count, bound;
  int L, R, T;

  while(cin >> N) {
    if (N == 0) break;

    for (int i = 0; i < N; i++) {

      cin >> Num; count = 2;
      if (Num == 1) {
        cout << 1 << endl;
        continue;
      }

      bound = (int)sqrt(Num);
      for (int i = 2; i <= bound; i++) {
        if (Num % i == 0) count += 2;
      }
      if (bound * bound == Num) count -= 1;

      cout << count << endl;
    }
  }

  return 0;
}
