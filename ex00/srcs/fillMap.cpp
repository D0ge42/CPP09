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
 * Ex: 1999-06-01 not found, found 1999-07-01 --> it -- and we get the spot where the date should be.
 * */

void BitcoinExchange::printConversion()
{
  std::string line;
  std::map<std::string, float>map;
  std::map<std::string, float>::iterator it;

  map = fillMapWithDates();

  if (this->infile->is_open() == false)
  {
    std::cerr << ERR_OPEN_FILE << std::endl;
    return ;
  }

  while(std::getline(*this->infile,line))
  {
    std::string date = getDate(line,' ');
    float value = getValue(line,'|');

    if (date == "date")
      continue;

    setErrType(date,value,'|');
    if (is_err(PRINT,date,value) == true)
        continue;

    it = map.lower_bound(date);
    if (it == map.end() || it->first != date)
    {
      if (it == map.begin())
      {
          std::cerr << ERR_ERL_DATE << date << std::endl;
          continue;
      }
      --it;
    }
    std::cout << it->first << " => " << value << " = " << value * it->second << std::endl;
  }
}


/* Function used to fill a map with key value pair from database.csv*/

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
      std::string date = getDate(line,',');
      float value = getValue(line,',');
      setErrType(date,value,',');
      if (is_err(NO_PRINT,date,value) == true)
        continue;
      map.insert(std::make_pair(date,value));
    }
    db.close();
  }
  return map;
}
