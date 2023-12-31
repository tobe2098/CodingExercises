#ifndef ALLCONSTRUCT
#define ALLCONSTRUCT
#include <vector>
#include <string>
#include <unordered_map>
std::vector< std::vector<std::string> > allConstructHelper(std::string target, std::vector<std::string> words, std::unordered_map<std::string, std::vector<std::vector<std::string>>>& hashmap);
std::vector<std::vector<std::string>> allConstruct(std::string target, std::vector<std::string> words);
std::vector<std::vector<std::string>> allConstructTab(std::string target, std::vector<std::string> words);


#endif