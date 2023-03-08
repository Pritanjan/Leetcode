// APPROACH 1 RECURSION
// fb

class Solution {
public:
    void postorder(TreeNode* root, vector<int>& nodes) {
        if(!root)
            return ;
        postorder(root->left,  nodes);
        postorder(root->right, nodes);
        nodes.push_back(root->val);
    }
    
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> nodes;
        postorder(root, nodes);
            return nodes;
    }
};

// APPROACH 2 USING 2 STACK

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> v;
        if(root == NULL) return v;

        stack<TreeNode*> stk1, stk2;
        stk1.push(root); 

        while(!stk1.empty()){
            TreeNode* node = stk1.top();
            stk1.pop();
            stk2.push(node);

            if(node -> left) stk1.push(node -> left);
            if(node -> right) stk1.push(node -> right);

        }        
        
        while(!stk2.empty()) {
            TreeNode* node = stk2.top();
            stk2.pop();
            v.push_back(node -> val);
        }
        return v;
    }
};

