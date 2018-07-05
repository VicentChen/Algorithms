// ------ 哈工大 -  素数判定 ------ //
#include <iostream>
#include <cmath>

using namespace std;

int main(int argc, char const *argv[]) {
  int N, bound;
  bool flag;
  while(cin >> N) {
    if (N < 2) {
      cout << "no" << endl;
      continue;
    }
    
    bound = (int)sqrt(N);
    flag = true;
    for (int i = 2; i <= bound; i++)
      if (N % i == 0) {
        flag = false;
        break;
      }
    if (flag) cout << "yes" << endl;
    else cout << "no" << endl;
  }
  return 0;
}
