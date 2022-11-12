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




// https://www.codingninjas.com/codestudio/problems/remove-duplicates-from-unsorted-linked-list_1069331?leftPanelTab=0
// Remove Duplicates From an Unsorted Linked List


#include <bits/stdc++.h> 
/****************************************************************
    Following is the class structure of the Node class:
    class Node
    {
    public:
        int data;
        Node *next;
        Node(int data)
        {
            this->data = data;
            this->next = NULL;
        }
    };
*****************************************************************/

Node *removeDuplicates(Node *head) {
    unordered_map<int, int> ump;
    Node* prev = NULL;
    Node* curr = head;
    
    while(curr != NULL){
        if(ump.count(curr -> data) > 0){
            prev -> next = curr -> next;
            curr = curr -> next;
            continue;
        }
        prev = curr;
        ump[curr -> data]++;
        curr = curr -> next;
    }
    return head;
}



