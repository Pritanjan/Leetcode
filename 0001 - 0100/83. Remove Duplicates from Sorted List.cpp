// https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// https://www.codingninjas.com/codestudio/problems/unique-sorted-list_2420283?leftPanelTab=2

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
    ListNode* deleteDuplicates(ListNode* head) {      
        if(!head)
            return head;
        
        ListNode *temp = head;
        while(temp && temp->next){
            if(temp->val == temp->next->val)
                temp->next = temp->next->next;
            else
                temp = temp->next;
        }
        return head;
    }
};


// T.C. --> O(N)
// S.C. --> O(1)



