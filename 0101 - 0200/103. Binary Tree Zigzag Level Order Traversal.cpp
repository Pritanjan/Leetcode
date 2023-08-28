// A 1 a

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) return ans;         
        queue<TreeNode*> q;
        q.push(root);
        
        bool reverse = false;
        while (!q.empty()) {
            int n = q.size();
            vector<int> level(n);
            
            // process level
            for (int i = 0; i < n; i++) {
                TreeNode* node = q.front();
                q.pop();
                
                int index = reverse ? n - i - 1 : i;
                level[index] = node->val;
                
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }            
            // change direction 
            reverse = !reverse;            
            ans.push_back(level);
        }
        return ans;
    }
};


// OR


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) { 
        vector<vector<int>>res;
        if(root == NULL) return res;

        queue<TreeNode*>q;
        q.push(root);
        int cnt = -1;
        while(!q.empty()) {
            int n = q.size();
            vector<int> l;
            for(int i=0; i<n; ++i){
                auto temp = q.front();
                q.pop();
                
                if(temp->left!=NULL) q.push(temp->left);
                if(temp->right!=NULL) q.push(temp->right);
                l.push_back(temp->val);
            }
            cnt++;         
            if(cnt % 2 != 0) reverse(l.begin(),l.end());
            res.push_back(l);
        }
        return res;
    }
};


// OR


class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;

        queue<TreeNode*> que;
        que.push(root);
        bool LtR = true;      // leftToRight

        while(!que.empty()) {
            int n = que.size();  // levelSize
            vector<int> levelValues(n);

            for(int i=0; i<n; ++i) {
                TreeNode* node = que.front();
                que.pop();

                int idx = LtR ? i : n - i - 1;
                levelValues[idx] = node -> val;

                if(node -> left)  que.push(node -> left);
                if(node -> right) que.push(node -> right);
            }
            res.push_back(levelValues);
            LtR = !LtR;
        }
        return res;
    }
};






// A 2

class Solution {
public:
    vector<vector<int>> ret;
    void DFS(TreeNode* root, int depth) {
        if(root == nullptr) return;
        if(depth >= ret.size()) ret.push_back(vector<int>());
        
        // add this value to the list
        if(depth % 2 == 0) ret[depth].push_back(root -> val);
        else ret[depth].insert(ret[depth].begin(), root -> val);
        
        depth++;
        DFS(root -> left, depth);
        DFS(root -> right, depth);
    }
    
    // Clown ass order traversal
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        DFS(root, 0);
        return ret;
    }
};






// A 3

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;

        stack<TreeNode*> currentLevel;
        stack<TreeNode*> nextLevel;
        bool leftToRight = true;
        currentLevel.push(root);

        while(!currentLevel.empty()) {
            vector<int> levelValues;
            while(!currentLevel.empty()) {
                TreeNode* node = currentLevel.top();
                currentLevel.pop();
                levelValues.push_back(node -> val);

                if(leftToRight) {
                    if(node -> left)  nextLevel.push(node -> left);
                    if(node -> right) nextLevel.push(node -> right);
                } 
                else {
                    if(node -> right) nextLevel.push(node -> right);
                    if(node -> left)  nextLevel.push(node -> left);
                }
            }
            res.push_back(levelValues);
            swap(currentLevel, nextLevel);
            leftToRight = !leftToRight;
        }
        return res;
    }
};






// A 4 - Using a deque (Double-ended Queue)

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;

        deque<TreeNode*> dq;
        dq.push_back(root);
        bool LtR = true;

        while(!dq.empty()) {
            int n = dq.size();  // level size
            vector<int> v(n);   // levelValues

            for(int i=0; i<n; ++i) {
                if(LtR) {
                    TreeNode* node = dq.front();
                    dq.pop_front();
                    v[i] = node -> val;

                    if(node -> left)  dq.push_back(node -> left);
                    if(node -> right) dq.push_back(node -> right);
                } 
                else {
                    TreeNode* node = dq.back();
                    dq.pop_back();
                    v[i] = node -> val;
                    if(node -> right) dq.push_front(node -> right);
                    if(node -> left)  dq.push_front(node -> left);
                }
            }
            res.push_back(v);
            LtR = !LtR;
        }
        return res;
    }
};






// A 5 -

