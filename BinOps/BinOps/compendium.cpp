#include <conio.h>
#include <iostream>

int help() {
  // Bitwise AND
  int a          = 5;                                      // 0101 in binary
  int b          = 3;                                      // 0011 in binary
  int result_and = a & b;                                  // Performs bitwise AND
  std::cout << "Bitwise AND: " << result_and << std::endl; // Output: 1

  // Bitwise OR
  int result_or = a | b;                                 // Performs bitwise OR
  std::cout << "Bitwise OR: " << result_or << std::endl; // Output: 7

  // Bitwise XOR
  int result_xor = a ^ b;                                  // Performs bitwise XOR
  std::cout << "Bitwise XOR: " << result_xor << std::endl; // Output: 6

  // Bitwise NOT
  int c          = 10;                                     // 1010 in binary
  int result_not = ~c;                                     // Performs bitwise NOT
  std::cout << "Bitwise NOT: " << result_not << std::endl; // Output: -11 (due to two's complement representation)

  // So, ~int +1 is the same as *=1

  //-----------------------------------------------------------------

  // Left Shift
  int num        = 5;                                     // 0101 in binary
  int left_shift = num << 2;                              // Left shifts by 2 positions
  std::cout << "Left Shift: " << left_shift << std::endl; // Output: 20 (10100 in binary)
  // Same as *=2

  // Right Shift
  int num2        = 20;                                     // 10100 in binary
  int right_shift = num2 >> 2;                              // Right shifts by 2 positions
  std::cout << "Right Shift: " << right_shift << std::endl; // Output: 5 (0101 in binary)
  // Same as /=2

  //-----------------------------------------------------------------

  // Clearing a Bit
  int number            = 10;                                 // 1010 in binary
  int position_to_clear = 1;                                  // Clear bit at position 1 (from the right)
  number &= ~(1 << position_to_clear);                        // Clear the bit at the given position
  std::cout << "After clearing bit: " << number << std::endl; // Output: 8 (1000 in binary)

  // Setting a Bit
  int position_to_set = 2;                                   // Set bit at position 2 (from the right, zero index)
  number |= (1 << position_to_set);                          // Set the bit at the given position
  std::cout << "After setting bit: " << number << std::endl; // Output: 12 (1100 in binary)

  // Toggling a Bit
  int position_to_toggle = 3;                                 // Toggle bit at position 3 (from the right)
  number ^= (1 << position_to_toggle);                        // Toggle the bit at the given position
  std::cout << "After toggling bit: " << number << std::endl; // Output: 4 (0100 in binary)
  _getch();
  return 0;
}
