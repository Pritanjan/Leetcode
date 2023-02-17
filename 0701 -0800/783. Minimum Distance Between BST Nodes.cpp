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

// The in-order traversal of a binary search tree produces a sorted array. 
// Therefore, we will generate the in-order array of the given tree and
// then find the minimum difference using the algorithm we just discussed.


// 1. Initialize the mi to MAX_VALUE possible; this is the variable to 
//    store the minimum difference.

// 2. Perform an in-order traversal of the given binary search tree and
//    store the nodes in a list inorderNodes.

// 3. Iterate over inorderNodes starting from index 1, and for each element at i, 
//    find the difference with the element at index i - 1 and update the variable mi accordingly.

// 4. Return minDistance.

class Solution {
public:
    // List to store the tree nodes in the inorder traversal.
    vector<int> v;
    void inorder(TreeNode* root){
        if (root == NULL) return;
        
        inorder(root->left);
        v.push_back(root->val);
        inorder(root->right);
    }

    int minDiffInBST(TreeNode* root) {
        inorder(root);
        int mi = INT_MAX;
        
        // Find the diff between every two consecutive values in the list.
        for(int i=0; i<v.size() - 1; i++) 
            mi = min(mi, v[i+1] - v[i]);
        
        return mi;
    }
};



// Here N is the number of nodes in the given binary search tree.

// Time complexity: O(N).
// We traverse the tree using in-order traversal; this takes O(N) time. 
// Then we iterate over the array of size N elements to find the minimum difference. T

// Space complexity: O(N).
// The in-order traversal is recursive and would take some space to store the stack calls. 
// The maximum number of active stack calls at a time would be the tree's height,
// in the worst case this space would be O(N) when the tree is a straight line. 
// We also need an array to store the NNN tree nodes. 





