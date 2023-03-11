// https://github.com/Pritanjan/Question/blob/main/POTD/gfg/0013%20191122%20Check%20if%20all%20levels%20of%20two%20trees%20are%20anagrams%20or%20not.cpp

// APPROACH 1

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL and q == NULL)  // both trees are empty, so they are the same
            return true;
        if(p == NULL or q == NULL)  // one of the trees is empty, so they are different
            return false;
        if(p -> val != q -> val)   // the node values are different, so the trees are different
            return false;
        // recursively check the left and right subtrees
        return isSameTree(p -> left, q -> left) and isSameTree(p -> right, q -> right);
    }
};





