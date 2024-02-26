#pragma once
#include <vector>
#include <unordered_map>
/*This function is a part of a data structure known as Disjoint-Set Union (DSU) or Union-Find. The purpose of this function is to find the root of the set to which a given element x belongs. It utilizes path compression to optimize the performance of future queries.

Here's how the function works:
If x is not the root of its set (i.e., f[x] != x), it means x has a parent.
To find the root, the function calls itself recursively with f[x] (which represents the parent of x). This step recursively searches for the root of the set to which x belongs.
Additionally, this step employs path compression. As the recursive calls unwind, the function updates the parent of each traversed element (f[x]) to point directly to the root of the set. This optimization ensures that future queries involving these elements will have faster access to their roots, as the path length to the root is minimized.*/
// Function to find the root of a set using path compression
int getf(std::vector<int>& f, int x);

/*This function merge is also a part of the Disjoint-Set Union (DSU) or Union-Find data structure. It merges two sets represented by the elements x and y, updating their parent information and frequency counts accordingly.*/
// Function to merge two sets and update the frequency
void merge(std::vector<int>& f, std::vector<int>& num, int x, int y);

bool canTraverseAllPairs(std::vector<int> nums);