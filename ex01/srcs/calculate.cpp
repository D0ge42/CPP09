#include "RPN.hpp"
#include <cctype>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <ostream>
#include <stack>
#include <utility>

static bool is_sign(char c);
static long long int do_math(t_op &op);

void RPN::calculate(const char *str)
{
  int len = strlen(str);
  t_op op;
  op.op = 0;
  std::stack<int> stack;

  for (int i = 0; i < len ; i++)
  {
    if (isdigit(str[i]) == true)
    {
      stack.push(str[i] - 48);
    }
    else if (is_sign(str[i]) == true)
    {
      op.op = str[i];
    }
    if (op.op != 0)
    {
      if (stack.size() < 2)
      {
        std::cerr << ERR_NUM_COUNT << std::endl;
        return;
      }
      else
      {
        op.f_n = stack.top();
        stack.pop();
        op.s_n = stack.top();
        stack.pop();
        op.res = do_math(op);
        stack.push(op.res);
        op.op = 0;
      }
    }
  }
  std::cout << "Result: " << op.res << std::endl;
}

static long long int do_math(t_op &op)
{
  if (op.f_n == 0 && op.op == '/')
  {
    std::cerr << ERR_DIV_ZERO << std::endl;
    exit(1);
  }
  if (op.op == '*')
  {
    if (op.f_n * op.s_n > 2147483647)
    {
      std::cerr << ERR_RES_OVERFLOW << std::endl;
      exit(1);
    }
  }
  if (op.op == '+')
    return op.f_n + op.s_n;
  if (op.op == '-')
    return op.s_n - op.f_n;
  if (op.op == '/')
    return op.s_n / op.f_n;
  if (op.op == '*')
    return op.s_n * op.f_n;
  return 0;
}

static bool is_sign(char c)
{
  if (c == '/' || c == '*' || c == '+' || c == '-')
    return 1;
  return 0;
}
