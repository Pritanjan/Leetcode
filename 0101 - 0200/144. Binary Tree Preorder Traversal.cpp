// APPROACH 1 STACK Recursive solution 

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

// T.C. --> O(N)
// S.C. --> O(N)



// APPROACH 2 USING 1 STACK (Iterative Solution)   

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        stack <TreeNode*> st;
        while (root || !st.empty()){
            if(root){
                v.push_back(root->val);
                if(root->right)
                    st.push(root->right);
                root = root->left;
            }
            else{
                root = st.top();
                st.pop();
            }
        }
        return v;
    }
};

// T.C. --> O(N)
// S.C. --> O(N)

