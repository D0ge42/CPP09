#include "PmergeMe.hpp"
#include <vector>

PmergeMe::PmergeMe(void)
{
  this->vec = new std::vector<int>();
  this->list = new std::list<int>();
}

PmergeMe::PmergeMe(const PmergeMe &other)
{
  (void)other;
}

PmergeMe::~PmergeMe(void)
{
}

PmergeMe &PmergeMe::operator=(const PmergeMe &other)
{
  (void)other;
  return (*this);
}

std::vector<int> *PmergeMe::getVec()
{
  return this->vec;
}


std::list<int>* PmergeMe::getList()
{
  return this->list;
}
