#pragma once
#include <vector>
#include "BinaryTree.hpp"
namespace bintree {
    namespace leftLeaves {
        int sumOfLeftLeaves(TreeNode* root);
    }
    namespace diameter {
        int result{};
        int helper(TreeNode* root);
        int diameterOfBinaryTree(TreeNode* root);
    }
}