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

int bitwiseAddLoop(int A, int B) {
  // CHATGPT, works, but 32 loops
  int result = 0;
  int carry  = 0;

  for (int position = 0; position < static_cast<int>(sizeof(int) * 8); ++position) { // Times 8 because sizeof os bytes
    int bitA = getBit(A, position);
    int bitB = getBit(B, position);

    int sum = bitA ^ bitB ^ carry;
    carry   = (bitA & bitB) | (bitA & carry) | (bitB & carry);

    setBit(result, position, sum);
  }

  return result;
}
int bitwiseAdd(int a, int b) {
  // Made by me, works with negatives and overflows, and less loops
  int carry_over{}, placeholder{}, result{};
  carry_over = a & b;
  result     = a ^ b;
  while (carry_over != 0) {
    carry_over <<= 1;
    placeholder = result & carry_over;
    result ^= carry_over;
    carry_over = placeholder;
  }
  return result;
}

int main() {
  int a{-12}, b{-12};
  std::cout << "(" << a << ")+(" << b << ")= " << bitwiseAddLoop(a, b) << std::endl;
  _getch();
  return 0;
  return 0;
}