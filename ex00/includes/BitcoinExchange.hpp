#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <fstream>

struct t_date
{

  std::string year;
  std::string month;
  std::string day;
};

class BitcoinExchange
{
  private:
    t_date *date;
    std::ifstream *infile;

  public:
    BitcoinExchange(void);
    BitcoinExchange(const BitcoinExchange &other);
    ~BitcoinExchange(void);

    BitcoinExchange &operator=(const BitcoinExchange &other);

    // Public Methods.
    int checkDate(std::string to_check);
    int checkValue(std::string to_check);
    int checkFormat(std::string to_check);
    void parseDateAndValue();

    int is_year_valid(const std::string year);
    int is_month_valid(const std::string year);
    int is_day_valid(const std::string year);


    // getters setters
    void setInputFile(std::ifstream  &infile);
    void setDate(t_date *date);
};

#endif
