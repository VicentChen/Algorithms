// ------ 北大 - 字符串排序 ------- //

#include <algorithm>
#include <cctype>
#include <iostream>

using namespace std;

struct IndexedStr {
  int index;
  char c;
  bool operator<(const IndexedStr istr) const { return c < istr.c; }
};

int main(int argc, char const *argv[]) {
  string str, res;
  IndexedStr istr[10000];
  int len, alpha_count;
  while (getline(cin, str)) {
    res = str;
    len = str.size();
    alpha_count = 0;
    for (int i = 0; i < len; i++) {
      if (isalpha(str[i])) {
        istr[alpha_count].index = i;
        istr[alpha_count].c = tolower(str[i]);
        alpha_count++;
      }
    }

    stable_sort(istr, istr + alpha_count);
    // A Famous Saying: Much Ado About Nothing(2012/8).
    for (int i = 0, j =0; i < len; i++) {
      if (isalpha(str[i])) {
        res[i] = str[istr[j++].index];
      }
    }

    cout << res << endl;
  }
  return 0;
}
