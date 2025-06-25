#include "PmergeMe.hpp"
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <list>
#include <utility>
#include <vector>

#define BEFORE 'b'
#define AFTER 'a'

bool PmergeMe::parser(std::vector<int>&vec)
{
  std::vector<int>::iterator it;
  if (*std::min_element(vec.begin(), vec.end()) < 0)
  {
    std::cout << "Found negative num";
    return false;
  }
  return true;
}

