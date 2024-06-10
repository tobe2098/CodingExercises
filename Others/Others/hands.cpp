#include "hands.hpp"

bool isNStraightHand(std::vector<int> hand, int groupSize) {
    if (hand.size() % groupSize != 0) return false;
    std::sort(hand.begin(), hand.end());
    std::vector<std::vector<int>> hands(hand.size() / groupSize);
    for (int num : hand) {
        bool added{ false };
        for (std::vector<int>& h : hands) {
            if (h.empty() || (h.back() + 1 == num&& h.size()<groupSize)) {
                added = true;
                h.push_back(num);
                break;
            }
        }
        if (!added) return false;
    }
    return (std::all_of(hands.begin(), hands.end(), [groupSize](std::vector<int>& v) {
        return v.size() == groupSize;
        }));
}