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

bool evenOddTree::isEvenOddTreeFast(TreeNode* root){
    //Should be twice as fast, one traversal
    std::queue<TreeNode*> q;
    q.push(root);
    int level = 0;
    while (!q.empty())
    {
        int size = q.size();
        int mx = INT_MIN, mn = INT_MAX;
        while (size--)
        {
            TreeNode* front = q.front();  q.pop();
            if (front->left)  q.push(front->left);
            if (front->right)  q.push(front->right);
            if ((level & 1) == 0)
            {
                if (!(front->val & 1))  return false;
                if (front->val > mx)  mx = front->val;
                else return false;
            }
            else
            {
                if (front->val & 1)  return false;
                if (front->val < mn)  mn = front->val;
                else return false;
            }
        }
        level++;
    }
    return true;
}