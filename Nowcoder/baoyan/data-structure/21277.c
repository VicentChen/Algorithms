// ------ 华为 - 表达式求值 ------ //
#include <stdio.h>

#define IS_NUM(c) (c >= '0' && c <= '9')
#define END_SIG '$'
#define POP(c, s) do {c = s.top(); s.pop();}while(0)

double compute(double op1, double op2, char op) {
  switch (op) {
    case '+':
      return op1 + op2;
    case '-':
      return op1 - op2;
    case '*':
      return op1 * op2;
    case '/':
      return op1 / op2;
    default:
      return 0;
  }
}

int main(int argc, char const *argv[]) {
  char s[100],c;
  double NS[100]; int NI = 0;
  char OS[100]; int OI = 0;
  int num, i, negative;
  double op1, op2;

  while(gets(s)) {
    // early end
    if (!s[0]) continue;

    // init
    NI = OI = 0; OS[OI++] = END_SIG;

    // check first minus
    if (s[0] == '-') { i = 1; negative = 1;}
    else {i = 0; negative = 0;}

    for (i; s[i]; i++) {
      if (IS_NUM(s[i])) {
        // number
        for (num = 0; IS_NUM(s[i]); num = num * 10 + s[i++] - '0');
        i--; // redirect to next char
        NS[NI++] = negative ? -num : num; // push to stack
        negative = 0; // reset negative flag
      }
      else {
        // character
        // left brace, push
        if (s[i] == '(') {
          OS[OI++] = s[i];
          // "(-", set negative
          if (s[i+1] == '-') {negative = !negative; i++;}
          continue;
        }

        // right brace, compute
        if (s[i] == ')') {
          for (OI--; OS[OI] != '('; OI--) {
            op2 = NS[--NI]; op1 = NS[--NI];
            NS[NI++] = compute(op1, op2, OS[OI]);
          }
          continue;
        }

        // compute
        while(1) {
          c = OS[OI - 1];
          // empty stack, push
          if (c == END_SIG) {OS[OI++] = s[i]; break;}
          // check priority
          if (c == '(')  {OS[OI++] = s[i]; break;}
          if ((s[i] == '*' || s[i] == '/') && (c == '+' || c == '-'))
            {OS[OI++] = s[i]; break;}
          
          op2 = NS[--NI]; op1 = NS[--NI]; OI--;
          NS[NI++] = compute(op1, op2, c);
        }
      }
    }

    for(OI--; OS[OI] != END_SIG; OI--) {
      c = OS[OI];
      op2 = NS[--NI]; op1 = NS[--NI];
      NS[NI++] = compute(op1, op2, c);
    }

    printf("%d\n", (int)NS[--NI]);
  }

  return 0;
}
