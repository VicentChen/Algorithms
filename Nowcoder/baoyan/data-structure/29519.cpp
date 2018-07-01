// ------ 北大 - 二叉树 ------ //
#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
  int x, y, xlen, ylen;
  int px[32], py[32];
  while(cin >> x >> y) {

    for (xlen = 0; x > 1; x /= 2) px[xlen++] = x;
    for (ylen = 0; y > 1; y /= 2) py[ylen++] = y;
    px[xlen] = py[ylen] = 1;


    while(xlen >= 0 && ylen >= 0) {
      if (px[xlen] != py[ylen]) break;
      xlen--; ylen--;
    }

    cout << px[xlen+1] << endl;
  }
  return 0;
}
