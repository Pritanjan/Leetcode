// A 1 

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        vector<int> v;

        // Add list1 node values before `a` to the array.
        int idx = 0;
        ListNode* curr1 = list1;
        while (idx < a) {
            v.push_back(curr1 -> val);
            curr1 = curr1 -> next;
            idx++;
        }

        // Add list2 node values to the array
        ListNode* curr2 = list2;
        while (curr2 != nullptr) {
            v.push_back(curr2 -> val);
            curr2 = curr2 -> next;
        }

        // Find node b + 1
        while (idx < b + 1) {
            curr1 = curr1 -> next;
            idx++;
        }

        // Add list1 node values after `b` to the array.
        while (curr1 != nullptr) {
            v.push_back(curr1 -> val);
            curr1 = curr1 -> next;
        }

        // Build a linked list with the result by iterating over the array
        // in reverse order and inserting new nodes to the front of the list
        ListNode* res = nullptr;
        for (int i = v.size() - 1; i >= 0; i--) {
            ListNode* tmp = new ListNode(v[i], res);
            res = tmp;
        }
        return res;
    }
};






// A 2 

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        stack<ListNode*> st;
        ListNode* dummy = new ListNode(0);
        dummy -> next = list1;
        ListNode* prev = dummy;

        for (int i = 0; i < a; ++i) {
            prev = prev -> next;
        }

        ListNode* curr = prev->next;
        for (int i = 0; i <= b - a; ++i) {
            st.push(curr);
            curr = curr -> next;
        }

        prev -> next = list2;
        while (!st.empty()) {
            st.top()->next = nullptr;
            st.pop();
        }

        while (list2->next) {
            list2 = list2->next;
        }

        list2->next = curr;
        return dummy->next;
    }
};
