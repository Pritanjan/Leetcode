// APPROACH 1

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* less  = new ListNode(0);
        ListNode* smaller = less;
        ListNode* high = new ListNode(0);
        ListNode* greater = high;

        while(head != NULL){
            if(head -> val < x) {
                smaller -> next = head;
                smaller = smaller -> next;
            }
            else{
                greater -> next = head; 
                greater = greater -> next;
            }
            head = head -> next;
        }
        greater -> next = NULL;
        smaller -> next = high -> next;

        return less -> next; 
    }
};

// Time Complexity: O(N), where NNN is the number of nodes in the original linked list and
// we iterate the original list.

// Space Complexity: O(1), we have not utilized any extra space, the point to note is that
// we are reforming the original list, by moving the original nodes, we have not used any
// extra space as such.






// APPROACH 2


