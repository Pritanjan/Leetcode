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
    ListNode* del(ListNode* head, ListNode* prev = NULL){
        if(head == NULL)
            return NULL;
            
        if ((head->next and head->next->val == head->val) or (prev and prev->val == head->val))
            return del(head->next, head);
        else
            head->next = del(head->next, head);
    
        return head;
    }

    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* prev = NULL;

        return del(head, NULL);
    }
};





