#pragma once
#include <vector>
#include <string>
#include "BinaryTree.hpp"
namespace bintree {
    namespace leftLeaves {
        int sumOfLeftLeaves(TreeNode* root);
    }
    namespace diameter {
        int helper(TreeNode* root);
        int diameterOfBinaryTree(TreeNode* root);
    }
    namespace composedNums {
        void helper(TreeNode* root, std::string carry);
        int sumNumbers(TreeNode* root);
    }
    namespace rowman {
        TreeNode* addOneRow(TreeNode* root, int val, int depth);
    }
}