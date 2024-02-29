#pragma once
#include "BinaryTree.hpp"

using namespace bintree;

namespace evenOddTree {
    static int max_depth{ -1 };
    void helper(TreeNode* root, int depth, std::vector<std::vector<int>>& stratos);
    bool isEvenOddTree(TreeNode* root);
}
