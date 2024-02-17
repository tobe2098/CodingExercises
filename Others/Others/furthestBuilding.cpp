#include "furthestBuilding.hpp"

int furthestBuilding(std::vector<int> heights, int bricks, int ladders) {
    //You calculate the differences between heights, all negatives are ignored.
    //You start pushbacking all positive numbers, and recompute if it is possible (ladders for top)
    //O(N^2)
    //See where you reach with the bricks, keep track of maximums? Then, when no more,
    //You start replacing maximums of past buildings(bricks only) and the next building, and 
    //redo the bricks thing. The problem is keeping track of the max bricks buildings
    //O(N)
    std::multiset<int> bricks_layed;
    int i{}, diff{}, maxBricks{};
    for (; i < heights.size() - 1; i++) {
        diff = heights[i + 1] - heights[i];
        if (diff > 0) {
            if (bricks < diff) {
                if (ladders == 0) return i;
                else if (diff > maxBricks) ladders--;
                else {
                    // return 0;
                    //Here we do the revamping
                    std::multiset<int>::iterator it = --bricks_layed.end();
                    if (it != bricks_layed.begin()) {
                        it--;
                        maxBricks = *it;
                        // return 0;
                        it++;
                        bricks += *it;
                        bricks_layed.erase(it);
                    }
                    else {
                        bricks += *it;
                        maxBricks = 0;
                        bricks_layed.erase(it);
                    }
                    ladders--;
                    i--;
                }
            }
            else {
                bricks -= diff;
                bricks_layed.insert(diff);
                if (maxBricks < diff) maxBricks = diff;
            }
        }
    }
    return heights.size() - 1;
}