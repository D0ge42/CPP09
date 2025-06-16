#include "BitcoinExchange.hpp"
#include <iostream>
#include <fstream>

int main(int ac, char **av)
{
  BitcoinExchange bp;
  if (ac != 2)
  {
    std::cerr << "Usage: ./btc inputfile.txt" << std::endl;
    return 0;
  }

  // std::string line;
  // std::ifstream database ("srcs/data.csv");
  // if (database.is_open())
  // {
  //   while ( getline (database,line) )
  //   {
  //     std::cout << line << '\n';
  //   }
  //   database.close();
  // }
  //
  std::ifstream input_file (av[1]);
  bp.setInputFile(input_file);
  bp.printConversion();
}
