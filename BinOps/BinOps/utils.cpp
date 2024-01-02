#include "utils.hpp"
int getBit(int num, int position) {
  return (num >> position) & 1;
}
void setBit(int &num, int position, int bit) {
  if (bit == 1)
    num |= (1 << position);
  else
    num &= ~(1 << position);
}

void testBitwiseOp(std::string symbol, int positive, int negative, int (*func)(int, int)) {
  std::cout << "(" << 2 << ")" << symbol << "(" << positive << ")= " << func(2, positive) << std::endl;
  std::cout << "(" << -2 << ")" << symbol << "(" << negative << ")= " << func(-2, negative) << std::endl;
  std::cout << "(" << 1 << ")" << symbol << "(" << negative << ")= " << func(1, negative) << std::endl;
  std::cout << "(" << negative << ")" << symbol << "(" << -negative << ")= " << func(negative, -negative) << std::endl;
  std::cout << "(" << positive << ")" << symbol << "(" << negative << ")= " << func(positive, negative) << std::endl;
}
