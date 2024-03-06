#include "floydLoopFinding.hpp"

bool listHasCycle(list::ListNode* head) {

    // making two pointers fast and slow and assignning them to head
    list::ListNode* fast = head;
    list::ListNode* slow = head;

    // till fast and fast-> next not reaches NULL
    // we will increment fast by 2 step and slow by 1 step
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;


        // At the point if fast and slow are at same address
        // this means linked list has a cycle in it.
        if (fast == slow)
            return true;
    }

    // if traversal reaches to NULL this means no cycle.
    return false;
}

list::ListNode* detectCycle(list::ListNode* head) {
    list::ListNode* fast{ head }, * slow{ head };
    while (fast && fast->next) {
        fast = fast->next->next;
        slow = slow->next;
        if (fast == slow) break;
    }
    if (!fast || !fast->next) return nullptr;
    slow = head;
    while (fast != slow) {
        fast = fast->next;
        slow = slow->next;
    }
    return slow;
}