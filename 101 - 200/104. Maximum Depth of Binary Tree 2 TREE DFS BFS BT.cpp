//https://leetcode.com/problems/maximum-depth-of-binary-tree/
// COMPANY TAG FB BLOOMBERG LINKEDIN

// APPROACH BFS
class Solution {
public:
    int maxDepth(TreeNode* root) {
        int depth = 0;
        if(root == NULL)
            return 0;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            ++depth;
            
            int size = q.size();
            // while(size--){
            for(int i=0; i<size; ++i){
                TreeNode* temp = q.front();
                q.pop();
                if(temp->left)  q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return depth;
    }
};

