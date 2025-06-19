#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>
#include <map>
#include <string>

#define ERR_OPEN_FILE "\033[1;91mError: could not open file\033[0m"
#define ERR_BAD_INPUT "\033[1;91mError: bad input\033[0m"
#define ERR_NEG_VALUE "\033[1;91mError: value is negative\033[0m"
#define ERR_OF_VALUE "\033[1;91mError: value overflow\033[0m"
#define ERR_LRG_VALUE "\033[1;91mError: value too large\033[0m"
#define ERR_ERL_DATE "\033[1;91mError: no earlier date found for \033[0m"
#define ERR_STR_LEN "\033[1;91mError: date string must be exactly 10 chars (yyyy-mm-dd)\033[0m"
#define ERR_YMD_INVALID "\033[1;91mError: Year month or date are invalid \033[0m"
#define ERR_ONLY_DIG "\033[1;91mError: value can only contain digits \033[0m"
#define PRINT "print"
#define NO_PRINT "no_print"

typedef enum e_type
{
  NONE = 1 << 0,
  E_BAD_INPUT = 1 << 1,
  E_NEG_VALUE = 1 << 2,
  E_OF_VALUE = 1 << 3,
  E_LRG_VALUE = 1 << 4,
  E_ERL_DATE = 1 << 5,
  E_STR_LEN = 1 << 6,
  E_YMD_INV = 1 << 7,
  E_ONLY_DIG = 1 << 8
} t_type;

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
    int err_type;

  public:
    BitcoinExchange(void);
    BitcoinExchange(const BitcoinExchange &other);
    ~BitcoinExchange(void);

    BitcoinExchange &operator=(const BitcoinExchange &other);


    std::string getDate (std::string date, char delim);
    float getValue (std::string date, char delim);
    void setInputFile(std::ifstream &ref);
    std::map <std::string, float> fillMapWithDates();
    void printConversion();
    void printMap();
    void setErrType(std::string date, float value, char delim);
    void printErr(std::string to_compare,int value);

    bool is_year_valid(std::string date);
    bool is_month_valid(std::string date);
    bool is_day_valid(std::string date);
    bool is_err(std::string print, std::string date, float value);

};

// check if date and value are valid
// if no just return error
// else
// store them in t_value

#endif
