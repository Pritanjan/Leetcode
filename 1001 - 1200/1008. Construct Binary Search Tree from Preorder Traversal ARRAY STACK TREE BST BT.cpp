//https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

//Give the function ma the maximum number it will handle.
//The left recursion will take the elements smaller than node->val
//The right recursion will take the remaining elements smaller than bound
//
//Complexity :-
//bstFromPreorder is called exactly N times.
//It's same as a preorder traversal.
//Time O(N)
//Space O(H)

class Solution {
public:
    int a = 0;
    TreeNode* bstFromPreorder(vector<int>& p, int ma = INT_MAX) {
        if(a == p.size() || p[a] > ma)
            return NULL;
        TreeNode* root = new TreeNode(p[a++]);
        root -> left = bstFromPreorder(p,root -> val);
        root -> right = bstFromPreorder(p,ma);
        
        return root;
    }
};
