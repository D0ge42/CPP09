#include "PmergeMe.hpp"
#include <cstdlib>
#include <iostream>
#include <list>
#include <utility>

#define BEFORE 'b'
#define AFTER 'a'

void PmergeMe::printContainer(std::vector<int> &vec, char c)
{
  std::vector<int>::iterator it;

  if (c == BEFORE)
    std::cout << "Before = \033[1;91m[ ";
  else if (c == AFTER)
    std::cout << "After VEC = \033[1;92m[ ";

  for (it = vec.begin(); it != vec.end(); it++)
  {
    if (*it != -1)
      std::cout << *it;
    if (it != vec.end() - 1)
      std::cout << ", ";
  }
  std::cout << " ]\033[0m" << std::endl;
}

void PmergeMe::printList(std::list<int> &list, char c)
{
  std::list<int>::iterator it;
  if (c == BEFORE)
    std::cout << "Before LIST = \033[1;91m[ ";
  else if (c == AFTER)
    std::cout << "AFTER LIST = \033[1;92m[ ";

  for (it = list.begin(); it != list.end(); it++)
  {
    if (*it != -1)
      std::cout << *it;
    std::list<int>::iterator next = it;
    if (++next != list.end())
      std::cout << ", ";
  }
  std::cout << " ]\033[0m" << std::endl;
}

void PmergeMe::printSet(std::set<int> &set)
{
  std::set<int>::iterator it;
  std::cout << "AFTER = \033[1;92m[ ";

  for (it = set.begin(); it != set.end(); it++)
  {
    if (*it != -1)
      std::cout << *it;
    std::set<int>::iterator next = it;
    if (++next != set.end())
      std::cout << ", ";
  }
  std::cout << " ]\033[0m" << std::endl;
}

