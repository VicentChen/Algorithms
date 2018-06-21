// ------ HDU - 今年暑假不AC ------- //
#include <algorithm>
#include <iostream>

using namespace std;

struct Range{
  int L;
  int R;

  bool operator < (const Range& r) const {
    return R < r.R;
  }
};

int main(int argc, char const *argv[]) {
  int N, index, C, t;
  Range r[100];

  while (cin >> N) {
    if (!N) return 0;
    for (int i = 0; i < N; i++) cin >> r[i].L >> r[i].R;

    sort(r, r+N);

    index = 0; C = 0;
    while(index < N) {
      C++;
      t = r[index].R;
      for(index; index < N && r[index].L < t; index++);
    }

    cout << C << endl;
  }

  return 0;
}
