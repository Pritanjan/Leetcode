//https://leetcode.com/problems/swapping-nodes-in-a-linked-list/

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


// 2_POINTER
class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* ptr1 = head; 
        ListNode* ptr2 = head;
        ListNode *k1  = NULL;
        
        while(--k){
            ptr1 = ptr1 -> next;
        }
        
        k1 = ptr1;
        ptr1 = ptr1 ->next;
        while(ptr1){
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next;
        }
        
        swap(k1 -> val, ptr2 -> val);
        
        return head;
    }
};
