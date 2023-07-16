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






// APPROACH 2 DFS USING SET

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



// OR


class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        int ans = -1;
        int rootvalue = root->val;

        function<void(TreeNode*)> dfs = [&](TreeNode* node) {
            if(!node) return;
            if(ans != -1 && node->val >= ans) return;
            if(node -> val > rootvalue) ans = node -> val;

            dfs(node -> left);
            dfs(node -> right);
        };

        dfs(root);
        return ans;
    }
};


// T.C.  --> O(N) We need at most one traversal of the entire binary tree
// S.C.  --> O(N) we use the DFS method to traverse, and  stack space that needs to be used is O (n)





// DFS USING VECTOR

// Traverse the tree and store all the values in an array.
// Sort the array.
// Iterate over the array and find the first array element which is not equal to the minimum element of the array (i.e. the one present at index 0). If no such element is present then return -1.

class Solution {
public:
    void pre(vector<int> &v, TreeNode* root){
        if(root == NULL) return ;
        v.push_back(root -> val);
        pre(v, root -> left);
        pre(v, root -> right);
     }
    
    int findSecondMinimumValue(TreeNode* root) {
        vector<int> v;
        pre(v, root);

        sort(v.begin(), v.end());
        for(int i=0; i<v.size()-1; i++){
            if(v[i] != v[i+1]) return v[i+1];
        }
        return -1;
    }
};

// T.C. -->  O(N * logN)
// S.C. -->  O(N)







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







// APPRAOCH 3  RECURSION

class Solution {
public:
    int findSecondMinimumValue(TreeNode* root) {
        if((!root) or (!root -> left and !root -> right)) return -1;
        int L = root -> left -> val;
        int R = root -> right -> val;       

        if(root -> val == root -> left -> val)  L = findSecondMinimumValue(root -> left);
        if(root -> val == root -> right -> val) R = findSecondMinimumValue(root -> right);

        if(L != -1 and R != -1) return min(L, R);
        else if(L != -1) return L;
        else return R;
    }
};


// T.C. --> O(H)
// S.C. --> O(1)
