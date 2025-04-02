// DynamicProgramming.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "parenthesis.hpp"
int main() {
    //std::cout << possiblePaths(18,18)<<'\n';
    //std::vector<int> arr = { 23,17,3,2 };
    //std::unordered_map<int, std::vector<int>> hashmap;
    //std::unordered_map<int, bool> hashmap2;
    //std::cout << std::boolalpha << canSum(arr, 123455, hashmap2)<<'\n';
    //std::cout << "{";
    //for (int i : howSum(arr, 89, hashmap)) {
    //    std::cout << i<<",";
    //}
    //std::cout << "}";
    //std::cout << fact(100)<<'\n';
    /*std::cout << "> enterapotentpot" << '\n';
    std::cout << "[";
    for (std::vector<std::string>& sol : allConstruct("enterapotentpot", { "a", "p", "ent", "enter", "ot", "o", "t" })) {
        std::cout << "[";
        for (std::string word : sol) {
            std::cout << word << ",";
        }
        std::cout << "]";
        std::cout << "\n";
    }
    std::cout << "]";
    std::cout << "> purple" << '\n';
    std::cout << "[\n";
    for (std::vector<std::string>& sol : allConstruct("purple", { "purp", "p", "ur", "le", "purpl" })) {
        std::cout << "[";
        for (std::string word : sol) {
            std::cout << word << ",";
        }
        std::cout << "]";
        std::cout << "\n";
    }
    std::cout << "]\n";
    */
    //std::cout << getLengthOfOptimalCompressionTab("abcdefghijklmnopqrstuvwxyz", 16);
    //int count{ 1 };
    //std::cout << (count >= 100) ? 3 : (count >= 10) ? 2 : (count >= 2) ? 1 : 0;
    diffWaysToComputeRec("2*3-4*5");
    //std::cout << minDifficultyTab({6,5,1,2,3,4,6,1 } , 4);
    return 0;
}