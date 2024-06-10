#include "Btree.hpp"

Node* BTree::search(Node* node, int key) {
    if (node == nullptr) {
        return nullptr;  // Key not found
    }

    // Traverse the node's keys
    for (int i = 0; i < node->keys.size(); i++) {
        if (key == node->keys[i]) {
            return node;  // Key found
        }
        if (key < node->keys[i]) {
            return search(node->C[i], key);  // Search in left subtree
        }
    }

    // Search in the rightmost subtree
    return search(node->C[node->keys.size()], key);
}

void BTree::splitChild(Node* parent, int index, Node* child) {
    // Create a new right child node
    Node* newChild = new Node;

    // Move half of the keys and child pointers from the full child to the new child
    newChild->keys.assign(child->keys.begin() + minimum_keys - 1, child->keys.end());
    if (!child->isLeaf()) {
        newChild->C.assign(child->C.begin() + minimum_keys, child->C.end());
    }

    // Reduce the number of keys in the child node
    child->keys.erase(child->keys.begin() + minimum_keys - 1, child->keys.end());
    if (!child->isLeaf()) {
        child->C.erase(child->C.begin() + minimum_keys, child->C.end());
    }

    // Insert the middle key from the child node to the parent node
    parent->keys.insert(parent->keys.begin() + index, child->keys[minimum_keys - 1]);

    // Update child pointers in the parent node
    parent->C.insert(parent->C.begin() + index + 1, newChild);
}

void BTree::insertNonFull(Node* node, int key) {
    // Handle insertion in a leaf node
    if (node->isLeaf()) {
        node->keys.push_back(key);
    }
    else {
        // Find the appropriate child node for insertion
        int i = 0;
        while (i < node->keys.size() && key > node->keys[i]) {
            i++;
        }

        // If the child node is full, split it
        if (node->C[i]->keys.size() == 2 * minimum_keys - 1) {
            splitChild(node, i, node->C[i]);

            // Update the child node index based on the split key
            if (key > node->keys[i]) {
                i++;
            }
        }

        // Recursive call to insert in the appropriate child node
        insertNonFull(node->C[i], key);
    }
}

void BTree::insert(int key) {
    if (root == nullptr || root->keys.size() == 2 * minimum_keys - 1) {
        // Handle root node overflow (split if necessary)
        Node* newRoot = new Node;
        newRoot->C.push_back(root);
        if (newRoot->keys.size() == 2 * minimum_keys - 1) {
            splitChild(newRoot, 0, root);
            // (splitChild implementation continued from previous code)
        }

        // Choose the leftmost child as the new root
        root = newRoot;
    }
    insertNonFull(root, key);
}