#include "RotateList.hpp"

ListNode* rotateRight(ListNode* head, int k) {
    std::vector<int> vals;
    int len{};
    while (head != nullptr) {
        vals.push_back(head->val);
        head = head->next;
        len++;
    }
    k %= len;
    int init{ (len - k) % len };
    ListNode* sol = new ListNode(vals[init]);
    head = sol;
    for (int idx = (init + 1) % len; idx != init; idx++, idx %= len) {
        head->next = new ListNode(vals[idx]);
        head = head->next;
    }
    return sol;
}

ListNode* rotateRightOptimal(ListNode* head, int k) {
    if (head == nullptr)
        return nullptr;

    ListNode* curr = head;
    int size = 1;

    // calculating length and making a circular loop
    while (curr->next != nullptr) {
        curr = curr->next;
        ++size;
    }

    curr->next = head;

    // cut from the rotating point
    int i = size - (k % size);

    while (i > 1) {
        head = head->next;
        i--;
    }

    curr = head->next;
    head->next = nullptr;
    return curr;
}
