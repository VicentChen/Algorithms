// ------ 清华 - 二叉树遍历 ------ //
#include <iostream>
#define NULL -1

using namespace std;

struct Node {
  char V;
  int P, L, R;
};

void traverl(Node *N, int i) {
  if (N[i].V == '#') return;
  traverl(N, N[i].L);
  cout << N[i].V << ' ';
  traverl(N, N[i].R);
}

int main(int argc, char const *argv[]) {
  Node N[100];
  int P, L, R;
  string s;
  while (getline(cin, s)) {
    int len = s.size();

    // save nodes
    for (int i = 0; i < len; i++) {
      N[i].V = s[i];
      N[i].P = N[i].L = N[i].R = NULL;
    }

    // construct tree
    N[0].P = NULL; P = 0;
    for (int i = 1; i < len; i++) {
      
      // find place to connect child
      for (P; P != NULL; P = N[P].P) {
        if (N[P].L == NULL || N[P].R == NULL) break;
      }
      // nothing to do
      if (P == NULL) continue;

      L = N[P].L; R = N[P].R;

      // child is empty
      if (L == NULL) {
        // connect left child
        N[P].L = i; N[i].P = P;
        // move down
        if (N[i].V != '#') P = i;
        continue;
      }
      if (R == NULL) {
        // connect left child
        N[P].R = i; N[i].P = P;
        // move down
        if (N[i].V != '#') P = i;
        continue;
      }
    }

    // travel tree
    traverl(N, 0);
  }

  return 0;
}
