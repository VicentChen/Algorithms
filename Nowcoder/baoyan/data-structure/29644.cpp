// ------ 华科 - 二叉排序树 ------ //
#include <iostream>
#define NULL -1

using namespace std;

struct Node{
  int V, L, R;
};

Node nodes[100];

void pre_order(int root) {
  if (root == NULL) return;
  cout << nodes[root].V << ' ';
  pre_order(nodes[root].L);
  pre_order(nodes[root].R);
}

void in_order(int root) {
  if (root == NULL) return;
  in_order(nodes[root].L);
  cout << nodes[root].V << ' ';
  in_order(nodes[root].R);
}

void post_order(int root) {
  if (root == NULL) return;
  post_order(nodes[root].L);
  post_order(nodes[root].R);
  cout << nodes[root].V << ' ';
}


int main(int argc, char const *argv[]) {
  int N, P;

  while(cin >> N) {
    for (int i = 0; i < N; i++) {
      cin >> nodes[i].V;
      nodes[i].L = nodes[i].R = NULL;
    }
    
    for (int i = 1; i < N; i++) {
      for (int P = 0; P < N;) {
        if (nodes[P].V > nodes[i].V) {
          if (nodes[P].L == NULL) {
            nodes[P].L = i;
            break;
          }
          P = nodes[P].L;
        }
        else if (nodes[P].V < nodes[i].V) {
          if (nodes[P].R == NULL) {
            nodes[P].R = i;
            break;
          }
          P = nodes[P].R;
        }
        else break;
      }
    }

    pre_order(0); cout << endl;
    in_order(0); cout << endl;
    post_order(0); cout << endl;
  }
  return 0;
}
