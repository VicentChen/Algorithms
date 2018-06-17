// ------ HDU - 叠筐 ------- //
// 1. 筐与筐之间空一行         //
// 2. 最后的筐不空行，但是换行  //

#include <iostream>

using namespace std;

char P[79][79]; // pattern

int main() {
  // construct pattern
  int begin, end, mark;
  P[38][38] = 1;
  for (int i = 1; i <= 38; i++) {
    begin = 38 - i; end = 38 + i; mark = !(i & 1);
    for (int j = begin; j <= end; j++) P[j][begin] = mark; // left
    for (int j = begin; j <= end; j++) P[begin][j] = mark; // top
    for (int j = begin; j <= end; j++) P[j][end] = mark; // top
    for (int j = begin; j <= end; j++) P[end][j] = mark; // bottom
  }

  int N, r; char c1, c2;
  int first = 1;
  while (cin >> N >> c1 >> c2) {
    if (first) first = 0;
    else cout << endl;
    
    if (N == 1) {
      cout << c1 << endl;
      continue;
    }

    r = (N - 1) / 2; begin = 38 - r; end = 38 + r;
    mark = P[38-r][38-r];
    // first line
    cout << ' ';
    for (int i = begin + 1; i < end; i++) {
      cout << (P[begin][i] ? c1 : c2);
    }
    cout << ' ' << endl;

    // middle
    for (int i = begin + 1; i < end; i++) {
      for (int j = begin; j < end; j++) {
        cout << (P[i][j] ? c1 : c2);
      }
      cout << (P[i][end] ? c1 : c2) << endl;
    }

    // end line
    cout << ' ';
    for (int i = begin + 1; i < end; i++) {
      cout << (P[begin][i] ? c1 : c2);
    }
    cout << ' '  << endl;
  }
  return 0;
}