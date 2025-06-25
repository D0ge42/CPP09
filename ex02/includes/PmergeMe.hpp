#ifndef PmergeMe_HPP
#define PmergeMe_HPP

#include <bits/types/struct_timeval.h>
#include <ctime>
#include <list>
#include <set>
#include <vector>
#include <sys/time.h>
#include <iostream>

#define ERR_ARGS "\033[1;91mError: Please provide at least 2 positive integers\033[0m"
#define ERR_NOT_INT "\033[1;91mError: only positive integers are supported\033[0m"
#define ERR_NOT_UNIQUE "\033[1;91mError: There can only be unique elements\033[0m"
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
