#ifndef PmergeMe_HPP
#define PmergeMe_HPP

#include <list>
#include <vector>
#include <iostream>


class PmergeMe
{
  private:
    std::vector<int > *vec;
    std::list <int>*list;
  public:
    PmergeMe(void);
    PmergeMe(const PmergeMe &other);
    ~PmergeMe(void);

    PmergeMe &operator=(const PmergeMe &other);
    void makePairs(int ac, char **av);

    std::vector<int >* getVec();
    std::list<int>* getList();
    void printVec();
    void recursiveSortVec(std::vector<int> *vec);
};

#endif
