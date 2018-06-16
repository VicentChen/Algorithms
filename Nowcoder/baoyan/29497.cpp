// ------ 清华 - 剩下的树 ------- //
#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[]) {
  int L, M;
  int left, right, count;
  char tree[10001];

  while(cin >> L >> M) {
    memset(tree, 1, sizeof(tree));
    count = 0;

    for (int i = 0; i < M; i++) {
      cin >> left >> right;
      memset(tree + left, 0, sizeof(char) * (right - left + 1));
    }

    for (int i = 0; i <= L; i++) count += tree[i];
    cout << count << endl;
  }

  return 0;
}
