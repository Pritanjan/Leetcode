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


// OR
// 1. Use a queue for level-order traversal of the binary tree.
// 2. Initialize the queue with the root node and an additional nullptr sentinel node
//    to indicate the end of a level.
// 3. During each iteration of the while loop, we pop a node from the queue.
// 4. If the node is not sentinel node, check if the next node in the queue is a sentinel node (nullptr). 
//    If it is, it means we have reached the last node at the current level, 
//    so we add its value to the result vector.
// 5. We enqueue the left and right children of each non-sentinel node if they exist.
// 6. If the popped node is a sentinel node and there are more nodes in the queue 
//    (i.e., it's not the end of the traversal), enqueue another sentinel node to indicate the end of
//    the next level.

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == NULL) return {};
        vector<int> res;
        
        queue<TreeNode*> que;
        que.push(root);
        que.push(NULL);  // Sentinel node to indicate the end of a level
        while(!que.empty()){
            TreeNode* node = que.front();  que.pop();
            if(node) {
                // If it's not a sentinel node, add its value to the result
                if(que.front() == nullptr) res.push_back(node -> val);

                // Add the left and right children to the queue if they exist
                if(node -> left != NULL)  que.push(node -> left);
                if(node -> right != NULL) que.push(node -> right);
            }
            // If it's a sentinel node and there are more nodes in the queue,
            // enqueue another sentinel node to indicate the end of the next level.
            else if(!que.empty()) que.push(nullptr);
        }
        return res;
    }
};







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






// A 4
// 1. Maintain two vectors, currLevel and nextLevel, to keep track of the nodes at the current level
//    and the nodes at the next level in the binary tree.
// 2. Start with the root node and add it to currentLevel.
// 3. During each iteration of the while loop, process the nodes in currLevel from left to right. 
//    The last node processed in this loop (i.e., currLevel.back()) will be the rightmost node
//    at the current level, so we add its value to the result vector.
// 4. Then prepare for the next level traversal by clearing the nextLevel vector and
//    adding the left and right children of the nodes in currentLevel to nextLevel.
// 5. Finally, swap currLevel and nextLevel to prepare for the next iteration of the loop.

class Solution {
public:    
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(!root) return res;
        
        vector<TreeNode*> currLevel, nextLevel;
        currLevel.push_back(root);

        while(!currLevel.empty()) {
            TreeNode* R = currLevel.back();
            res.push_back(R->val);

            // Prepare for the next level traversal
            nextLevel.clear();

            for(TreeNode* node : currLevel) {
                if(node -> left)  nextLevel.push_back(node -> left);
                if(node -> right) nextLevel.push_back(node -> right);
            }

            // Swap the current and next levels
            swap(currLevel, nextLevel);
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


