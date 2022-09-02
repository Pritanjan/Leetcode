//https://leetcode.com/problems/remove-duplicates-from-sorted-list/
// https://www.codingninjas.com/codestudio/problems/unique-sorted-list_2420283?topList=amazon-sde-challenge&leftPanelTab=0

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
 
 // in CN 
 // ListNode  -> Node
 // val -> data
 
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *temp = head;
        
        if(!head)
            return head;
        
        while(temp && temp->next){
            if(temp->val == temp->next->val)
                temp->next = temp->next->next;
            else
                temp = temp->next;
        }
        return head;
    }
};
