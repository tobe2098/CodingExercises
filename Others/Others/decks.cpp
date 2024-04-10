#include "decks.hpp"

std::vector<int> deckRevealedIncreasing(std::vector<int> deck) {
    std::sort(deck.begin(), deck.end());
    std::vector<int> sol(deck.size(), 0);
    size_t ptr1{}, ptr2{}, size{ deck.size() };
    bool found{ true };
    while (ptr2 < size) {
        for (; ptr1 < size; ptr1++) {
            if (sol[ptr1] == 0) {
                if (found) {
                    sol[ptr1] = deck[ptr2];
                    ptr2++;
                    found = false;
                }
                else {
                    found = true;
                }
            }
        }
        if (ptr1 == size) ptr1 = 0;
    }
    return sol;
}