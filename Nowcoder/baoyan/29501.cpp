// ------ 北大 - 谁是你潜在的朋友 ------- //
#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char const *argv[]) {
  int N, M;
  int book[201]; int reader[201];
  while (cin >> N >> M) {
    memset(book, 0, sizeof(book));
    memset(reader, 0, sizeof(reader));
    for (int i = 1; i <= N; i++) {
      cin >> reader[i];
      book[reader[i]]++;
    }
    
    for (int i = 1; i <= N; i++) {
      if (book[reader[i]] > 1) cout << book[reader[i]] - 1 << endl;
      else cout << "BeiJu" << endl;
    }
  }
  return 0;
}
