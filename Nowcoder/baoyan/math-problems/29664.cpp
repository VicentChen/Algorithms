// ------ 华科 - 守形数 ------ //
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int N, square, modN, modS;
  bool is;
  while (cin >> N) {
    square = N * N; is = true;
    while( N > 0 ) {
      if (N % 10 != square % 10) {
        is = false;
        break;
      }
      N /= 10; square /= 10;
    }
    cout << (is ? "Yes!" : "No!") << endl;
  }

  return 0;
}
