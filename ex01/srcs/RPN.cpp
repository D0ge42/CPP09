#include "RPN.hpp"

RPN::RPN(void)
{
  this->num_digits = 0;
  this->num_sign = 0;
}

RPN::RPN(const RPN &other)
{
  this->num_digits = other.num_digits;
  this->num_sign = other.num_sign;
}

RPN::~RPN(void)
{
}

RPN &RPN::operator=(const RPN &other)
{
  (void)other;
  return (*this);
}
