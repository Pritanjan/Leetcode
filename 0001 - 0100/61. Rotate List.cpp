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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL)
            return NULL;
            
        ListNode* slow = head;
        ListNode* fast = head;

        ListNode* temp = head;
        int len = 0;
        while(temp != NULL){
            temp = temp -> next;
            len++;
        }

        k = k % len;
        for(int i=0; i<k; i++){
            fast = fast -> next;
        }

        while(fast -> next != NULL){
            slow = slow -> next;
            fast = fast -> next;
        }
        fast -> next = head;
        ListNode* res = slow -> next;
        slow -> next = NULL;

        return res;
    }
};


// Here we are going to use the approach that calculates the length of the list first,
// then get the offset and do the rotation.

// If the input offset is always going to be valid, a fast and slow pointer way is a little better.
// But in the Leetcode version, k could be larger than the length, so we need the length anyway.

