#pragma once

#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "utils.hpp"

constexpr uint64_t no_float_sign { 0x7FFFFFFFFFFFFFFF };
// For 64 bits floats
float ReverseFloat(const float inFloat);

struct Float64 {
    unsigned int       sign : 1;
    unsigned int       exponent : 11;
    unsigned long long mantissa : 52;
};

double add64(double num1, double num2);
double add64_2(double num1, double num2);
