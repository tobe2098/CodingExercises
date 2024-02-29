#include "evenOddTree.hpp"

void evenOddTree::helper(TreeNode* root, int depth, std::vector<std::vector<int>>& stratos) {
    if (depth == max_depth + 1) {
        max_depth = depth;
        stratos.push_back(std::vector<int>());
    }
    stratos[depth].push_back(root->val);

    if (root->left) helper(root->left, depth + 1, stratos);
    if (root->right) helper(root->right, depth + 1, stratos);



}

bool evenOddTree::isEvenOddTree(TreeNode* root) {
    std::vector<std::vector<int>> stratos;
    helper(root, 0, stratos);
    for (int i = 0; i < stratos.size(); i++) {
        if (i % 2 == 0) {
            for (int j = 0; j < stratos[i].size(); j++) {
                if (!(stratos[i][j] & 1) || (j + 1 < stratos[i].size() && stratos[i][j] >= stratos[i][j + 1])) return false;
            }
        }
        else {
            for (int j = 0; j < stratos[i].size(); j++) {
                if ((stratos[i][j] & 1) || (j + 1 < stratos[i].size() && stratos[i][j] <= stratos[i][j + 1])) return false;
            }
        }
    }
    return true;
}