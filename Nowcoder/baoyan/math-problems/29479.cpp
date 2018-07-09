// ------ 清华 - 质因数的个数 ------ //
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
  bool T[100001];
  int N, bound, count;

  // pre-compute
  T[0] = T[1] = false;
  for (int i = 2; i <= 100000; i++)
    T[i] = isPrime(i) ? true : false;

  while (cin >> N) {
    // init
    bound = (int)sqrt(N); count = 0;

    for (int i = 2; i <= bound; i++) {
      if(isPrime(i)) {
        for (count; N % i == 0; count++) N /= i;
      }
    }

    if (N != 1) count++;

    cout << count << endl;
  }

  return 0;
}
