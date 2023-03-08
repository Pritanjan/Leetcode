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


// Time complexity: O(n) where n is no of nodes in a binary tree
// Auxiliary space: O(n) because using stack stk1 and stk2


class Solution {
public:
    vector<int> res;
    vector<int> postorderTraversal(TreeNode* root) {
        if(root == NULL) return res;
        postorderTraversal(root -> left);
        postorderTraversal(root -> right);
        res.push_back(root -> val);
            
        return res;
    }
};


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL) return {};

        stack<TreeNode*>st;     
        st.push(root);
        
        vector<int>ans;

        while(!st.empty()){
            TreeNode* node=st.top();
            st.pop();

            ans.push_back(node->val);
            
            if(node->left!=NULL) st.push(node->left);
            if(node->right!=NULL) st.push(node->right);
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};



class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if(root==NULL) return {};

        stack<TreeNode*>st;     
        st.push(root);
        
        vector<int>ans;

        while(!st.empty()){
            auto t = st.top();
            if(t->left == nullptr && t->right == nullptr){
                ans.push_back(t->val);
                st.pop();
            }
            
            if(t->right != nullptr){
                st.push(t->right);
                t->right = nullptr;
            }

            if(t->left != nullptr){
                st.push(t->left);
                t->left = nullptr;
            }
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};



