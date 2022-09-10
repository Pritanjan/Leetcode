class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode*fast = head;
        ListNode*slow = head;
        
        // iterate first n node using fast
        while(n--){
            fast = fast->next;
        }
        // if fast is already null, it means we have to delete 
        // head itself. So, just return next of head
        if(!fast)
            return head->next;
        
        // iterate till fast reaches the last node of list
        while(fast->next){
            fast = fast->next;
            slow = slow->next;
        }
        
        // remove the nth node from last
        slow->next = slow->next->next;
        return head;
    }
};

