#pragma once
#include <vector>
#include <set>
#include "BinaryTree.hpp"
using namespace bintree;
void graph(TreeNode* root, std::vector<std::vector<int>>& adj, TreeNode* parent);
int traverse(int tdist, int maxdist, std::vector<std::vector<int>>& adj, int prev, int root);
int countPairs(TreeNode* root, int distance);