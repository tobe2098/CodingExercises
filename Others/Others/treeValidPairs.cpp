#include "treeValidPairs.hpp"

std::set<int>leafs;

void graph(TreeNode* root, std::vector<std::vector<int>>& adj, TreeNode* parent) {
    root->val = adj.size();
    adj.push_back({});
    if (parent) {
        adj.back().push_back(parent->val);
        adj[parent->val].push_back(root->val);
    }
    bool leaf{ true };
    if (root->left) {
        leaf = false;
        graph(root->left, adj, root);
    }
    if (root->right) {
        leaf = false;
        graph(root->right, adj, root);
    }
    if (leaf) leafs.insert(root->val);
}

int traverse(int tdist, int maxdist, std::vector<std::vector<int>>& adj, int prev, int root) {
    if (tdist+1 > maxdist) return 0;
    int sol{};
    for (int i : adj[root]) {
        if (i == prev) continue;
        if (leafs.contains(i)) {
            sol++;
        }
        else {
            sol += traverse(tdist + 1, maxdist, adj,root, i);
        }
    }
    return sol;
}

int countPairs(TreeNode* root, int distance) {
    std::vector<std::vector<int>> adj;
    graph(root, adj, nullptr);
    //Can be done without set, just store an extra integer at the back to signal leaf and then iterate
    int sol{};
    for (int leaf : leafs) {
        sol += traverse(0, distance, adj,-1, leaf);
    }
    return sol / 2;
}
