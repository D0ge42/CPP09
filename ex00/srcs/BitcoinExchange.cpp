#include "BitcoinExchange.hpp"
#include <algorithm>
#include <cstdio>
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


void BitcoinExchange::printConversion()
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
      {
        std::cout << findDate(to_check);
      }
    }
    input_file->close();
  }
}

std::string BitcoinExchange::findDate(std::string date)
{
  std::string to_compare;
  const char *db = "srcs/data.csv";
  std::ifstream input_file(db);
  int i = -1;

  if (input_file.is_open())
  {
    while ( getline (input_file,to_compare))
    {
      if (++i == 0)
        continue;
      std::cout << "Comparing: " << to_compare.substr(0,to_compare.find_first_of(','))
        << "with " << date.substr(0,date.find_first_of(' ')) << std::endl;
      while (getline(input_file, to_compare))
      {
        if (to_compare.substr(to_compare.find_first_of(',')) == date.substr(0,date.find_first_of(' ')))
        {
          return to_compare.substr(0,to_compare.find_first_of(','));
        }
        else
          return "Couldn't find a match\n";
      }
    }
    input_file.close();
  }
  return "could not open file\n";
}

int BitcoinExchange::checkDate(std::string to_check)
{
  this->date->year =  to_check.substr(0,to_check.find_first_of('-'));
  this->date->month = to_check.substr(to_check.find_first_of('-') + 1,2);
  this->date->day = to_check.substr(to_check.find_first_of('-') + 4,2);
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
