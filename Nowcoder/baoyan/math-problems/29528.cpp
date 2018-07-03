// ------ 北大 - 数制转换 ------ //
#include <iostream>
#define IS_NUM(n) (n >= '0' && n <= '9')
#define IS_UPPER(n) (n >= 'A' && n <= 'F')
#define IS_LOWER(n) (n >= 'a' && n <= 'f')

using namespace std;

int main(int argc, char const *argv[]) {
  int A, B, size;
  string N;
  long num10;
  int res[64], index;
  while(cin >> A >> N >> B) {
    num10 = 0; size = N.size();
    for (int i = 0; i < size; i++) {
      if (IS_NUM(N[i])) num10 = num10 * A + N[i] - '0';
      else if (IS_UPPER(N[i])) num10 = num10 * A + N[i] - 'A' + 10;
      else if (IS_LOWER(N[i])) num10 = num10 * A + N[i] - 'a' + 10;
    }

    for (index = 0; num10 >= B; num10 /= B)
      res[index++] = num10 % B;
    res[index] = num10;

    for (index; index >= 0; index--)
      cout << (char)(res[index] >= 10 ? res[index] - 10 + 'A' : res[index] + '0');
    cout << endl;
  }
  return 0;
}
