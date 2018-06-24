// ----- 吉林大学 - 堆栈的使用 ------ //
#include <iomanip>
#include <iostream>
#include <stack>

using namespace std;

int main(int argc, char const *argv[]) {
  int N, num;
  char c;
  stack<int> s;
  while (cin >> N) {
    for (int i = 0; i < N; i++) {
      cin >> c;
      if (c == 'A') {
        if (s.size() == 0) cout << 'E' << endl;
        else cout << s.top() << endl;
      }
      else if (c == 'P') {
        cin >> num;
        s.push(num);
      }
      else if (c == 'O') {
        if (s.size() > 0) s.pop();
      }
    }
    cout << endl;
  }

  return 0;
}
