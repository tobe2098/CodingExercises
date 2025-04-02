#include <conio.h>
#include <iostream>
#include "addition.hpp"
#include "binSearch1.hpp"
#include "binSearchShifted.hpp"
#include "division.hpp"
#include "float_add.hpp"
#include "minOperations.hpp"
#include "multiplication.hpp"
#include "subtraction.hpp"
#include "utils.hpp"
static void displayBitOperations() {
  int a { 245 }, b { -15 };
  testBitwiseOp("+", a, b, &bitwiseAdd);
  testBitwiseOp("+", a, b, &bitwiseAddLoop);
  testBitwiseOp("-", a, b, &bitwiseSub);
  testBitwiseOp("-", a, b, &bitwiseSubsLoop);
  testBitwiseOp("x", a, b, &bitwiseMult);
  testBitwiseOp("/", a, b, &bitwiseDiv);
  std::cout << "bitwiseAdd\n";
  boolTest<int>([](int a, int b) { return a + b; }, a, b, &bitwiseAdd);
  std::cout << "bitwiseSub\n";
  boolTest<int>([](int a, int b) { return a - b; }, a, b, &bitwiseSub);
  std::cout << "bitwiseMult\n";
  boolTest<int>([](int a, int b) { return a * b; }, a, b, &bitwiseMult);
  std::cout << "bitwiseDiv\n";
  boolTest<int>([](int a, int b) { return a / b; }, a, b, &bitwiseDiv);
  std::cout << divide32(INT_MIN, -1) << '\n';

  std::cout << "Float addition\n";
  double x { 0.1 }, y { -0.2 };
  boolTest<double>([](double a, double b) { return a + b; }, x, y, &add64);
}

int main() {
  // searchRange({1, 2, 3, 4, 5, 6, 7, 8}, 6);
  std::cout << search({ 2, 5, 6, 0, 0, 1, 2 }, 0);
  std::cout << "Float addition\n";
  double x { 0.1 }, y { -0.2 };
  boolTest<double>([](double a, double b) { return a + b; }, x, y, &add64);
  std::cout << add64(0.1, 0.2) << '\n';
  std::cout << add64(0.1, -0.2) << '\n';
  std::cout << add64(-0.2, -0.2) << '\n';
  (void)_getch();
  return 0;
}
