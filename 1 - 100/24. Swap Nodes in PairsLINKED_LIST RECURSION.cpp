//https://leetcode.com/problems/swap-nodes-in-pairs/
//COMPANY_TAG FB MICROSOFT AMAZON UBER

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        
        if(!head || !head -> next)
            return head;
        ListNode* first  = head;
        ListNode* second = head->next;
        ListNode* ptr    = swapPairs(second -> next);
        second -> next = first;
        first  -> next = ptr;
        
        return second;
    }
};
