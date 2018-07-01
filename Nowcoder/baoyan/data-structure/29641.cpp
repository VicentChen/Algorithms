// ------ 北邮 - 树查找 ------ //
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {

  int N, L;
  int begin, end;
  int tree[1000];

  while(cin >> N) {
    // input
    for (int i = 0; i < N; i++) cin >> tree[i];
    cin >> L;

    begin = (1 << (L - 1)) - 1;
    end = (1 << L) - 1; 
    if (begin >= N) {
      cout << "EMPTY" << endl;
      continue;
    }
    if (end > N) end = N;

    cout  << tree[begin];
    for (int i = begin + 1; i < end; i++) cout << ' ' << tree[i];
    cout << endl;
  }

  return 0;
}
