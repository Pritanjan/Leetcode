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



