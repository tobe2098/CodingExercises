#include "multiplication.hpp"

int bitwiseMult(int a, int b) {
  // Made by me, works with negatives and overflows, and less loops
  int result{};
  for (int position = 0; position < static_cast<int>(sizeof(int) * 8); position++) {
    if (((b >> position) & 1) == 1) {
      result = bitwiseAdd(result, a << position);
    }
  }
  return result;
}
