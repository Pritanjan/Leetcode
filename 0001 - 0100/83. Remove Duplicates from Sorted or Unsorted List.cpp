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


// APPROACH 1 Brute Force
// (1) A brute force approach could be to use two nested loops to check whether an
//     element occurs multiple times or not.
// (2) The outer loop picks the elements one by one from the linked list.
// (3) The inner loop iterates over the rest of the linked list to compare the
//     picked element with the rest of the elements.
//     -> During comparison if the same element is found (means it’s a duplicate),
//        we remove that element from the list.
// (4) Return the head of the resulting linked list.
   

Node *removeDuplicates(Node *head) {
    Node *p, *q;
    p = head;

    // Outer loop to pick element.
    while (p != NULL) {
        // Initialize the inner loop pointer.
        q = p->next;

        // Keep track of previous node.
        Node *prev = p;

        while (q != NULL) {
            if (p->data == q->data) {
                // Found a duplicate of node 'p'. Now, we need to remove it.
                // Firstly update the next pointer of the previous node.
                prev->next = q->next;

                // Delete the duplicate node.
                delete q;

                // Move the inner loop pointer to the next node.
                q = prev->next;
            }
            else{
                // Node 'q' is not a duplicate. So, move to the next node.
                prev = q;
                q = q->next;
            }
        }
        // Move the outer loop pointer to the next node.
        p = p->next;
    }
    return head;
}


// Time Complexity: O(N^2)
// Space Complexity: O(1)





// APPROACH 2

// Use hashing to keep track of elements that have already been encountered.

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


// OR
// HASHING

// (1) Instead of iterating over the complete list to determine whether the element is
//     duplicate or not, a better approach is to use the concept of hashing.
// (2) The idea is to maintain a hashtable to keep track of the elements that have
//     already been encountered.
// (3) We traverse through the linked list.
// (4) For every element, we check if it is present in the hashtable or not.
//     -> If yes, it means that we have encountered this element before. 
//        Hence, this is a duplicate. So, remove it from the list.
//     -> Otherwise, this is the first time we encounter the element. 
//        So, add it to the hash table.
// (5) In, this way we can remove all the duplicate elements.
// (6) Return the head of the resulting linked list.


#include <unordered_map>
Node *removeDuplicates(Node *head) {
    Node *curr = head;

    // Keep track of previous node.
    Node *prev = NULL;
    unordered_map<int, bool> seen;

    // Iterate over the given linked list.
    while (curr != NULL) {
        int val = curr->data;
        if (seen[val]) {
            // Node has been encountered before, so its a duplicate.
            // Firstly update the next pointer of the previous node.
            prev->next = curr->next;

            // Delete the duplicate node.
            delete curr;

            // Move on to the next node.
            curr = prev->next;
        }
        else {
            // Node is seen for the first time, so add it to hash table.
            seen[val] = true;

            // Move on to the next node.
            prev = curr;
            curr = curr->next;
        }
    }
    return head;
}

// Time Complexity : O(N)
// We traverse the linked list only once. Hence, the overall time complexity is O(N),
// assuming the hash table can be accessed in O(1) time. 

// Space Complexity: O(N)
// In the worst case, the hash table has to store all the elements of the linked list. 
// Hence, the overall space complexity is O(N).




