#include "division.hpp"

int bitwiseDiv(int dividend, int divisor) {
  // My version but incorrect, it does not handle INT_MIN as an input
  int  result{};
  bool negative{false};
  if (dividend < 0) {
    negative = true;
    dividend = (~dividend) + 1;
  }

  if (divisor < 0) {
    if (negative)
      negative = false;
    else
      negative = true;
    divisor = (~divisor) + 1;
  }

  if (divisor == 0) {
    // Handle division by zero error
    _getch();
    throw; // Or some error code indicating division by zero
  }
  while (dividend >= divisor) {
    int subtractor  = divisor;
    int quotientBit = 1;

    while ((subtractor << 1) <= dividend) {
      subtractor <<= 1;
      quotientBit <<= 1;
    }

    dividend = bitwiseSub(dividend, subtractor);
    result   = bitwiseAdd(result, quotientBit);
  }
  if (negative) {
    result = ~(result) + 1;
    return result;
  } else {
    return result;
  }
}

// int bitwiseDiv2(int a, int b) {
//   // CHATPGT but incorrect, it does not handle INT_MIN as an input among other things
//   bool negative1{false}, negative2{false};
//   int  result = 0;

//   if (a < 0) {
//     negative1 = true;
//     a         = (~a) + 1;
//   }

//   if (b < 0) {
//     negative2 = true;
//     b         = (~b) + 1;
//   }

//   if (b == 0) {
//     // Handle division by zero error
//     _getch();
//     throw; // Or some error code indicating division by zero
//   }

//   while (a >= b) {
//     int subtractor  = b;
//     int quotientBit = 1;

//     while ((subtractor << 1) <= a) {
//       subtractor <<= 1;
//       quotientBit <<= 1;
//     }

//     a      = bitwiseSub(a, subtractor);
//     result = bitwiseAdd(result, quotientBit);
//   }

//   return result;
// }

int divide32_c(int a, int b) {
  // My version, only 32 bits to work on LeetCode problem
  unsigned int result = 0, dividend = a, divisor = b;
  bool         negative = false;
  if (a < 0) {
    negative = true;
    dividend = (~(unsigned int)a) + 1;
  }
  if (b < 0) {
    if (negative)
      negative = false;
    else
      negative = true;
    divisor = (~(unsigned int)b) + 1;
  }
  while (dividend >= divisor) {
    unsigned int subtractor  = divisor;
    unsigned int quotientBit = 1;

    while ((subtractor << 1) <= dividend && (subtractor << 1) != 0) {
      subtractor <<= 1;
      quotientBit <<= 1;
    }

    dividend -= subtractor;
    result += quotientBit;
  }
  if (negative) {
    if (result > (unsigned int)INT_MAX)
      return INT_MIN;
    return ~(result) + 1;
  } else {
    if (result > (unsigned int)INT_MAX)
      return INT_MAX;
    else
      return result;
  }
}

int divide32(int a, int b) {
  // My version, only 32 bits to work on LeetCode problem
  unsigned int result{}, dividend{std::bit_cast<unsigned int>(a)}, divisor{std::bit_cast<unsigned int>(b)};
  bool         negative{false};
  if (a < 0) {
    negative = true;
    dividend = (~std::bit_cast<unsigned int>(a)) + 1;
  }
  if (b < 0) {
    if (negative)
      negative = false;
    else
      negative = true;
    divisor = (~std::bit_cast<unsigned int>(b)) + 1;
  }
  while (dividend >= divisor) {
    unsigned int subtractor{divisor};
    unsigned int quotientBit{};

    while ((subtractor << 1) <= dividend && (subtractor << 1) != 0) {
      subtractor <<= 1;
      quotientBit++;
    }
    quotientBit = 1 << quotientBit;
    dividend -= subtractor;
    result += quotientBit;
  }
  if (negative) {
    if (result > std::bit_cast<unsigned int>(INT_MAX))
      return INT_MIN;
    return std::bit_cast<int>(~(result) + 1);
  } else {
    if (result > std::bit_cast<unsigned int>(INT_MAX))
      return INT_MAX;
    else
      return std::bit_cast<int>(result);
  }
}
