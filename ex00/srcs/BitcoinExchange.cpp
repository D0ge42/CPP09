#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
  this->value = new t_value();
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other)
{
  (void)other;
}

BitcoinExchange::~BitcoinExchange(void)
{

  delete this->value;
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
  (void)other;
  return (*this);
}
