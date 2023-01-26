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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head == NULL) return NULL;
        ListNode* prev = NULL;
        ListNode* fast = head;
        ListNode* slow = head;
        
        while(fast != NULL && fast -> next != NULL){
            fast = fast -> next -> next;
            prev = slow;
            slow = slow -> next;
        }

        TreeNode* root = new TreeNode(slow -> val);
        if(prev != NULL) prev -> next = NULL;
        else head = NULL;

        root -> left = sortedListToBST(head);
        root -> right = sortedListToBST(slow -> next);

        return root;
    }
};



// Traverse the list to get the middle element and make that the root. left side of the list 
// forms left sub-tree and right side of the middle element forms the right sub-tree.




// The first step is to check if the head of the linked list is NULL, in which case the function 
// returns NULL, as there is no tree to be created.

// Then, it uses the slow and fast pointers method to find the middle of the linked list,
// similar to the previous explanation. The prev variable keeps track of the node before
// the slow pointer, which will be used later to break the linked list into two parts.

// Once the middle of the linked list is found, a new TreeNode is created with the value 
// of the middle node. The middle node is the root of the BST.

// Then, the linked list is broken into two parts, the left part and the right part.
// The left part is the nodes before the middle node, and the right part is the nodes after
// the middle node.

// The left part of the linked list is recursively passed as the left child of the root node
// and the right part of the linked list is recursively passed as the right child of the root node.

// Finally, the root node is returned as the result of the function.

// This code uses the property of a BST that left child node is always smaller than the right
// child node and recursively constructs left and right sub-tree until the last node.





