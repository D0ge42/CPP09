#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <map>
#include <string>

#define E_BI "\033[1;91mError: bad input\033[0m"
#define E_LZ "\033[1;91mError: value is negative\033[0m"
#define E_OF "\033[1;91mError: value overflow\033[0m"
#define E_OT "\033[1;91mError: value too large\033[0m"

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
    std::ifstream *infile;
    std::map<std::string, float> map;

  public:
    BitcoinExchange(void);
    BitcoinExchange(const BitcoinExchange &other);
    ~BitcoinExchange(void);

    BitcoinExchange &operator=(const BitcoinExchange &other);


    std::string checkDate (std::string date);
    float checkValue (std::string date);
    void setInputFile(std::ifstream &ref);
    std::map <std::string, float> fillMapWithDates();
    void printConversion();
    void printMap();


};

// check if date and value are valid
// if no just return error
// else
// store them in t_value

#endif
