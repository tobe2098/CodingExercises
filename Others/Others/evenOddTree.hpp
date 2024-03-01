#pragma once
#include "BinaryTree.hpp"
#include <vector>
#include <queue>

using namespace bintree;

namespace evenOddTree {
    static int max_depth{ -1 };
    void helper(TreeNode* root, int depth, std::vector<std::vector<int>>& stratos);
    bool isEvenOddTree(TreeNode* root);
    bool isEvenOddTreeFast(TreeNode* root);
}
