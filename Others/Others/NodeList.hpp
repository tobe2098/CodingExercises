#pragma once 
#include <vector>
#include <iostream>
namespace list {
	struct ListNode {
		int val;
		ListNode* next;
		ListNode() : val(0), next(nullptr) {}
		ListNode(int x) : val(x), next(nullptr) {}
		ListNode(int x, ListNode* next) : val(x), next(next) {}
	};
    ListNode* createNodeList(std::vector<int> vec);
	void freeNodeList(ListNode* head);
	void printNodeList(ListNode* head);
}