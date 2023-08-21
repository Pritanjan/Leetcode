// SAME AS LC Q 445 Add Two Numbers II

// APPROACH 1

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        ListNode* temp = new ListNode(0) ;        
        ListNode* ans = temp;        
        
        while(l1 or l2){
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2) {
                sum += l2 -> val;
                l2 = l2 -> next;
            }
            temp -> next = new ListNode(sum % 10);
            temp = temp -> next;
            
            if(sum > 9) sum = 1;
            else sum = 0;
        }        
        if(sum) temp -> next = new ListNode(sum);
        return ans -> next;
    }
};

// Time complexity :  O(max(m,n)). Assume that mm and nn represents the length of L1 and L2 respectively, the algorithm above iterates at most max(m,n) times.
// Space complexity : O(max(m,n)). The length of the new list is at most max(m,n)+1.






// APPROACH 2

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* curr = dummyHead;
        int carry = 0;
        while (l1 != NULL || l2 != NULL || carry != 0) {
            int x = l1 ? l1->val : 0;
            int y = l2 ? l2->val : 0;
            int sum = carry + x + y;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            l1 = l1 ? l1->next : nullptr;
            l2 = l2 ? l2->next : nullptr;
        }
        return dummyHead->next;
    }
};
