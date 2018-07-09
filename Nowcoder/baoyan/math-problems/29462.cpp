  // ------ 上交 - 整除问题 ------ //
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

    int prime[1000], primeSize = 0;
    int n, a, t;
    int cntN[1000], cntA[1000];
    int ans = 10000000;

    // pre-compute
    for (int i = 2; i <= 1000; i++)
      if (isPrime(i)) prime[primeSize++] = i;

    while(cin >> n >> a) {

      // init
      for (int i = 0; i < primeSize; i++)
        cntN[i] = cntA[i] = 0;

      // decompose n!
      for (int i = 0; i < primeSize; i++) {
        for(t = n; t; t /= prime[i]) cntN[i] += t / prime[i];
      }

      // decompose a
      for (int i = 0; i < primeSize; i++) {
        for(a; a % prime[i] == 0; a /= prime[i]) cntA[i]++;
      }

      // compute answer
      for (int i = 0; i < primeSize; i++) {
        if (cntA[i] && cntN[i] / cntA[i] < ans)
          ans = cntN[i] / cntA[i];
      }

      // output
      cout << ans << endl;
    }

    return 0;
  }
