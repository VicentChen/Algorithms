// ------ 北大 - Repeater ------- //
#include <stdio.h>
#include <stdlib.h>

char P[6][6];

void swap(char **S, char **D) {
  char *T = *S;
  *S = *D; *D = T;
}

int main() {
  char *Buf = (char*)malloc(sizeof(char)*18000000);
  char *S = Buf, *D = Buf + 9000000;

  int N, Q, size;
  while (scanf("%d", &N) == 1) {
    if (N == 0) break;

    getchar(); // redraw '\n'
    // input
    for(int i = 0; i < N; i++) {
      gets(P[i]);
    }

    scanf("%d", &Q);
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        S[i*3000+j] = P[i][j];
    size = N;

    for (; Q > 1; Q--) {
      for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
          if (S[i * 3000 + j] != ' ') {
            // replace pattern
            for (int m = 0; m < N; m++) {
              for (int n = 0; n < N; n++) {
                D[(i*N+m) * 3000 + (j*N+n)] = P[m][n];
              }
            }
          }
          else {
            for (int m = 0; m < N; m++) {
              for (int n = 0; n < N; n++) {
                D[(i*N+m) * 3000 + (j*N+n)] = ' ';
              }
            } 
          }
        }
      }
      swap(&S, &D);
      size *= N;
    }

    for (int i = 0; i < size; i++ ) {
      for (int j = 0; j < size; j++) {
        putchar(S[i*3000 + j]);
      }
      putchar('\n');
    }
  }

  free(Buf);
  return 0;
}