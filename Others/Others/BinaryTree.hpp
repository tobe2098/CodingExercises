#pragma once
#include <vector>
#include <queue>

namespace bintree {
    // Tree Node Structure
    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode*left, TreeNode*right) : val(x), left(left), right(right) {}
    };

    // Function to create a tree from an array and return the root node
    TreeNode* createTreeFromArray(std::vector<int> arr);

    // Function to free the memory of the tree
    void freeTree(TreeNode* root);
}

