// APPROACH 1

// Give the function ma the maximum number it will handle.
// The left recursion will take the elements smaller than node->val
// The right recursion will take the remaining elements smaller than bound


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



// Complexity :-
// bstFromPreorder is called exactly N times.
// It's same as a preorder traversal.
// Time O(N)
// Space O(H)







// APPROACH 2

class Solution {
public:
    TreeNode* f(vector<int> &preorder, int mi, int mx, int &i){
        if(i >= preorder.size()) return NULL;

        // out of rsnge
        if(preorder[i] < mi or preorder[i] > mx) return NULL;

        TreeNode* root = new TreeNode (preorder[i++]);
        root -> left = f(preorder, mi, root -> val, i);
        root -> right = f(preorder, root -> val, mx, i);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int> &preorder) {
        int mi = INT_MIN;
        int mx = INT_MAX;
        int i = 0;
        
        return f(preorder, mi, mx, i);
    }
};
