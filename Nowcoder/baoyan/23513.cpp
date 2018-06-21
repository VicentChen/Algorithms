// ------ HDU - 迷瘴 ------- //
#include <algorithm>
#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char const *argv[]) {
  int C;
  int N,V,W;
  int P[100];
  int count, total;
  double concentration;

  cin >> C;
  for(int x = 0; x < C; x++) {
    cin >> N >> V >> W;
    for (int i = 0; i < N; i++) cin >> P[i];

    sort(P, P+N);

    count = 0; total = 0;
    for (int i = 0; i < N; i++) {
      total += P[i]; count++;
      if (total > W * count) {
        total -= P[i];
        count--;
        break;
      }
    }

    if (count == 0) concentration = 0;
    else concentration = total * 1.0 / count;

    cout << V * count << ' ';
    cout << fixed << setprecision(2) << setfill('0') << concentration / 100;
    cout << endl;
  }

  return 0;
}
