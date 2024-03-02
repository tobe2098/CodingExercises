#include "NodeList.hpp"

namespace list {
    ListNode* createNodeList(std::vector<int> vec) {
        ListNode* head = nullptr;
        ListNode* tail = nullptr;

        for (int val : vec) {
            ListNode* newNode = new ListNode(val);
            if (head == nullptr) {
                head = newNode;
                tail = newNode;
            }
            else {
                tail->next = newNode;
                tail = newNode;
            }
        }

        return head;
    }
    void freeNodeList(ListNode* head) {
        while (head != nullptr) {
            ListNode* temp = head;
            head = head->next;
            delete temp;
        }
    }
    void printNodeList(ListNode* head) {
        while (head != nullptr) {
            std::cout << head->val << " ";
            head = head->next;
        }
        std::cout << std::endl;
    }
}
