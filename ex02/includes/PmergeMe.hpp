#ifndef PmergeMe_HPP
#define PmergeMe_HPP

#include <bits/types/struct_timeval.h>
#include <ctime>
#include <list>
#include <set>
#include <vector>
#include <sys/time.h>
#include <iostream>

#define BEFORE 'b'
#define AFTER 'a'

class PmergeMe
{
  private:

  public:
    PmergeMe(void);
    PmergeMe(const PmergeMe &other);
    ~PmergeMe(void);

    PmergeMe &operator=(const PmergeMe &other);
    void makePairs(int ac, char **av);

    void printContainer(std::vector<int> &vec, char c);
    void printSet(std::set<int> &set);
    void printList(std::list<int> &list, char c);

    bool parser(std::vector<int>&vec);
    void recursiveSortVec(std::vector<int> *vec);
    void recursiveSortList(std::list<int> *list);
};

#endif
