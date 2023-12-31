#pragma once
#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>
int compLength2(std::string s);
std::string compress(std::string s);
int getLengthOfOptimalCompressionHelper(std::string s, int k, std::unordered_map<std::string, int>& hashmap);
int getLengthOfOptimalCompression(std::string s, int k);
int getLengthOfOptimalCompressionTab(std::string s, int k);