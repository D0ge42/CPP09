#include "RPN.hpp"

RPN::RPN(void)
{
  this->num_digits = 0;
  this->num_sign = 0;
  this->stack = new std::stack<int>();
}

RPN::RPN(const RPN &other)
{
  (void)other;
}

RPN::~RPN(void)
{
  delete this->stack;
}

RPN &RPN::operator=(const RPN &other)
{
  (void)other;
  return (*this);
}
