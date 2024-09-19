#pragma once
#include <vector>
#include <unordered_map>
#include <string>
int oper(int a, int b, char op);
void rec(std::vector<int>& sol, std::string& expression, std::unordered_map<std::string, int>& map, int opcount);
std::vector<int> diffWaysToCompute(std::string expression);