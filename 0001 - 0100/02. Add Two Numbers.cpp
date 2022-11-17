/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int sum = 0;
        ListNode* temp = new ListNode(0) ;
        
        ListNode* ans = temp;
        
        
        // ListNode* rtn = new ListNode((l1->val + l2->val) % 10);
        
        while(l1 or l2){
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
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
        
        return ans -> next;
    }
};





