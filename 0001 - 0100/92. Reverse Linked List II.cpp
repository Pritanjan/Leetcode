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


// Approach
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
        ListNode* CN = head;
        ListNode* SN;
        ListNode* LN;
        int idx = 1;

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


// Time Complexity: O(n)
// Auxiliary Space Complexity: O(1)






