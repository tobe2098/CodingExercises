#pragma once
#include <vector>
#include <unordered_map>
#include <string>
int oper(int a, int b, char op);
std::vector<int> rec(std::vector<int> res, std::string expression);
std::vector<int> rec2(std::string& expression, std::vector<std::vector<std::vector<int>>>& memo, int begin, int end);

std::vector<int> diffWaysToComputeRec(std::string expression);
std::vector<int> diffWaysToComputeMemo(std::string expression);
std::vector<int> diffWaysToComputeTab(std::string expression);

