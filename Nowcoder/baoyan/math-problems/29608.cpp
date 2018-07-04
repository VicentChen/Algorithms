// ------ 哈工大 - 最大公约数 ------ //
#include <iostream>

using namespace std;

int gcd(int a, int b) {
  if (b == 0) return a;
  else return gcd(b, a % b);
}

int main(int argc, char const *argv[]) {
  int a, b;
  while(cin >> a >> b) {
    if (a >= b) cout << gcd(a, b) << endl;
    else cout << gcd(b, a) << endl;
  }
  return 0;
}
