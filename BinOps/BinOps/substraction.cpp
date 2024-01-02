#include "substraction.hpp"
#include "addition.hpp"
#include <conio.h>
#include <iostream>

int bitwiseSubsLoop(int A, int B) {
  // CHATGPT, works, but 32 loops
  return 0;
}

int bitwiseSubs(int a, int b) {
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
