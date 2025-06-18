#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <iostream>

static bool is_year_valid(std::string date);
static bool is_month_valid(std::string date);
static bool is_day_valid(std::string date);

std::string BitcoinExchange::checkDate(std::string to_check)
{
  std::string date;
  unsigned long end_date = to_check.find_first_of(' ');
  date = to_check.substr(0,end_date);

  if (date.length() != 10)
    return "";
  if (!is_year_valid(date) || !is_month_valid(date) || !is_day_valid(date))
    return "";
  return date;
}


float BitcoinExchange::checkValue(std::string date)
{
  std::string str_conv;
  float num_conv;
  unsigned long value_idx;

  value_idx = date.find_first_of('|') + 2;
  str_conv = date.substr(value_idx);
  num_conv = std::atof(date.substr(value_idx).c_str());

  if (str_conv.find_first_not_of("0123456789+-.") != std::string::npos)
    return 0.0;
  return num_conv;
}


static bool is_year_valid(std::string date)
{
  std::string year = date.substr(0,4);
  if (year.find_first_not_of("0123456789") != std::string::npos)
    return false;
  return true;
}


static bool is_month_valid(std::string date)
{
  std::string month = date.substr(5,2);
  int numeric_month = std::atoi(month.c_str());

  if (month.find_first_not_of("0123456789") != std::string::npos)
    return false;

  if (numeric_month < 1 || numeric_month > 12)
    return false;

  return true;
}


static bool is_day_valid(std::string date)
{
  std::string day = date.substr(8,2);
  int numeric_day = std::atoi(day.c_str());

  if (day.find_first_not_of("0123456789") != std::string::npos)
    return false;

  if (numeric_day < 1 || numeric_day > 31)
    return false;

  return true;
}
