// ------ HDU - FatMouse' Trade ------- //
// 1. 不能用float //
// 2. 注意边界如 0 //
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

struct House{
  int J;
  int F;
  double W;

  bool operator < (const House& h) const {
    return W < h.W;
  }
};

int main(int argc, char const *argv[]) {
  double M; int N;
  double left, count;
  House H[1000];
  while(cin >> M >> N) {
    if (M == -1 && N == -1) return 0;
    for (int i = 0; i < N; i++) {
      cin >> H[i].J >> H[i].F;
      if (H[i].F == 0) H[i].W = 100000;
      else H[i].W = H[i].J * 1.0 / H[i].F;
    }

    sort(H, H + N);

    left = M; count = 0;
    for (int i = N-1; i >= 0; i--) {
      if (H[i].F == 0) {
        count += H[i].J;
        continue;
      }
      if (left > H[i].F) { 
        left -= H[i].F;
        count += H[i].J;
      }
      else {
        count += left * H[i].W;
        break;
      }
    }
    cout << fixed << setprecision(3) << setfill('0') << count;
    cout << endl;
  }
  return 0;
}
