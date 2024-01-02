#include <conio.h>
#include <iostream>
int getBit(int num, int position) {
  return (num >> position) & 1;
}

// Function to set the bit at a specific position
void setBit(int &num, int position, int bit) {
  if (bit == 1)
    num |= (1 << position);
  else
    num &= ~(1 << position);
}

int bitwiseMultLoop(int A, int B) {
  // For each bit of the multiplicator, if it is equal to 1,
  // add the multiplicand shifted by the bits position.
  return 0;
}
int bitwiseMult(int a, int b) {
  // Made by me, works with negatives and overflows, and less loops
  int carry_over{}, placeholder{}, result{};
  carry_over = (~a) & b;
  result     = a ^ b;
  while (carry_over != 0) {
    carry_over <<= 1;
    placeholder = (~result) & carry_over;
    result ^= carry_over;
    carry_over = placeholder;
  }
  return result;
}

int main() {
  int a{245}, b{-15};
  std::cout << "(" << a << ")+(" << b << ")= " << bitwiseMult(a, b) << std::endl;
  std::cout << "(" << a << ")+(" << b << ")= " << bitwiseMultLoop(a, b) << std::endl;
  _getch();
  return 0;
}