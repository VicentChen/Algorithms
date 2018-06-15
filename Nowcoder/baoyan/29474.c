// ------ 清华 - 成绩排序 ------- //
#include <stdio.h>
#include <string.h>

typedef struct {
    int score;
    char *name;
}Student;

int main() {
    int N, type;
    int i_temp; char *c_temp;
    int i, j; 
    char name[100000];
    Student s[1000];
    while(scanf("%d%d", &N, &type) == 2) {
        for (i = 0; i < N; i++) {
            scanf("%s %d", name + 100 * i, &(s[i].score));
            s[i].name = name + 100 * i;
        }
        for (i = 0; i < N; i++) {
            for (j = N - 1; j > i; j--) {
                if (type) {
                    // ascsend
                    if (s[j].score < s[j-1].score) {
                        i_temp = s[j].score; s[j].score = s[j-1].score; s[j-1].score = i_temp;
                        c_temp = s[j].name; s[j].name = s[j-1].name; s[j-1].name = c_temp;
                    }
                }
                else {
                    // descend
                    if (s[j].score > s[j-1].score) {
                        i_temp = s[j].score; s[j].score = s[j-1].score; s[j-1].score = i_temp;
                        c_temp = s[j].name; s[j].name = s[j-1].name; s[j-1].name = c_temp;
                    }
                }
            }
        }
        for (i = 0; i < N; i++)
            printf("%s %d\n", s[i].name, s[i].score);
    }
    return 0;
}
