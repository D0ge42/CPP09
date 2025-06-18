#include "BitcoinExchange.hpp"
#include <fstream>

BitcoinExchange::BitcoinExchange(void)
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
  (void)other;
}

BitcoinExchange::~BitcoinExchange(void)
{

}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
  (void)other;
  return (*this);
}

void BitcoinExchange::setInputFile(std::ifstream &ref)
{
  this->infile = &ref;
}
