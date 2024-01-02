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
  std::cout << "(" << positive << ")" << symbol << "(" << 2 << ")= " << func(positive, 2) << std::endl;
  std::cout << "(" << negative << ")" << symbol << "(" << -2 << ")= " << func(negative, -2) << std::endl;
  std::cout << "(" << negative << ")" << symbol << "(" << 1 << ")= " << func(negative, 1) << std::endl;
  std::cout << "(" << negative << ")" << symbol << "(" << -negative << ")= " << func(negative, -negative) << std::endl;
  std::cout << "(" << positive << ")" << symbol << "(" << negative << ")= " << func(positive, negative) << std::endl;
}
