#include "BitcoinExchange.hpp"
#include <algorithm>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <map>
#include <set>
#include <string>
#include <utility>

/* lower_bound:
 * This function returns the first element of a subsequence of elements that matches the given key.
 * If unsuccessful it returns an iterator pointing to the first element that has a greater value
 * than given key or end() if no such element exists.
 * Ex: 1999-06-01 not found, found 1999-07-01 --> it -- and we get the spot where the date should
 * be.*/


void BitcoinExchange::printConversion()
{
  std::string line;
  std::map<std::string, float>map;
  std::map<std::string, float>::iterator it;

  map = fillMapWithDates();
  if (this->infile->is_open() == false)
    return ;

  while(std::getline(*this->infile,line))
  {
    std::string to_compare = checkDate(line);
    float value = checkValue(line);

      if (to_compare == "")
      {
        std::cerr << E_BI << " => " << to_compare << std::endl;
        continue;
      }
      else if (value < 0 )
      {
        std::cerr << E_LZ << " => " << value << std::endl;
        continue;
      }
      else if (value > 2147483647.0)
      {
        std::cerr << E_OF << " => " << value << std::endl;
        continue;
      }
      else if (value > 1000)
      {
        std::cerr << E_OT << " => " << value << std::endl;
        continue;
      }

      it = map.lower_bound(to_compare);
      if (it == map.end() || it->first != to_compare)
      {
        if (it == map.begin())
        {
            std::cerr << "Error: no earlier date found for " << to_compare << std::endl;
            continue;
        }
        --it;
      }
      std::cout << it->first << " => " << value << " = " << value * it->second << std::endl;
  }
}

std::map <std::string, float> BitcoinExchange::fillMapWithDates()
{
  std::ifstream db("srcs/data.csv");
  std::string line;
  std::map<std::string,float> map;
  std::map<std::string,float>::iterator it;

  if (db.is_open())
  {
    while(std::getline(db,line))
    {
      unsigned long idx = line.find_first_of(',');
      std::string date = line.substr(0,idx);
      float value = std::atof(line.substr(idx + 1).c_str());
      map.insert(std::make_pair(date,value));
    }
    db.close();
  }
  return map;
}

void BitcoinExchange::printMap()
{
  std::map<std::string,float>::iterator it;
  for (it  = this->map.begin(); it != this->map.end(); it++)
  {
    std::cout << it->first << ": " << it->second << std::endl;
  }
}
