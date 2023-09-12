// A 1

// We are given a linked list 4 -> 5 -> 10-> 13 and we need node 5 to be removed from LL,
// also the order should be maintained.
// All we need to do is change the value of node 5 to value of node 10, and point the node 5
// to the address that node 10 points. So that Linked list will become 4 -> 10 -> 13

class Solution {
public:
    void deleteNode(ListNode* node) {
        node -> val  = node -> next -> val;
        node -> next = node -> next -> next;
    }
};


// OR


class Solution {
public:
    void deleteNode(ListNode* node) {
        // Skip the node to be deleted by copying the value of the next node
        // and then updating the 'next' pointer to skip the next node.
        ListNode* temp = node->next;
        node->val = temp->val;
        node->next = temp->next;
        delete temp;  // Free the memory of the original next node
    }
};

// Time Complexity: O(1), since only 1 node needs to be updated and we only traverse one node behind.
// Space Complexity: O(1), since we use constant extra space to track the next node.






// A 2

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






// A 3 

class Solution {
public:
    void deleteNode(ListNode* node) {
        *node = *node -> next;
    }
};





// A 4

class Solution {
public:
    void deleteNode(ListNode* node) {
        if(node == nullptr || node->next == nullptr) return ;
        ListNode* curr = node;
        while(curr -> next -> next != nullptr) {
            curr -> val = curr -> next -> val;
            curr = curr -> next;
        }
        // Update the value of the second-to-last node and delete the last node
        curr -> val = curr -> next -> val;
        delete curr -> next;
        curr -> next = nullptr;
    }
};






// A 5
