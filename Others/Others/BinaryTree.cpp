#include "BinaryTree.hpp"
namespace bintree {
    TreeNode* createTreeFromArray(const std::vector<int>& arr) {
        if (arr.empty()) return nullptr;

        std::queue<TreeNode*> nodes;
        TreeNode* root = new TreeNode(arr[0]);
        nodes.push(root);

        for (size_t i = 1; i < arr.size(); ++i) {
            TreeNode* parent = nodes.front();
            nodes.pop();

            if (arr[i] != -1) {
                parent->left = new TreeNode(arr[i]);
                nodes.push(parent->left);
            }

            ++i;
            if (i < arr.size() && arr[i] != -1) {
                parent->right = new TreeNode(arr[i]);
                nodes.push(parent->right);
            }
        }

        return root;
    }

    void freeTree(TreeNode* root) {
        if (!root) return;

        freeTree(root->left);
        freeTree(root->right);

        delete root;
    }
}

