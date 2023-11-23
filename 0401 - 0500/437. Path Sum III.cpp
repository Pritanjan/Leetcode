// A 1

class Solution{
public:
    void f(TreeNode* root, int k, int &cnt, vector<int> &path){
        if(root == NULL) return ;

        path.push_back(root -> val);

        f(root -> left, k, cnt, path);     // left
        f(root -> right, k, cnt, path);    // right
        
        long long  sum = 0;            // check for k sum
        for(int i=path.size()-1; i>=0; i--){
            sum += path[i];
            if(sum == k) cnt++;
        }
        path.pop_back();
    }
    
    int pathSum(TreeNode *root,int k){
        vector<int> path;
        int cnt = 0;
        f(root, k, cnt, path);
        return cnt;
    }
};

