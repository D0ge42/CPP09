#include "RPN.hpp"
#include <iostream>

int main(int ac, char **av)
{
  RPN rpn;

  if (ac != 2)
  {
    std::cerr << ERR_NUM_ARGV << std::endl;
    return 1;
  }
  if (rpn.parseString(av[1]) == true)
    rpn.calculate(av[1]);
  return 0;
}
