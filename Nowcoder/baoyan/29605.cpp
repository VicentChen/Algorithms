// ------ 哈工大 - 找x ------- //
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int N, X, res;
  int a[200];
  while(cin >> N) {
    res = -1;
    for(int i = 0; i < N; i++)
      cin >> a[i];
    cin >> X;
    for (int i = 0; i < N; i++)
      if (a[i] == X) {
        res = i;
        break;
      }
    cout << res << endl;
  }
  return 0;
}
