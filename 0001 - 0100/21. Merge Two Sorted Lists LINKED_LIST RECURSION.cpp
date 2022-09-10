//https://leetcode.com/problems/merge-two-sorted-lists/
// COMPANY TAG FB MICROSOFT AMAZON UBER BLOOMBERG

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        // If the list 1 is empty then return list 2
        if(list1== NULL)
            return list2;
        
        // If the list 2 is empty then return list 1
        if(list2== NULL)
            return list1;
        
        // if value pointed by list1 pointer is <= to value pointed by list2 pointer
        if(list1->val <=list2->val){
            list1->next = mergeTwoLists(list1->next, list2);
                return list1;
        }
        
        // we will call recursive l1 whole list and l2 -> next
        else{
            list2->next = mergeTwoLists(list2->next, list1);
                return list2;
        }
        return 0;    
    }
};


