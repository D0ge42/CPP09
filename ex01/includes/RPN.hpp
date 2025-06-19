#ifndef RPN_HPP
#define RPN_HPP

#include <stack>
#include <string>
#define ERR_UNKW_CHARS "Error: input string can only contain '1234567890 */+-'"
#define ERR_NUM_ARGV "Error: invalid number of arguments: ./rpn polish notation"
#define ERR_MAL_EXPR "Error: malformed expression. Num of sign must be == num_of_digits -  1"
#define ERR_NUM_COUNT "Error: not enough numbers in the stack"

class RPN
{
  private:
    size_t num_digits;
    size_t num_sign;

  public:
    RPN(void);
    RPN(const RPN &other);
    ~RPN(void);

    RPN &operator=(const RPN &other);

    // Parser
    bool parseString(const char *arg);

    // Calculate
    void calculate(const char *str);
};

#endif
