#pragma once
#include <functional>
#include <iostream>
#include <string>
int  getBit(int num, int position);
void setBit(int &num, int position, int bit);

void testBitwiseOp(std::string symbol, int positive, int negative, int (*func)(int, int));

template <class U> void boolTest(std::function<U(U, U)> operation_lambda, U arg1, U arg2, U (*func)(U, U)) {
  std::cout << "(" << arg1 << ")"
            << "(" << arg2 << ")-> " << std::boolalpha << (func(arg1, arg2) == operation_lambda(arg1, arg2)) << std::endl;
  std::cout << "(" << arg1 << ")"
            << "(" << arg1 << ")-> " << std::boolalpha << (func(arg1, arg1) == operation_lambda(arg1, arg1)) << std::endl;
  std::cout << "(" << arg2 << ")"
            << "(" << arg2 << ")-> " << std::boolalpha << (func(arg2, arg2) == operation_lambda(arg2, arg2)) << std::endl;
}
