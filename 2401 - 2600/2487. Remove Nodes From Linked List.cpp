// A 1

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        if (head == NULL) return NULL;
        head->next = removeNodes(head->next);
        if (head->next != NULL && head->val < head->next->val) return head->next;
        return head;
    }
};

// Time: O{N)
// Space:O(n)
  





// A 2 
