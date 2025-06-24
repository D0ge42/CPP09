#include "PmergeMe.hpp"
#include <cstdlib>
#include <utility>
#include <vector>
#include <iostream>

// make pairs
// sort pairs
// make list with bigger numbers
// merge sort bigger list

int main(int ac , char **av)
{
  PmergeMe pm;
  pm.makePairs(ac, av);
  pm.printVec();
  pm.recursiveSortVec(pm.getVec());
  pm.printVec();
}
