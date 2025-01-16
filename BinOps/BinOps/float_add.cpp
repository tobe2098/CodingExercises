#include "float_add.hpp"

float ReverseFloat(const float inFloat) {
  float retVal;
  char* floatToConvert = (char*)&inFloat;
  char* returnFloat    = (char*)&retVal;

  // swap the bytes into a temporary buffer
  returnFloat[0] = floatToConvert[3];
  returnFloat[1] = floatToConvert[2];
  returnFloat[2] = floatToConvert[1];
  returnFloat[3] = floatToConvert[0];

  return retVal;
}

double add64(double num1, double num2) {
  // Following IEEE 754 standard
  // 1 sign bit, 11 bit exponent, 52 bit mantissa
  // Float64 n1 { .num = num1 }, n2 { .num = num2 };
  uint64_t n1, n2;
  memcpy(&n1, &num1, sizeof(double));
  memcpy(&n2, &num2, sizeof(double));
  if ((n1 & no_float_sign) < (n2 & no_float_sign)) {
    n1 ^= n2;
    n2 ^= n1;
    n1 ^= n2;
  }
  uint64_t s1, s2;
  uint64_t e1, e2;
  uint64_t m1, m2;
  s1 = (n1 >> 63);
  s2 = (n2 >> 63);
  e1 = (n1 >> 52) & 0x7FF;
  e2 = (n2 >> 52) & 0x7FF;
  m1 = (n1 & 0xFFFFFFFFFFFFF) | (1ull << 52);
  m2 = (n2 & 0xFFFFFFFFFFFFF) | (1ull << 52);
  // We assume n1 is greater always
  // Section on exponents
  // We can assume first exponent is bigger
  // uint64_t exp_diff { e1 ^ e2 }, carry { (exp_diff & e2) << 1 };
  // while (carry) {
  //   exp_diff = (exp_diff ^ carry);
  //   carry    = (exp_diff & carry) << 1;
  // }
  m2 >>= (e1 - e2);
  // Actual operation
  // How do I do it? Branch substraction and addition? Do I use 2's complement?
  if (s1) {
    m1 = (~m1) + 1;
  }
  if (s2) {
    m2 = (~m2) + 1;
  }
  m1 ^= m2;
  uint64_t carry = ((m1 ^ m2) & m2) << 1;
  while (carry) {
    m1 ^= carry;
    carry = ((m1 ^ carry) & carry) << 1;
  }
  // Now we have to find the first one.
  if (s1) {
    m1 = ~(m1 - 1);
  }
  if (m1 & (1ull << 53)) {
    e1++;
    if (e1 & 0x800) {
      m1 = 0xFFFFFFFFFFFFFFFF;
      memcpy(&num1, &n1, sizeof(double));
      return num1;
    }
    m1 >>= 1;
  } else if (!(m1 & (1ull << 52)) && e1) {
    if (!m1) {
      return 0.0;
    }
    while (!((1ull << 52) & m1)) {
      e1--;
      m1 <<= 1;
    }
  }
  n1 |= (s1 << 63);
  n1 |= (e1 << 52);
  n1 |= (m1 & ((1ull << 52) - 1));
  memcpy(&num1, &n1, sizeof(double));
  return num1;
}

double add64_2(double num1, double num2) {
  // Following IEEE 754 standard
  // 1 sign bit, 11 bit exponent, 52 bit mantissa
  // Float64 n1 { .num = num1 }, n2 { .num = num2 };
  uint64_t n1, n2;
  memcpy(&n1, &num1, sizeof(double));
  memcpy(&n2, &num2, sizeof(double));
  if ((n1 & no_float_sign) < (n2 & no_float_sign)) {
    n1 ^= n2;
    n2 ^= n1;
    n1 ^= n2;
  }

  uint64_t s1, s2;
  uint64_t e1, e2;
  uint64_t m1, m2;
  s1 = (n1 >> 63);
  s2 = (n2 >> 63);
  e1 = (n1 >> 52) & 0x7FF;
  e2 = (n2 >> 52) & 0x7FF;
  m1 = (n1 & 0xFFFFFFFFFFFFF) | (0xFFFFFFFFFFFFF + 1);
  m2 = (n2 & 0xFFFFFFFFFFFFF) | (0xFFFFFFFFFFFFF + 1);
  // We assume n1 is greater always
  // Section on exponents
  // We can assume first exponent is bigger
  uint64_t exp_diff { e1 ^ e2 }, carry { (exp_diff & e2) << 1 };
  while (carry) {
    exp_diff = (exp_diff ^ carry);
    carry    = exp_diff & carry;
    carry <<= 1;
  }
  m2 >>= exp_diff;
  //
  uint32_t diff_sign = (s2 != s1);
  if (diff_sign) {
    // Substract
  } else {
    // Add
  }
  return 0.0;
}