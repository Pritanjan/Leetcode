// SAME AS LC Q 2 Add Two Numbers II

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *nextNode, *prevNode = NULL;
        while(head){
            nextNode = head->next;
            head->next = prevNode;
            prevNode = head;
            head = nextNode;
        }
        return prevNode;
    }

    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* p = reverseList(l1);
        ListNode* l = reverseList(l2);

        int sum = 0;
        ListNode* temp = new ListNode(0) ;
        
        ListNode* ans = temp;
        
        // ListNode* rtn = new ListNode((l1->val + l2->val) % 10);
        
        while(p or l){
            if(p){
                sum += p -> val;
                p = p -> next;
            }
            if(l){
                sum += l -> val;
                l = l -> next;
            }
            temp -> next = new ListNode(sum % 10);
            temp = temp -> next;
            
            if(sum > 9)
                sum = 1;
            else 
                sum = 0;
        }
        
        if(sum)
            temp -> next = new ListNode(sum);
        
        return reverseList(ans -> next);
    }
};
