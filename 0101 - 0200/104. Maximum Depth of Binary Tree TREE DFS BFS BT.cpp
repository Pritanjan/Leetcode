// COMPANY TAG FB BLOOMBERG LINKEDIN

// APPROACH 1 RECURSION

class Solution {
public:
    int Mdepth = 0;
    int maxDepth(TreeNode* root, int depth = 1) {
        if(root == NULL)
            return 0;
        
        if(!root->left && !root->right){
            if(depth > Mdepth)
                Mdepth = depth;
            
            return Mdepth;
        }
        maxDepth(root->left, depth+1);
        maxDepth(root->right,depth+1);
        
         return Mdepth;
    }
};







// APPROACH 2 BFS

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





// APPROACH 3 DFS
class Solution {
public:
    int depth(TreeNode* node){
        // IF NODE IS NULL THEN DEPTH IS 0
        if(!node)
            return NULL;
        
        int LD = depth(node->left) ;    // RETURNS LENGTH OF LEFT NODE
        int RD = depth(node->right);    // RETURNS LENGTH OF RIGHT NODE
        
        return 1+ max(LD, RD);          // 1 IS ADDED FOR ROOT NODE 
    }
    
    int maxDepth(TreeNode* root) {
        // if(!root)
        //     return 0;
        // else
            return depth(root);
    }
};

// APPROACH Same as 3rd 
class Solution {
public:
   int maxDepth(TreeNode* root) {
       if(!root)
           return NULL;
       return 1 + max(maxDepth(root->left), maxDepth(root->right));
   }
};







