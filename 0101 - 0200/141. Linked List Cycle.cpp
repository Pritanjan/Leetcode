//https://leetcode.com/problems/linked-list-cycle/
//COMPANY TAG AMAZON LINKEDIN MICROSOFT

//https://leetcode.com/problems/linked-list-cycle/discuss/2011503/Microsot

// check cycle -> tail to head
// https://www.codingninjas.com/codestudio/problems/circularly-linked_1070232?source=youtube&campaign=Lovebabbar_codestudio_26thjan&utm_source=youtube&utm_medium=affiliate&utm_campaign=Lovebabbar_codestudio_26thjan&leftPanelTab=0


class Solution {
public:
    bool hasCycle(ListNode *head) {
		// if head is NULL then return false;
        if(head == NULL || head->next == NULL)
            return false;
        
        ListNode* ptr  = head;
        ListNode* ptr1 = head->next;
        
        while(ptr != ptr1){
            if(ptr1 == NULL || ptr1->next == NULL)
                return false;
            ptr = ptr->next;
            ptr1 = ptr1->next->next;
        }
        return true;
    }
};

// APPROACH 2
class Solution {
public:
    bool hasCycle(ListNode *head) {  
		// making two pointers ptr and ptr1 and assignning them to head      
        ListNode* ptr  = head;
        ListNode* ptr1 = head;
        
		// till ptr1 and ptr1> next not reaches NULL
		// we will increment fast by 2 step and slow by 1 step
        while(ptr1 && ptr1->next){
            ptr = ptr->next;
            ptr1 = ptr1->next->next;

			  // At the point if ptr and ptr1 are at same address
			  // this means linked list has a cycle in it.
            if(ptr == ptr1)
                return true;
        }
	  	// if traversal reaches to NULL this means no cycle.
        return false;
    }
};

Time Complexity : O(N)
Space Complexity : O(1)
