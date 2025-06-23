#include <cstdlib>
#include <utility>
#include <vector>
#include <iostream>

int main(int ac , char **av)
{
  int i = 1;
  std::vector<std::pair<int, int> >vec;
  std::vector<std::pair<int, int> >::iterator it;
  std::pair<int, int> last_element;


  for (; i < ac; i+=2)
  {
    if (av[i + 1] != NULL)
    {
      std::pair<int, int> to_push = std::make_pair(std::atoi(av[i]),std::atoi(av[i + 1]));
      vec.push_back(to_push);
    }
  }
  if ((ac - 1) %2 != 0)
  {
    last_element = std::make_pair(std::atoi(av[ac - 1]),-1);
    vec.push_back(last_element);
  }

  std::cout << "Before = \033[1;91m[ ";
  for (it = vec.begin(); it != vec.end(); it++)
  {
    std::cout << "( " << it->first << ", " << it->second << " )";
    if (it + 1 != vec.end())
      std::cout << ", ";
  }
  std::cout << " ]\033[0m" << std::endl;
}
