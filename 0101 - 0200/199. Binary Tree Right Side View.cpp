// Right View of Binary Tree
// A 1 DFS 

class Solution {
public:
    void RT(TreeNode* root, int level, int& mxLevel, vector<int>& res){
        if(root == nullptr) return ;
        if(level > mxLevel) {
            mxLevel = level;
            res.push_back(root -> val);
        }    
        RT(root->right, level + 1, mxLevel, res);
        RT(root->left, level + 1, mxLevel, res);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        int mxLevel = -1;
        RT(root, 1, mxLevel, res);
        return res;
    }
};


// OR


class Solution{
public:    
    void helper(TreeNode* node, vector<int>& ans, int n) {
        if(node == NULL) return;
        if(n == ans.size()) ans.push_back(node -> val);
        
        helper(node -> right, ans, n+1);
        helper(node -> left,  ans, n+1);
    }    
    vector<int> rightSideView(TreeNode* node) {
        vector<int> ans;
        helper(node, ans, 0);
        return ans;
    }
};

// T.C. O(N)
// S.C. O(h)






// A 2 BFS 

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        vector<int> res;
        queue<TreeNode*> que;
        que.push(root);
        
        while(!que.empty()){
            int n = que.size();
            while(n--){
                TreeNode* temp = que.front();  que.pop();

                if(n == 0) res.push_back(temp -> val);
                if(temp -> left != NULL) que.push(temp -> left);
                if(temp -> right != NULL) que.push(temp -> right);
            }
        }
        return res;
    }
};

// T.C. O(N)
// S.C. O(N)






// A 3 - DFS with stack

class Solution {
public:    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;

        stack<pair<TreeNode*, int>> stk;  // Stack to perform DFS along with depth information
        stk.push({root, 0});  // Push the root node along with depth 0

        while(!stk.empty()) {
            TreeNode* node = stk.top().first;
            int depth = stk.top().second;
            stk.pop();

            if(depth == res.size()) {
                // If the result vector size is the same as the current depth,
                // it means we are visiting the rightmost node at this depth.
                res.push_back(node -> val);
            }

            // Perform DFS on the left and right subtrees, pushing them onto the stack
            // along with their respective depths.
            if(node -> left)  stk.push({node -> left,  depth + 1});
            if(node -> right) stk.push({node -> right, depth + 1});
        }
        return res;
    }
};

















// Bottom View of Binary Tree
// https://practice.geeksforgeeks.org/problems/bottom-view-of-binary-tree/1

class Solution {
public:
    vector <int> bottomView(Node *root) {
        if(root == NULL) return {};
        
        vector<int> v;
        map<int, int> mp;
        queue<pair<Node*, int>> que;
        que.push({root, 0});
        
        while(!que.empty()){
            Node* temp = que.front().first;
            int hd = que.front().second;
            que.pop();
            
            mp[hd] = temp -> data;
            
            if(temp -> left)  que.push({temp -> left, hd - 1});
            if(temp -> right)  que.push({temp -> right, hd + 1});
        }
        
        for(auto it=mp.begin(); it != mp.end(); it++){
            v.push_back(it -> second);
        }
        return v;
    }
};


