#include "BitcoinExchange.hpp"
#include <iostream>

int main(int ac, char **av)
{
  if (ac != 0x2)
  {
    std::cerr << ERR_OPEN_FILE << std::endl;
    return 0;
  }

  BitcoinExchange be;
  std::ifstream  in (av[1]);

  be.setInputFile(in);
  be.fillMapWithDates();
  be.printConversion();
}
