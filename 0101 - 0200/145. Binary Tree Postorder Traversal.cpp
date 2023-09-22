// APPROACH 1 [ RECURSION ]

class Solution {
public:
    void postorder(TreeNode* root, vector<int>& nodes) {
        if(!root) return ;
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


// OR


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


// OR


class Solution {
public:
    struct Postorder {
        vector<int> res;
        void operator()(TreeNode* node) {
            if(node == nullptr) return;
            (*this)(node -> left);
            (*this)(node -> right);
            res.push_back(node -> val);
        }
    };

    vector<int> postorderTraversal(TreeNode* root) {
        Postorder post;
        post(root);
        return post.res;
    }
};






// APPROACH 2 [ USING 2 STACK ]

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






// APPROACH 3 [  USING 1 STACK ]

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


// OR


class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root == nullptr) return res;
        stack<TreeNode*> stk;
        stk.push(root);
        
        while(!stk.empty()) {
            root = stk.top();
            stk.pop();            
            if(root != nullptr) {
                stk.push(root);
                stk.push(nullptr);
                if (root->right != nullptr)  stk.push(root->right);
                if (root->left != nullptr) stk.push(root->left);
            } 
            else {
                res.push_back(stk.top()->val);
                stk.pop();
            }
        }
        return res;
    }
};






// APPROACH 4 [ Morris Traversal ]

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> res;
        if (root == nullptr) {
            return res;
        }
        TreeNode* dummy = new TreeNode(-1);
        dummy->left = root;
        TreeNode* cur = dummy;
        while (cur != nullptr) {
            if (cur->left == nullptr) {
                cur = cur->right;
            } else {
                TreeNode* pre = cur->left;
                while (pre->right != nullptr && pre->right != cur) {
                    pre = pre->right;
                }
                if (pre->right == nullptr) {
                    pre->right = cur;
                    cur = cur->left;
                } else {
                    reverseAddNodes(cur->left, pre, res);
                    pre->right = nullptr;
                    cur = cur->right;
                }
            }
        }
        delete dummy;
        return res;
    }
    
    void reverseAddNodes(TreeNode* from, TreeNode* to, vector<int>& res) {
        reverse(from, to);
        TreeNode* node = to;
        while (true) {
            res.push_back(node->val);
            if (node == from) {
                break;
            }
            node = node->right;
        }
        reverse(to, from);
    }
    
    void reverse(TreeNode* from, TreeNode* to) {
        if (from == to) {
            return;
        }
        TreeNode* x = from;
        TreeNode* y = from->right;
        while (true) {
            TreeNode* temp = y->right;
            y->right = x;
            x = y;
            y = temp;
            if (x == to) {
                break;
            }
        }
    }
};






