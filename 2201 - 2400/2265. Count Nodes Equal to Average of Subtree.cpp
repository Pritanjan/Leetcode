// A 1

class Solution {
public:
    int res = 0;
private: 
    vector<int> dfs(TreeNode* root) {
        if(root == NULL) return {0, 0};
        
        vector<int> L = dfs(root -> left);
        vector<int> R = dfs(root -> right);

        int sum = L[0] + R[0] + root -> val;
        int nodes = L[1] + R[1] + 1;

        int avg = sum / nodes;
        if(root -> val == avg) res++;
        return {sum, nodes};
    }
public:
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return res;
    }
};






// A 2



