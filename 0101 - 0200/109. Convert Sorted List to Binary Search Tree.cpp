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
