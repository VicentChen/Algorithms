// ------ 华为 - 最小公倍数 ------ //
#include <iostream>

using namespace std;

int gcd(int A, int B) {
  if (B == 0) return A;
  else return gcd(B, A % B);
}

int main(int argc, char const *argv[]) {
  int A, B;
  int GCD;
  while(cin >> A >> B) {
    GCD = (A >= B) ? gcd(A, B) : gcd(B, A);
    cout << (GCD * (A / GCD) * (B / GCD)) << endl;
  }
  return 0;
}
