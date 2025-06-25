#include "PmergeMe.hpp"
#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <cstdlib>

void PmergeMe::recursiveSortVec(std::vector<int> *vec)
{
    if (vec->size() <= 1)
    {
        return;
    }

    std::vector<int> tmp_max;
    std::vector<int> tmp_min;
    size_t i = 0;

    for (i = 0; i + 1 < vec->size(); i += 2)
    {
        int first = (*vec)[i];
        int second = (*vec)[i + 1];
        tmp_max.push_back(std::max(first, second));
        tmp_min.push_back(std::min(first, second));
    }

    if (i < vec->size())
    {
        tmp_max.push_back((*vec)[i]);
    }

    recursiveSortVec(&tmp_max);

    for (int j = tmp_min.size() - 1; j >= 0; j--)
    {
        std::vector<int>::iterator pos = std::lower_bound(tmp_max.begin(), tmp_max.end(), tmp_min[j]);
        tmp_max.insert(pos, tmp_min[j]);
    }

    *vec = tmp_max;
}
