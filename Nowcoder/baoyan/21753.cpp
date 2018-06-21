// ------ HDU - Repair the Wall ------- //
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

int main(int argc, char const *argv[]) {
  int L, N;
  int count;
  int A[600];
  while( cin >> L >> N ) {
    for (int i = 0; i < N; i++) cin >> A[i];

    sort(A, A+N);

    count = 0;
    for (int i = N - 1; i >= 0; i--) {
      L -= A[i]; count++;
      if (L <= 0) break;
    }
    if (L > 0) cout << "impossible" << endl;
    else cout << count << endl;
  }
  return 0;
}
