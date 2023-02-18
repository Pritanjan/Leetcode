// APPROACH 1 RECUSIVE DFS

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return NULL;
        
        TreeNode* tempRight = root->right;
            
        root->right = invertTree(root->left) ;
        root->left  = invertTree(tempRight);
        
        return root;
    }
};









// APPROACH 2

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(root == NULL)
            return root;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            if(node->left != NULL)
                q.push(node->left);
            
            if(node->right != NULL)
                q.push(node->right);
            
            // TreeNode* temp = node->left;
            // node->left = node->right;
            // node->right = temp;
            
            swap(node->left , node->right);
        }
        return root;
    }
};

//If you draw the 3 or 4 level, just to make sure, 
//binary tree and invert it on a paper, you will easily
//see that all have to be done is to swap kids for each
//node. This can be done many ways: recursion or using 
//queue to store nodes of one level. Recursion is not 
//good way to go due to performance overhead and risk 
//to run it against huge tree. With standard queue 
//solution looks simple robust and runs faster.











// APPROACH 3 -- USING STACK
 
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (!root) {
            return nullptr;
        }
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* node = s.top();
            s.pop();
            if (node->left) {
                s.push(node->left);
            }
            if (node->right) {
                s.push(node->right);
            }
            swap(node->left, node->right);
        }
        return root;
    }
};

