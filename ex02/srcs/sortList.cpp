#include "PmergeMe.hpp"
#include <algorithm>
#include <cstddef>
#include <cstdio>
#include <cstdlib>
#include <utility>

void PmergeMe::recursiveSortList(std::list<int> *list)
{
    if (list->size() <= 1)
        return;

    std::list<int> tmp_max;
    std::list<int> tmp_min;
    std::list<int>::iterator it = list->begin();

    while (it != list->end())
    {
        int first = *it;
        ++it;

        if (it == list->end())
        {
            tmp_max.push_back(first);
            break;
        }

        int second = *it;
        tmp_max.push_back(std::max(first, second));
        tmp_min.push_back(std::min(first, second));
        ++it;
    }

    recursiveSortList(&tmp_max);

    std::list<int>::reverse_iterator it_m;
    for (it_m = tmp_min.rbegin(); it_m != tmp_min.rend(); ++it_m)
    {
        std::list<int>::iterator it_pos = std::lower_bound(tmp_max.begin(), tmp_max.end(), *it_m);
        tmp_max.insert(it_pos, *it_m);
    }

    *list = tmp_max;
}
