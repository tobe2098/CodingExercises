#ifndef COUNTCONSTRUCT
#define COUNTCONSTRUCT
#include <map>
#include<string>
#include <vector>
unsigned int countConstructHelper(std::string& construct, std::vector<std::string>& words, std::string replicate, std::map<std::string, int>& hashmap);
unsigned int countConstruct(std::string construct, std::vector<std::string> words, std::string replicate="");
int countConstructTab(std::string construct, std::vector<std::string> words);

#endif