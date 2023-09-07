// A 1
// Find the addresses of the nodes at the left and right position by traversing the given list.
// Reverse the list from left to right separately.
// After the reversal, reattach the list in the original list at the same position.

class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode *nextNode, *prevNode = NULL;
        // while(head != NULL){
        while(head){
            nextNode = head->next;
            head->next = prevNode;
            prevNode = head;
            head = nextNode;
        }
        return prevNode;
    }

    ListNode* reverseBetween(ListNode* head, int L, int R) {
        ListNode* CN = head;   // current node
        ListNode* SN;          // strt node
        ListNode* LN;          // last node
        int idx = 1;           // index

        while(CN != NULL){
            if(idx > R) break;
            if(idx < L) SN = CN;
            if(idx == R) LN = CN;

            CN = CN -> next;
            idx++;
        }

        LN -> next = NULL;
        if(L == 1){
            LN = head;
            head = reverse(head);
        }
        else{
            LN = SN -> next;
            SN -> next = reverse(SN -> next);
        }
        LN -> next = CN;
        return head;
    }
};

// 1. It initializes CN (current node), SN (start node), and LN (end node) to head, NULL, and NULL, 
//    and idx to 1.
// 2. It iterates through the list using a while loop until it reaches the Rth node or the end of the list. 
// 3. If idx is less than L, it updates SN to point to the current node (CN) as 
//    it represents the node just before the left position.
// 4. If idx is equal to R, it updates LN to point to the current node (CN) as 
//    it represents the node at the right position.
// 5. It then updates CN and increments idx.
// 6. After the loop, it sets the next pointer of the LN node to NULL, 
//    effectively splitting the list into two parts: the one to be reversed and the rest.
// 7. If L is 1, it means that the reversal starts from the beginning of the list, 
//    so it reverses the entire list using the reverse function and updates the head of the list.
// 8. If L is greater than 1, it means the reversal starts from a node other than the head. 
//    In this case, it reverses the sublist between SN and LN using the reverse function
//    and updates SN->next to point to the new head of the reversed sublist.
// 9. Finally, it connects the reversed sublist (LN->next) to the remaining part of the list (CN)
//    and returns the updated head of the list.

// Time Complexity: O(n)
// Auxiliary Space Complexity: O(1)






// A 2







