Explanation : -

Consider root node as max.
Now, traverse left subtree & right subtree and if we found any value greater than max then make increment in cnt by 1, and consider this node as node.

class Solution {
public:
    int cnt = 0;
    
    int goodNodes(TreeNode* root) {
        cnt = 0;
        dfs(root, root->val);
        return cnt;
    }
    
    void dfs(TreeNode* root, int max){
        if(root == NULL)
            return ;
        
        if(root->val >= max){
            // cout<<root -> val<<" ";
            max = root->val;
            cnt++;
        }
        dfs(root->left, max);
        dfs(root->right, max);
        
        // return cnt;
    }
};

