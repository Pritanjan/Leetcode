// APPROACH 1 [ Recursive solution ]


class Solution {
public:
    void preorder(TreeNode* root, vector<int>& nodes){
        if(!root) return ;
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




// OR



class Solution {
public:
    vector<int> ans;
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==NULL) return ans;
        
        ans.push_back(root->val);
        preorderTraversal(root->left);
        preorderTraversal(root->right);
        return ans;
    }
};









// APPROACH 2 USING 1 STACK (Iterative Solution)  


class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> v;
        stack <TreeNode*> st;
        while (root || !st.empty()){
            if(root) {
                v.push_back(root->val);
                if(root->right) st.push(root->right);
                root = root->left;
            }
            else {
                root = st.top();
                st.pop();
            }
        }
        return v;
    }
};


// T.C. --> O(N)
// S.C. --> O(N)





// OR



class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == NULL) return {};

        vector<int> v;
        stack <TreeNode*> stk;
        stk.push(root);

        while(!stk.empty()){
            TreeNode* curr = stk.top();
            stk.pop();

            v.push_back(curr->val);
            if (curr->right) stk.push(curr->right);
            if (curr->left) stk.push(curr->left);
        }
        return v;
    }
};







// APPROACH 3 [  Morris Traversal Approach ]


class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        TreeNode* curr = root;
        while(curr != NULL) {
            if(curr->left == NULL) {
                res.push_back(curr -> val);
                curr = curr -> right;
            } 
            else {
                TreeNode* pred = curr -> left;
                while(pred -> right != NULL && pred -> right != curr) pred = pred -> right;
                
                if (pred -> right == NULL) {
                    res.push_back(curr -> val);
                    pred -> right = curr;
                    curr = curr -> left;
                } 
                else {
                    pred -> right = NULL;
                    curr = curr -> right;
                }
            }
        }
        return res;
    }
};








// Post order traversal
// For post order traversal, it will be easier to use the stack to handle the expression. 
// Each time an operator is encountered, the two elements at the top of the stack can be ejected from the stack, computed, and returned to the stack.
// Postorder is widely used in mathematical expression. 
// It is easier to write programs to parse suffix notation


// inorder traversal 
// It is used to find the original expression



// Deletion

// The deletion process happens in the post order.
// That is, when you delete a node, you will first delete its left node and its right node, and then delete the node itself.


