#ifndef PmergeMe_HPP
#define PmergeMe_HPP

#include <vector>
class PmergeMe
{
  private:
    std::vector<int> *vec;
  public:
    PmergeMe(void);
    PmergeMe(const PmergeMe &other);
    ~PmergeMe(void);

    PmergeMe &operator=(const PmergeMe &other);
    void makePairs();
};

#endif
