//https://leetcode.com/problems/binary-tree-preorder-traversal/

//In interview recursive & iterative and then we can present the third 
//one if they ask specifically for optimizing the space complexity.

//Recursive solution :-O(n) time and O(n) space (function call stack);

class Solution {
public:
    void preorder(TreeNode* root, vector<int>& nodes){
        if(!root)
            return ;
        nodes.push_back(root->val);
        preorder(root->left, nodes);
        preorder(root->right, nodes);
    }
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> nodes;
        preorder(root, nodes);
            return nodes;
    }
};
