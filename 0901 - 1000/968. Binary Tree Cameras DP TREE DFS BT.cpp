//https://leetcode.com/problems/binary-tree-cameras/submissions/

//Apply a recusion function dfs.
//Return 0 if it's a leaf.
//Return 1 if it's a parent of a leaf, with a camera on this node.
//Return 2 if it's coverd, without a camera on this node.
//
//For each node,
//if it has a child, which is leaf (node 0), then it needs camera.
//if it has a child, which is the parent of a leaf (node 1), then it's covered.
//
//If it needs camera, then res++ and we return 1.
//If it's covered, we return 2.
//Otherwise, we return 0.

class Solution {
public:
    int ans = 0; 
    int dfs(TreeNode* root){
        if(!root)
            return 2;
        int L = dfs(root->left);
        int R = dfs(root->right);
        if(L == 0 || R == 0){
            ans++;
            return 1;
        }
        return L == 1 || R == 1 ? 2 : 0;
    }
    
    int minCameraCover(TreeNode* root) {
        return (dfs(root) < 1 ? 1 : 0) + ans;
    }
};
