#include "PmergeMe.hpp"
#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <utility>

void PmergeMe::makePairs(int ac, char **av)
{
  int i = 1;
  std::pair<int, int> last_element;

  for (; i < ac; i++)
  {
    this->vec->push_back(std::atoi(av[i]));
  }
}

void PmergeMe::recursiveSortVec(std::vector<int> *vec)
{
  if (vec->size() <= 1)
    return;

  std::vector<int> tmp_max;
  std::vector<int> tmp_min;
  std::vector<std::pair<int,int> >::iterator it;
  size_t i = 0;

  for (i = 0; i < vec->size() - 1; i+=2)
  {
    int first = (*vec)[i];
    int second = (*vec)[i + 1];
    tmp_max.push_back(std::max(first,second));
    tmp_min.push_back(std::min(first,second));
  }

  if (vec->size() %2 != 0)
  {
    tmp_max.push_back((*vec)[i]);
  }

  recursiveSortVec(&tmp_max);

  std::vector<int>::iterator it_m;
  std::vector<int>::iterator s;
  for (size_t i = 0; i < tmp_min.size(); i++)
  {
    s = std::lower_bound(tmp_max.begin(),tmp_max.end(),tmp_min[i]);
    tmp_max.insert(s,tmp_min[i]);
  }
  *vec = tmp_max;
}
