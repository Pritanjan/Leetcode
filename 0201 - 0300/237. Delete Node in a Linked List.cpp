// https://leetcode.com/problems/delete-node-in-a-linked-list/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {
        node -> val  = node -> next -> val;
        node -> next = node -> next -> next;
    }
};

// Time Complexity: O(1) since only 1 node needs to be updated and we only traverse one node behind.

// Space Complexity: O(1), since we use constant extra space to track the next node.

// We are given a linked list 4 -> 5 -> 10-> 13 and we need node 5 to be removed from linked list, also the order should be maintained.

// All we need to do is change the value of node 5 to value of node 10 , and point the node 5 to the address that node 10 points .

// So that Linked list will become 4 -> 10 -> 13



