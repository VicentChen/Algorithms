// ------ 北邮 - 哈夫曼树 ------ //
#include <iostream>
#include <queue>
 
using namespace std;
 
int main(int argc, char const *argv[]) {
  priority_queue<int, vector<int>, greater<int>> Q;
  int N, num;
  int a, b, res;
 
  while(cin >> N) {
    // init
    res = 0;
 
    // input
    for (int i = 0; i < N; i++) {
      cin >> num;
      Q.push(num);
    }
 
    while(Q.size() > 1) {
      a = Q.top(); Q.pop();
      b = Q.top(); Q.pop();
      res += a + b;
      Q.push(a + b);
    }
    Q.pop();
 
    cout << res << endl; 
  }
 
  return 0;
}