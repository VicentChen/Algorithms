// ------ 清华 - 特殊乘法 ------ //
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char const *argv[]) {
  string A, B;
  int sizeA, sizeB;
  int realA, realB;
  while (cin >> A >> B) {
    realA = realB = 0;
    sizeA = A.size(); sizeB = B.size();
    for (int i = 0; i < sizeA; i++) realA += A[i] - '0';
    for (int i = 0; i < sizeB; i++) realB += B[i] - '0';
    cout << realA * realB << endl;
  }
  return 0;
}
