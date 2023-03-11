// https://practice.geeksforgeeks.org/problems/diameter-of-binary-tree/1

class Solution {
public:
    int height(TreeNode* root){
        if(!root) return 0;

        int Lheight = height(root -> left);
        int Rheight = height(root -> right);

        return max(Lheight, Rheight) + 1;
    }


    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        int op1 = diameterOfBinaryTree(root -> left);
        int op2 = diameterOfBinaryTree(root -> right);
        int op3 = height(root -> left) + height(root -> right);

        return max(op1, max(op2, op3));
    }
};


// T.C. --> O(N^2)



class Solution {
public:
    int height(TreeNode* root, int &diameter){
        if(!root) return 0;

        int Lheight = height(root -> left, diameter);
        int Rheight = height(root -> right, diameter);

        diameter = max(diameter, Lheight + Rheight);
        return max(Lheight, Rheight) + 1;
    }


    int diameterOfBinaryTree(TreeNode* root) {
        int Ldiameter = 0;
        height(root, Ldiameter);
        return Ldiameter;
    }
};








