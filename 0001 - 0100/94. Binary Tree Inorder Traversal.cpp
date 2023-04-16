// APPROACH 1 [ RECURSIVE ]


class Solution {
public:
    void inorder(TreeNode* root, vector<int>& nodes) {
        if(!root)
            return ;
        inorder(root->left,  nodes);
        nodes.push_back(root->val);
        inorder(root->right, nodes);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> nodes;
        inorder(root, nodes);
            return nodes;
    }
};

//Time complexity: O(n)
//The time complexity is O(n) because the recursive function is T(n)=2·T(n/2)+1.

//Space complexity: O(n)
//The worst case space required is O(n), and in the average case it's O(logn) where n is number of nodes.











// APPROACH 2 [ Iterative method using Stack ]


class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> stack;
        while(root || !stack.empty()) {
            while(root) {
                stack.push(root);
                root = root->left;
            }
            root=stack.top(), stack.pop();
            ans.push_back(root->val);
            root=root->right;
        }
        return ans;
    }
};



// Time complexity: O(n)
// Space complexity: O(n)









// APPROACH 3 [ Morris Traversal ]





// Time complexity: O(n)
// Space complexity: O(1)
