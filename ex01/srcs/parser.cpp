#include "RPN.hpp"
#include <cctype>
#include <cstring>
#include <iostream>
#include <ostream>
#include <string>

static bool is_sign(char c);

bool RPN::parseString(const char *arg)
{
  std::string str = arg;
  int len = str.length();

  if (str.find_first_not_of("1234567890 +-*/") != std::string::npos)
  {
    std::cerr << ERR_UNKW_CHARS << std::endl;
    return false;
  }

  for (int i = 0; i < len ; i++)
  {
    if (isdigit(arg[i]) == true)
      this->num_digits++;
    if (is_sign(arg[i]) == true)
      this->num_sign++;
  }
  if (this->num_sign != (this->num_digits - 1))
  {
    std::cerr << ERR_MAL_EXPR << std::endl;
    return false;
  }
  return true;
}

static bool is_sign(char c)
{
  if (c == '/' || c == '*' || c == '+' || c == '-')
    return 1;
  return 0;
}
