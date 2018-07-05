// ------ 北航 - 素数 ------ //
#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int N) {
    int bound = (int)sqrt(N);
    for (int i = 2; i <= bound; i++)
        if (N % i == 0) return false;
    return true;
}

int main(int argc, char const *argv[]) {
  int n[1000];
  int num, N;

  // prepare
  n[0] = 0; num = 1;
  for (int i = 1; i < 1000; i++) {
    num += 10;
    n[i] = isPrime(num) ? 1 : 0;
  }

  // input
  while(cin >> N) {
    if (N < 11) {
      cout << -1 << endl;
      continue;
    }
    cout << 11;
    for(int i = 2; i < 1000; i++) {
      if (i * 10 + 1 >= N) break;
      if(n[i]) cout << " " << i * 10 + 1;
    }
    cout << endl;
  }

  return 0;
}
