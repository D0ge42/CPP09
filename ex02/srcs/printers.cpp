#include "PmergeMe.hpp"
#include <cstdlib>
#include <iostream>
#include <list>
#include <utility>

void PmergeMe::printVec()
{
  std::vector<int>::iterator it;

  std::cout << "Before = \033[1;91m[ ";
  for (it = this->vec->begin(); it != this->vec->end(); it++)
  {
    if (*it != -1)
      std::cout << *it;
    if (it != this->vec->end() - 1)
      std::cout << ", ";
  }
  std::cout << " ]\033[0m" << std::endl;
}
