#pragma once
#include <vector>
#include <string>


void moveToNextLetters(std::vector<std::vector<int>>& dp, char keychar, std::string_view ring, int i, int j, int prevSteps);
int findRotateSteps(std::string ring, std::string key);