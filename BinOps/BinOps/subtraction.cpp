#include "subtraction.hpp"
#include "addition.hpp"
#include <conio.h>
#include <iostream>

int bitwiseSubsLoop(int A, int B) {
  // CHATGPT, works, but 32 loops
  int result = 0;
  int carry  = 0;

  for (int position = 0; position < static_cast<int>(sizeof(int) * 8); ++position) { // Times 8 because sizeof os bytes
    int bitA = getBit(A, position);
    int bitB = getBit(B, position);

    int sum = bitA ^ bitB ^ carry;
    carry   = (carry & bitB) || (carry & ~(bitA)) || (bitB & ~(bitA));

    setBit(result, position, sum);
  }
  return result;
}

int bitwiseSub(int a, int b) {
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
