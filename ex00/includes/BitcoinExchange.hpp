#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <map>
#include <ostream>
#include <string>

struct t_date
{

  std::string year;
  std::string month;
  std::string day;
};

struct t_value
{
  std::string date;
  float conversion_rate;
};

class BitcoinExchange
{
  private:
    t_date *date;
    t_value *value;
    std::ifstream *infile;
    std::map<t_value *, float> map;

  public:
    BitcoinExchange(void);
    BitcoinExchange(const BitcoinExchange &other);
    ~BitcoinExchange(void);

    BitcoinExchange &operator=(const BitcoinExchange &other);


    bool checkDate (std::string date);
    bool checkValue (std::string date);

};

// check if date and value are valid
// if no just return error
// else
// store them in t_value

#endif
