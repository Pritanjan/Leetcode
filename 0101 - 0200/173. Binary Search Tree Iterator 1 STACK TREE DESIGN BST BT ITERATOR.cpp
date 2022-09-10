// https://leetcode.com/problems/binary-search-tree-iterator/

// WE WILL FIND INORDER OF THE TREE AND CHECK IF NEXT IS AVAILABLE OR NOT

class BSTIterator {
public:
    vector <int> nums;
    int i = 0;
    
    void inorder(TreeNode *&root){
        if(!root)
            return;
        inorder(root -> left);
        nums.push_back(root -> val);
        inorder(root -> right);
    }
    
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    int next() {
        int a = nums[i];
        i++;
        return a;
    }
    
    bool hasNext() {
        if(i < nums.size())
            return true;
        return false;
        
    }
};

   
