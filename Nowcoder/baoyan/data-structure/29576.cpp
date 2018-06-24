// ------ 浙大、HDU - 简单计算器 ------- //
#include <iomanip>
#include <iostream>
#include <stack>
#define IS_NUM(c) (c >= '0' && c <= '9')
#define END_SIG '$'
#define POP(c, s) do {c = s.top(); s.pop();}while(0)
using namespace std;

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
  char compute_flag;
  char c;
  int len;
  double op1, op2;
  string s;
  stack<double> operand_stack;
  stack<char> operator_stack;

  while (getline(cin, s)) {
    // early end
    len = s.length();
    if (len == 1 && s[0] == '0') return 0;

    // init
    operand_stack.empty(); operator_stack.empty();
    operator_stack.push(END_SIG);

    for (int i = 0; i < len; i++) {
      if (IS_NUM(s[i])) {
        for (op1 = 0; i < len && IS_NUM(s[i]); op1 = op1 * 10 + s[i++] - '0');
        operand_stack.push(op1);
      }
      else if (s[i] != ' ') {
        while(true) {
          // get operator
          c = operator_stack.top();
          // if stack is empty, push
          if (c == END_SIG) { operator_stack.push(s[i]); break; }
          // else check priority
          if ((s[i] == '*' || s[i] == '/') && (c == '+' || c == '-'))
            { operator_stack.push(s[i]); break; }
          // compute
          // pop operands
          POP(op2, operand_stack); POP(op1, operand_stack);
          // pop operators
          operator_stack.pop();
          // push compute result
          operand_stack.push(compute(op1, op2, c));
        }
      }
    }

    c = operator_stack.top();
    while(c != END_SIG) {
      // pop operands
      POP(op2, operand_stack); POP(op1, operand_stack);
      // pop operators
      operator_stack.pop();
      // push compute result
      operand_stack.push(compute(op1, op2, c));
      // get new opeartors
      c = operator_stack.top();
    }

    // output
    cout << fixed << setprecision(2) << operand_stack.top() << endl;
  }

  return 0;
}
