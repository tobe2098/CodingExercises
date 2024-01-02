#pragma once
#include <iostream>
#include <string>
int  getBit(int num, int position);
void setBit(int &num, int position, int bit);

void testBitwiseOp(std::string symbol, int positive, int negative, int (*func)(int, int));
