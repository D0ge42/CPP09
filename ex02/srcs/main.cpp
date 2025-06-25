#include "PmergeMe.hpp"
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <sys/select.h>
#include <utility>
#include <vector>
#include <iostream>


int main(int ac , char **av)
{
  PmergeMe pm;
  std::vector<int > vec;
  std::list <int> list;
  std::set<int> set;

  int i = 1;

  if (ac <= 2)
  {
    std::cerr << ERR_ARGS << std::endl;
    return 1;
  }


  for (; i < ac; i++)
  {
    std::string arg = av[i];
    if (arg.find_first_not_of("1234567890") != 18446744073709551615UL)
    {
      std::cerr << ERR_NOT_INT << std::endl;
      return 1;
    }

    int num = std::atoi(av[i]);
    vec.push_back(num);
    list.push_back(num);
    set.insert(num);
  }

  if (set.size() != vec.size())
  {
    std::cerr << ERR_NOT_UNIQUE << std::endl;
    return 1;
  }

  pm.printContainer(vec,BEFORE);

  const std::clock_t v_start = std::clock();
  pm.recursiveSortVec(&vec);
  const std::clock_t v_end = std::clock();

  const std::clock_t l_start = std::clock();
  pm.recursiveSortList(&list);
  const std::clock_t l_end = std::clock();

  pm.printSet(set);
  double v_res = static_cast<double>(v_end - v_start) * 1e6 / CLOCKS_PER_SEC;
  double l_res = static_cast<double>(l_end - l_start) * 1e6 / CLOCKS_PER_SEC;

  std::cout << "Time to process a range of " << vec.size() << " with std::vector : " << v_res << " µs" << std::endl;
  std::cout << "Time to process a range of " << list.size() << " with std::list : " << l_res << " µs" << std::endl;
}
