// APPROACH 1

// We are given a linked list 4 -> 5 -> 10-> 13 and we need node 5 to be removed from LL,
// also the order should be maintained.

// All we need to do is change the value of node 5 to value of node 10 ,
// and point the node 5 to the address that node 10 points .

// So that Linked list will become 4 -> 10 -> 13


class Solution {
public:
    void deleteNode(ListNode* node) {
        node -> val  = node -> next -> val;
        node -> next = node -> next -> next;
    }
};


// Time Complexity: O(1) 
// since only 1 node needs to be updated and we only traverse one node behind.

// Space Complexity: O(1), 
// since we use constant extra space to track the next node.





// APPROACH 2

class Solution {
public:
    void deleteNode(ListNode* node) {
        // If node is the last node or node is NULL
        if (!node || !node->next) return;
        
        // Copy the value of the next node into the current node
        node->val = node->next->val;
        
        // Delete the next node
        ListNode* temp = node->next;
        node->next = temp->next;
        delete temp;
    }
};



