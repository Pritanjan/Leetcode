// APPROACH 1 [ Recursive ]

// 1) The first step is to check whether the Head is NULL or Not, if its NULL then
//    we can directly return NULL,
// 2) If the Head is not NULL, then we need to check the length of Linked List starting 
//    from current Head.
// 3) If it is not a multiple of K(Less than K) , then there is no need to reverse it and 
//    hence we can directly return head,
// 4) Else if its a multiple of K, then we have to reverse the K elements starting from current 
//    Head,
// 5) We will follow the same steps for the rest of the elements Recursively.

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        // base case
        if(head == NULL) return NULL;
        
        // to stop from reversing in case of some rem element
        //  Eg. --> 1,2,3,4,5 
        ListNode* times = head;
        for(int i=0; i<k; i++) {
            if(times == NULL) return head;
            else times = times -> next;
        }
        
        // S1 -> reverse first k nodes
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;
        int cnt = 0;           
        
        while(curr != NULL and cnt < k){
            next = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }      
        // S2 -> Recursion call
        if(head != NULL) head -> next = reverseKGroup(next, k);        
        return prev;
    }
};





// APPROACH 2 

