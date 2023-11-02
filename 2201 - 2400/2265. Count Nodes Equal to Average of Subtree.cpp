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

class Solution {
public:
    int res = 0;
    int averageOfSubtree(TreeNode* root) {
        if(root == NULL) return 0;

        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()) {
            TreeNode* node = que.front();
            que.pop();

            vector<int> v = dfs(node);
            int sum = v[0];
            int tmp = v[1];
            int avg = sum / tmp;

            if(node -> val == avg) res++;
            if(node -> left) que.push(node -> left);
            if(node -> right) que.push(node -> right);
        }
        return res; 
    }

    vector<int> dfs(TreeNode* root) {
        if(root == nullptr) return {0, 0};
        
        vector<int> L = dfs(root -> left);
        vector<int> R = dfs(root -> right);

        int sum = L[0] + R[0] + root -> val;
        int nodes = L[1] + R[1] + 1;

        return {sum, nodes};
    }
};






// A 3



