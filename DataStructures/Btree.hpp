#include <iostream>
#include <vector>

using namespace std;

// Define the minimum degree (m) of the B-tree

// B-Tree node structure
struct Node {
    vector<int> keys;   // Array to store keys
    vector<Node*> C;  // Array to store child pointers

    // Check if the node is a leaf
    bool isLeaf() const { return C.empty(); }

    // Node constructor (initially empty)
    Node() {}
};

// B-Tree class
class BTree {
private:
    Node* root{};  // Root node of the B-Tree
    int minimum_keys{}; // Minimum number of keys per node (except root)

    // Function to perform a recursive search for a key
    Node* search(Node* node, int key);

    // Function to split a child node during insertion
    void splitChild(Node* parent, int index, Node* child);

    // Recursive function to insert a new key
    void insertNonFull(Node* node, int key);

public:
    // Constructor (initially empty tree)
    BTree(int num) :minimum_keys{ num } { root = nullptr; }

    // Function to search for a key in the B-Tree
    Node* search(int key) { return search(root, key); }

    // Function to insert a new key into the B-Tree
    void insert(int key);
};