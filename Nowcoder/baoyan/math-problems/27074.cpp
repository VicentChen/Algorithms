// ------ HDU - 人见人爱A^B ------ //
#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int A, B;
  int ans;
  while(cin >> A >> B) {
    if (A == 0 && B == 0) break;

    // init 
    ans = 1; 

    for(B; B != 0; B /= 2) {
      if (B % 2 == 1)
        ans = ans * A % 1000;
      A = A * A % 1000;
    }

    cout << ans << endl;
  }
  return 0;
}
