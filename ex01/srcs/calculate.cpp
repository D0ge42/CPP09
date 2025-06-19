#include "RPN.hpp"
#include <cctype>
#include <cstring>
#include <iostream>
#include <ostream>
#include <stack>
#include <string>

static bool is_sign(char c);
static int do_math(int num1, int num2 , char sign);

void RPN::calculate(const char *str)
{
  int len = strlen(str);
  int res = 0;
  char f_sign = 0;
  int first_num;
  int second_num;

  for (int i = 0; i < len ; i++)
  {
    if (isdigit(str[i]) == true)
    {
      stack->push(str[i] - 48);
    }
    else if (is_sign(str[i]) == true)
    {
      f_sign = str[i];
    }
    if (f_sign != 0)
    {
      if (stack->size() < 2)
      {
        std::cerr << ERR_NUM_COUNT << std::endl;
        return;
      }
      else
      {
        first_num = stack->top();
        stack->pop();
        second_num = stack->top();
        stack->pop();
        res = do_math(first_num, second_num, f_sign);
        stack->push(res);
        f_sign = 0;
      }
    }
  }
  std::cout << "Result: " << res << std::endl;
}

static int do_math(int num1, int num2 , char sign)
{
  if (sign == '+')
    return num1 + num2;
  if (sign == '-')
    return num2 - num1;
  if (sign == '/')
    return num2 / num1;
  if (sign == '*')
    return num2 * num1;
  return 0;
}

static bool is_sign(char c)
{
  if (c == '/' || c == '*' || c == '+' || c == '-')
    return 1;
  return 0;
}
