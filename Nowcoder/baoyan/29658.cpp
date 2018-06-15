// ------ 华科 - 特殊排序 ------- //
// 1. 如果只有一个元素输出 -1      //
// 2. 只去掉一个最大值，即1 2 3 3 输出3\n1 2 3 //

#include <algorithm>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  
  int N;
  int a[1000];
  while(cin >> N) {
    for (int i = 0; i < N; i++)
      cin >> a[i];
    
    sort(a, a+N);
    
    // max
    cout << a[N-1] << endl;

    // one element
    if (N == 1) {
      cout << "-1" << endl;
      continue;
    }

    // more than one
    for (int i = 0; i < N - 2; i++) {
      cout << a[i] << ' ';
    }
    cout << a[N - 2] << endl;
  }

  return 0;
}
