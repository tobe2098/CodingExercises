#include "treeProblems.hpp"
namespace bintree {
    int leftLeaves::sumOfLeftLeaves(TreeNode* root) {
        int sum{};
        if (root->left) {
            if (root->left->left || root->left->right) {
                sum += sumOfLeftLeaves(root->left);

            }
            else {
                sum += root->left->val;
            }
        }
        if (root->right) {
            sum += sumOfLeftLeaves(root->right);
        }
        return sum;
    }
    namespace diameter {
        int result{};
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
    namespace composedNums {
        std::vector<std::string> nums;

        void helper(TreeNode* root, std::string carry) {
            bool right{ static_cast<bool>(root->right) }, left{ static_cast<bool>(root->left) };
            carry.push_back(root->val + '0');
            if (right) {
                helper(root->right, carry);
            } if (left) {
                helper(root->left, carry);
            } if (!right && !left) {
                nums.push_back(carry);
            }
        }

        int sumNumbers(TreeNode* root) {
            helper(root, "");
            int sol{};
            for (std::string& s : nums) {
                sol += std::stoi(s);
            }
            return sol;
        }

    }
}
