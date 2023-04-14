// APPROACH 1

class Solution {
public:
    int height(TreeNode* root) {
        if(!root) return NULL;
        return 1 + max(height(root->left), height(root->right));
    }

    bool isBalanced(TreeNode* root) {
        int LH = 0, RH = 0;

        if(root == NULL) return true;

        LH = height(root -> left);
        RH = height(root -> right);

        if(abs(LH - RH) > 1) return 0;

        // return true;    
        // this function only checks if the root node is balanced or not, 
        // but it does not check if its subtrees are balanced. 
      
        // To check if a tree is balanced, we need to recursively check if its left and
        // right subtrees are balanced as well.
        // So we need to call the isBalanced function recursively on the left and right subtrees
        // and return true only if both subtrees are balanced and the difference in height 
        // between them is less than or equal to 1.
        return isBalanced(root->left) && isBalanced(root->right);
    }
};

// T.C. O(N^2)

class Solution {
public:
    int height(TreeNode* root) {
        if (!root) return 0;
        
        int LH = height(root->left);
        if (LH == -1) return -1;

        int RH = height(root->right);
        if (RH == -1) return -1; 
        
        if (abs(LH - RH) > 1) return -1;
        return max(LH, RH) + 1;
    }
    
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};



// T.C. --> O(N)
// The height function is called once for each node in the tree, so the time complexity
// of the height function is O(n), where n is the number of nodes in the tree. 
// The isBalanced function calls the height function once.

// S.C.
// On the basis of height function
// O(log N) [best  case] (when the tree is balanced)
// O(N)     [Wrost Case] (when the tree is completely unbalanced).
// O(log N) [avg   case]

// On the basis of isBalanced function 
// O(1).

// S.C. -->  O(log N)









// APPROACH 3


class Solution {
public:
    static bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;
        
        dfs(root);
        queue<TreeNode*> que;
        que.push(root);

        while (!que.empty()) {
            TreeNode* node = que.front();
            que.pop();

            int leftHeight = (node->left == NULL) ? 0 : node->left->val;
            int rightHeight = (node->right == NULL) ? 0 : node->right->val;
            
            if(abs(leftHeight - rightHeight) > 1) return false;
            if(node->left != NULL) que.push(node->left);
            if(node->right != NULL) que.push(node->right);
        }
        return true;
    }

private:
    static void dfs(TreeNode* root) {
        if(root == NULL) return ;
    
        dfs(root->left);
        dfs(root->right);

        if(root != NULL && root->left == NULL && root->right == NULL) root->val = 1;
        else {
            int leftHeight = (root->left == NULL) ? 0 : root->left->val;
            int rightHeight = (root->right == NULL) ? 0 : root->right->val;
            root->val = max(leftHeight, rightHeight) + 1;
        }
    }
};


