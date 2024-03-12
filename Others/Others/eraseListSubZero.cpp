#include "eraseListSubZero.hpp"

ListNode* removeZeroSumSublists(ListNode* head) {
    //My version
    std::vector<int> store, prefix(1);
    ListNode* newhead{ head }, * ptr{ head };
    while (head) {
        store.push_back(head->val);
        prefix.push_back(prefix.back() + store.back());
        head = head->next;
    }
    //Find the subsequences
    for (int i = 0; i < store.size(); i++) {
        if (store[i] == 0) continue;
        for (int j = i + 1; j < store.size(); j++) {
            if (store[j] == 0) continue;
            if (prefix[j + 1] - prefix[i] == 0) {
                for (int k = i; k <= j; k++) {
                    store[k] = 0;
                }
            }
        }
    }
    //erase the subsequences (done)

    int elements{};
    for (int i = 0; i < store.size(); i++) {
        if (store[i] != 0) {
            elements++;
            ptr->val = store[i];
            head = ptr;
            ptr = ptr->next;
        }
    }
    if (elements) {
        head->next = nullptr;
        return newhead;
    }
    else return nullptr;

}

ListNode* removeZeroSumSublists2(ListNode* head) {
    std::deque<int>dq;
    ListNode* temp = head;
    std::set<long long>st;
    st.insert(0);
    long long sum = 0;
    while (temp != NULL)
    {
        dq.push_back(temp->val);
        sum = sum + temp->val;
        temp = temp->next;
        if (st.find(sum) != st.end())
        {
            long long int val = sum;
            while (!dq.empty())
            {
                st.erase(sum);
                sum -= dq.back();
                dq.pop_back();
                if (sum == val) break;
            }
        }
        st.insert(sum);
    }
    ListNode* nhead = NULL;
    ListNode* mover = NULL;
    while (!dq.empty())
    {
        if (nhead == NULL)
        {
            nhead = new ListNode(dq.front());
            mover = nhead;
        }
        else {
            mover->next = new ListNode(dq.front());
            mover = mover->next;
        }
        dq.pop_front();
    }
    return nhead;
}


ListNode* removeZeroSumSublists3(ListNode* head) {
    //Important to understand this one
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    int prefix_sum = 0;
    std::unordered_map<int, ListNode*> prefix_sums;
    prefix_sums[0] = dummy;
    ListNode* current = head;

    while (current) {
        prefix_sum += current->val;
        if (prefix_sums.find(prefix_sum) != prefix_sums.end()) {
            ListNode* to_delete = prefix_sums[prefix_sum]->next;
            int temp_sum = prefix_sum + to_delete->val;
            while (to_delete != current) {
                prefix_sums.erase(temp_sum);
                to_delete = to_delete->next;
                temp_sum += to_delete->val;
            }
            prefix_sums[prefix_sum]->next = current->next;
        }
        else {
            prefix_sums[prefix_sum] = current;
        }
        current = current->next;
    }

    return dummy->next;
}
