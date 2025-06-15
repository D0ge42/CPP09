#include "BitcoinExchange.hpp"
#include <algorithm>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <vector>

BitcoinExchange::BitcoinExchange(void)
{
  this->date = new t_date();
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


void BitcoinExchange::parseDateAndValue()
{
  std::string to_check;
  std::ifstream *input_file = this->infile;
  int i = -1;

  if (input_file->is_open())
  {
    while ( getline (*input_file,to_check))
    {
      if (++i == 0)
        continue;
      if (checkDate(to_check) && checkValue(to_check))
        std::cout << to_check << std::endl;
    }
    input_file->close();
  }
}

int BitcoinExchange::checkDate(std::string to_check)
{
  this->date->year =  to_check.substr(0,4);
  this->date->month = to_check.substr(5,2);
  this->date->day = to_check.substr(8,2);
  if (!is_year_valid(this->date->year) || !is_month_valid(this->date->month) || !is_day_valid(this->date->day))
  {
    std::cerr << "date not valid" << std::endl;
    return 0;
  }
  else
    return 1;
}

int BitcoinExchange::checkValue(std::string to_check)
{
  int date_delim = to_check.find_first_of('|');
  int new_line_idx = to_check.find_first_of('\n');

  int value = std::atoi(to_check.substr(date_delim + 1,new_line_idx - date_delim).c_str());
  if (value > 0  && value < 1000)
    return 1;
  else
  {
    std::cerr << "value not valid" << std::endl;
    return 0;
  }
}

int BitcoinExchange::is_year_valid(const std::string year)
{
  if (year.find_first_not_of("0123456789") != std::string::npos)
    return 0;
  return 1;
}

int BitcoinExchange::is_month_valid(const std::string month)
{
  int numeric_month = std::atoll(month.c_str());
  if (numeric_month < 1 || numeric_month > 12)
    return 0;
  if (month.find_first_not_of("0123456789") != std::string::npos)
    return 0;
  return 1;
}

int BitcoinExchange::is_day_valid(const std::string day)
{
  int numeric_day = std::atoll(day.c_str());
  if (numeric_day < 1 || numeric_day > 31)
    return 0;
  if (day.find_first_not_of("0123456789") != std::string::npos)
    return 0;
  return 1;
}


void BitcoinExchange::setDate(t_date *date)
{
  this->date = date;
}

void BitcoinExchange::setInputFile(std::ifstream &infile)
{
  this->infile = &infile;
}
