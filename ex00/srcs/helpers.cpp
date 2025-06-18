#include "BitcoinExchange.hpp"
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <stdexcept>
#include <string>
#include <utility>

void BitcoinExchange::setErrType(std::string date, float value)
{
  unsigned long value_idx = 0;
  // unsigned long first_dig_idx = 0;
  std::string  str_conv = "";
  try
  {
    value_idx = date.find_first_of('|') + 2;
  }
  catch (std::out_of_range &e)
  {
    this->err_type = E_BAD_INPUT;
  }
  try
  {
    // first_dig_idx = date.find_first_of(value_idx,date.find_last_of(' '));
    std::string  str_conv = date.substr(value_idx);
  }
  catch (std::out_of_range &e)
  {
    this->err_type = E_BAD_INPUT;
  }

  if (date.length() != 10)
    this->err_type = E_STR_LEN;
  else if (!is_year_valid(date) || !is_month_valid(date) || !is_day_valid(date))
    this->err_type = E_YMD_INV;
  else if (str_conv.find_first_not_of("0123456789+-.") != std::string::npos)
    this->err_type = E_ONLY_DIG;
  else if (date == ERR_YMD_INVALID || date == ERR_STR_LEN)
    this->err_type = E_BAD_INPUT;
  else if (value < 0 )
    this->err_type = E_NEG_VALUE;
  else if (value > 2147483647.0)
    this->err_type = E_OF_VALUE;
  else if (value > 1000)
    this->err_type = E_LRG_VALUE;
  else
    this->err_type = NONE;

}

void BitcoinExchange::printErr(std::string to_compare, int value)
{
  if (this->err_type & E_BAD_INPUT)
  {
        std::cerr << ERR_BAD_INPUT << " => " << to_compare << std::endl;
  }
  if (this->err_type & E_NEG_VALUE)
  {
        std::cerr << ERR_NEG_VALUE << " => " << value << std::endl;
  }
  if (this->err_type & E_OF_VALUE)
  {
        std::cerr << ERR_OF_VALUE << " => " << value << std::endl;
  }
  if (this->err_type & E_LRG_VALUE)
  {
        std::cerr << ERR_LRG_VALUE << " => " << value << std::endl;
  }
  if (this->err_type & E_STR_LEN)
  {
        std::cerr << ERR_STR_LEN << " => " << to_compare << std::endl;
  }
  if (this->err_type & E_YMD_INV)
  {
        std::cerr << ERR_YMD_INVALID << " => " << to_compare << std::endl;
  }
  if (this->err_type & E_ONLY_DIG)
  {
        std::cerr << ERR_ONLY_DIG << " => " << value << std::endl;
  }
}

void BitcoinExchange::printMap()
{
  std::map<std::string,float>::iterator it;
  for (it  = this->map.begin(); it != this->map.end(); it++)
  {
    std::cout << it->first << ": " << it->second << std::endl;
  }
}
