// https://practice.geeksforgeeks.org/problems/height-of-binary-tree/1

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

// T.C. --> O(N)
// S.C. --> O(H)


// APPROACH 2 BFS
// It uses the concept of Level Order Traversal but we wont be adding null in the Queue.
// We will simply increase the counter when the level will increase and then remove all the nodes
// from the queue of the current Level.

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






class Solution {
public:
    int maxii = 1;
    int ans = 1;

    int solve(TreeNode* root){
        if(root == NULL) return 0;
        if(root->left){
            ans+=1 ;
            solve(root->left);
            maxii = max(ans, maxii);
            ans -= 1;
        }
        if(root->right){
            ans+=1;
            solve(root->right);
            maxii = max(ans, maxii);
            ans -= 1;
        }
        return 1;

    }

    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        solve(root);
        return maxii;
    }
};
