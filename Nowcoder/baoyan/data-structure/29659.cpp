// ------ 二叉树遍历 ------ //
#include <iostream>
#define NULL -1

using namespace std;

struct Node {
  char V;
  int L, R;
};

string pre_order, in_order;
Node N[100];

// preorder left, preorder, right, inorder left, inorder right, parent node
int construct(int PL, int PR, int IL, int IR) {
  if(PL > PR || IL > IR) return NULL;

  char root_V = N[PL].V;
  int root;
  for (root = IL; root <= IR && in_order[root] != root_V; root++);
  int L_len = root - IL, R_len = IR - root;

  int L = construct(PL+1, PL+L_len, IL, root-1);
  int R = construct(PL+L_len+1, PR, root+1, IR);

  N[PL].L = L; N[PL].R = R;

  return PL;
}

void travel(int P) {
  if (P == NULL) return;
  travel(N[P].L);
  travel(N[P].R);
  cout << N[P].V;
}

int main(int argc, char const *argv[]) {
  while (getline(cin, pre_order)) {
    getline(cin, in_order);

    // record nodes
    int len = pre_order.size();
    for (int i = 0; i < len; i++) {
      N[i].V = pre_order[i];
      N[i].L = N[i].R = NULL;
    }

    construct(0, len-1, 0, len-1);

    travel(0);
    cout << endl;
  }

  return 0;
}
