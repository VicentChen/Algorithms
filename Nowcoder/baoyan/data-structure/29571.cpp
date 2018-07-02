// ------ 浙大 - 二叉搜索树 ------ //
#include <iostream>
#define NULL -1

using namespace std;

struct Node{
  int V, L, R;
};

void construct(Node *n) {
  int len;
  string s;
  cin >> s; len = s.size();

  // construct BST
  for (int i = 0; i < len; i++) {
    n[i].V = s[i] - '0';
    n[i].L = n[i].R = NULL;
  }
  for (int i = 1; i < len; i++) {
    for (int P = 0; P < len;) {
      if (n[i].V < n[P].V) {
        if (n[P].L == NULL) { 
          n[P].L = i;
          break;
        }
        P = n[P].L;
      }
      else {
        if (n[P].R == NULL) {
          n[P].R = i;
          break;
        }
        P = n[P].R;
      }
    }
  }
}

long pre_order(long* pre, int root, Node *n) {
  if (root == NULL) return 0;
  *pre = *pre * 10 + n[root].V;
  long L = pre_order(pre, n[root].L, n);
  long R = pre_order(pre, n[root].R, n);
  return *pre;
}

long in_order(long* in, int root, Node *n) {
  if (root == NULL) return 0;
  long L = in_order(in, n[root].L, n);
  *in = *in * 10 + n[root].V;
  long R = in_order(in, n[root].R, n);
  return *in;
}

int main(int argc, char const *argv[]) {
  Node nodes[21];
  Node curr_nodes[21];
  long pre, in, curr_pre, curr_in;
  int N;
  while(cin >> N) {
    if (N == 0) break;

    pre = in = 0;
    construct(nodes);
    pre_order(&pre, 0, nodes); in_order(&in, 0, nodes);

    for (int i = 0; i < N; i++) {
      curr_pre = curr_in = 0;
      construct(curr_nodes);
      pre_order(&curr_pre, 0, curr_nodes); in_order(&curr_in, 0, curr_nodes);
      if (curr_pre == pre && curr_in == in) {
        cout << "YES" << endl;
      }
      else {
        cout << "NO" << endl;
      }
    }
  }

  return 0;
}
