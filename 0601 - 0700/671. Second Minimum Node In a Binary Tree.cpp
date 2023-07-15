// APPROACH 1 BFS

class Solution {
public:    
    int findSecondMinimumValue(TreeNode* root) {
        if(root -> left == nullptr) return -1;

        queue<TreeNode*> que;
        que.push(root);

        int m = root->val;
        int t = pow(2, 31)-1;
        int f = 0;   

        while(!que.empty()){
            root = que.front();
            que.pop();
            if(root -> left){
                if(root -> left -> val != root -> right -> val){
                    if(root -> left -> val > m and root -> left -> val <= t) {
                        t = root -> left -> val;
                        f = 1;
                    }
                    if(root -> right -> val > m and root -> right -> val <= t){
                        t = root -> right -> val;
                        f = 1;
                    }
                }      
                que.push(root->left);
                que.push(root->right);  
            } 
        }

        if(f == 0) return -1;
        return t;
    }
};








// APPROACH 2 DFS

class Solution {
public:
     void pre(set<int> &v, TreeNode* root){
         if(root == NULL) return ;
        //  v.push_back(root -> val);
         v.insert(root -> val);
         pre(v, root -> left);
         pre(v, root -> right);
     }
    
    int findSecondMinimumValue(TreeNode* root) {
        set<int> v;
        pre(v, root);

        if(v.size() < 2) return -1;
        auto it = v.begin(); 
        it++;

        return *it;
    }
};






// LEETCODE EDITORIAL 2    

class Solution {
private:
    int min1;
    long long ans = LLONG_MAX;

    void dfs(TreeNode* root) {
        if(root != nullptr) {
            if(min1 < root -> val && root -> val < ans) {
                ans = root -> val;
            } 
            else if(min1 == root -> val) {
                dfs(root -> left);
                dfs(root -> right);
            }
        }
    }

public:
    int findSecondMinimumValue(TreeNode* root) {
        min1 = root -> val;
        dfs(root);
        return ans < LLONG_MAX ? static_cast<int>(ans) : -1;
    }
};
