#include "treeDiameter.hpp"

namespace bintree {
    namespace diameter {
        int helper(TreeNode* root) {
            if (root->left == nullptr && root->right == nullptr) {
                return 1;
            }
            int right{}, left{};
            if (root->right) {
                right = helper(root->right);
            }
            if (root->left) {
                left = helper(root->left);
            }
            result = std::max(result, right + left);
            return std::max(right, left) + 1;
        }

        int diameterOfBinaryTree(TreeNode* root) {
            helper(root);
            return result;
        }
    }
}

