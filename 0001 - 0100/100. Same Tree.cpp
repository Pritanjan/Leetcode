// https://github.com/Pritanjan/Question/blob/main/POTD/gfg/0013%20191122%20Check%20if%20all%20levels%20of%20two%20trees%20are%20anagrams%20or%20not.cpp

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p == NULL and q == NULL)
            return true;
        if(p == NULL or q == NULL)
            return false;
        if(p -> val != q -> val)
            return false;
        return isSameTree(p -> left, q -> left) and isSameTree(p -> right, q -> right);
    }
};





