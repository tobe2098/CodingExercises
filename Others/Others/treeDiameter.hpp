#pragma once
#include "BinaryTree.hpp"
namespace bintree {
    namespace diameter {
        int result{};
        int helper(TreeNode* root);
        int diameterOfBinaryTree(TreeNode* root);
    }
}