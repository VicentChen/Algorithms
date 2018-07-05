// ------ 上交 - Prime Number ------ //
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
  
  int prime[10000];
  int last_i, last_prime, N;

  prime[0] = 2; last_prime = 2; last_i = 1;
  while(cin >> N) {
    for (last_i; last_i < N; last_i++) {
      for(last_prime += 1; !isPrime(last_prime); last_prime++);
      prime[last_i] = last_prime;
    }
    cout << prime[N - 1] << endl;
  }

  return 0;
}
