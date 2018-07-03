// ------ 北大 - Digital Roots ------ //
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int N, S;

  while (cin >> N) {
    for (N; N >= 10; N = S) {
      for (S = 0; N > 0; N /= 10)
        S += N % 10;
      N = S;
    }
    cout << N << endl;
  }

  return 0;
}
