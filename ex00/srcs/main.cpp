#include "BitcoinExchange.hpp"

int main(int ac, char **av)
{
  if (ac != 0x2)
    return 0;

  BitcoinExchange be;
  std::ifstream  in (av[1]);

  be.setInputFile(in);
  be.fillMapWithDates();
  be.printConversion();
}
