// https://www.codingninjas.com/codestudio/problems/merge-two-sorted-linked-lists_800332?leftPanelTab=0
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




// APPROACH 2


class Solution {
public:
        ListNode* solve(ListNode* first, ListNode* second) {
        // if one element is present in the first
        if(first -> next == NULL){
            first -> next = second;
            return first;
        }
    
        ListNode* curr1 = first; 
        ListNode* next1 = curr1 -> next;
        ListNode* curr2 = second;
        ListNode* next2 = curr2 -> next;
    
        while(next1 != NULL and curr2 != NULL){
            if((curr2 -> val >= curr1 -> val) and (curr2 -> val <= next1 -> val)) {
                // adding node in b/w the first list
                curr1 -> next = curr2;
                next2 = curr2 -> next;
                curr2 -> next = next1; 
            
                // update pointer
                curr1 = curr2;
                curr2 = next2;
            }
            else{
                curr1 = next1;
                next1 = next1 -> next;
            
                if(next1 == NULL){
                    curr1 -> next = curr2;
                    return first;
                }
            }   
        }
        return first;
    }

    
    ListNode* mergeTwoLists(ListNode* first, ListNode* second) {
        if(first == NULL)
            return second;
        if(second == NULL)
            return first;
    
        if(first -> val <= second -> val)
            return solve(first, second);
        else
            return solve(second, first);
    }
    
};



