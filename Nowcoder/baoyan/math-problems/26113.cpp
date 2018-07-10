// ------ HDU - A sequence of numbers ------ //
#include <cmath>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int N, K; long long num[3];
  bool isArithmic;
  long long step; int ans;

  while(cin >> N) {
    for (int i = 0; i < N; i++) {
      // input
      for (int k = 0; k < 3; k++) cin >> num[k];
      cin >> K;
      // judge
      isArithmic = (num[2] + num[0] == num[1] << 1) ? true : false;

      if (isArithmic) {
        ans = num[0];
        step = (num[1] - num[0]) % 200907;
        for (K--; K != 0; K /= 2) {
          if (K % 2 == 1) ans = (ans + step) % 200907;
          step = step * 2 % 200907;
        }
      }
      else {
        ans = num[0];
        step = (num[1] / num[0]) % 200907;
        for(K--; K != 0; K /= 2) {
          if (K % 2 == 1) ans = (ans * step) % 200907;
          step = step * step % 200907;
        }
      }

      // output
      cout << ans << endl;
    }
  }

  return 0;
}
