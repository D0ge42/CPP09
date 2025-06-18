#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <iostream>
#include <stdexcept>

std::string BitcoinExchange::getDate(std::string to_check)
{
  std::string date;
  unsigned long end_date = to_check.find_first_of(' ');
  try
  {
    date = to_check.substr(0,end_date);
  }
  catch(std::out_of_range &e)
  {
    std::cout << e.what() << std::endl;
  }

  return date;
}


float BitcoinExchange::getValue(std::string date)
{
  std::string str_conv;
  float num;
  unsigned long value_idx;
  // unsigned long first_dig_idx;

  value_idx = date.find_first_of('|') + 2;
  // first_dig_idx = date.find_first_of(value_idx,date.find_first_not_of(' '));
  num = std::atof(date.substr(value_idx).c_str());

  return num;
}

bool BitcoinExchange::is_year_valid(std::string date)
{
  std::string year = date.substr(0,4);
  if (year.find_first_not_of("0123456789") != std::string::npos)
    return false;
  return true;
}


bool BitcoinExchange::is_month_valid(std::string date)
{
  std::string month = date.substr(5,2);
  int numeric_month = std::atoi(month.c_str());

  if (month.find_first_not_of("0123456789") != std::string::npos)
    return false;

  if (numeric_month < 1 || numeric_month > 12)
    return false;

  return true;
}


bool BitcoinExchange::is_day_valid(std::string date)
{
  std::string day = date.substr(8,2);
  int numeric_day = std::atoi(day.c_str());

  if (day.find_first_not_of("0123456789") != std::string::npos)
    return false;

  if (numeric_day < 1 || numeric_day > 31)
    return false;

  return true;
}
