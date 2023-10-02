// A 1 - Recursion -  DFS  -  (Top-down approah)  

class Solution {
public:
    int sum;
    int calcSum(TreeNode* root){
        if(root == NULL) return 0;
        int left  = max(0, calcSum(root->left)) ;
        int right = max(0, calcSum(root->right));
        
        sum = max(sum, left + right + root->val);
        return max(left,right) + root->val;
        // return max(left,right) + root->val;  // bottom - UP
    }
    
    int maxPathSum(TreeNode* root) {
        sum = INT_MIN;
        calcSum(root);
        return sum;
    }
};

// T.C. --> O(N)
// S.C. --> O(N)






// A 2  

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int sum = INT_MIN; // placeholder to be updated
        function<int(TreeNode*)> helper = [&](TreeNode* node) {
            if(!node) return 0;
            int left  = max(helper(node -> left), 0);
            int right = max(helper(node -> right), 0);

            sum = max(sum, node -> val + left + right);
            return node -> val + max(left, right);
        };
        
        helper(root); // Starts the recursion chain
        return sum;
    }
};






// A 3

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        if(!root) return 0;

        int maxSum = root->val;
        queue<TreeNode*> que;
        que.push(root);

        while(!que.empty()) {
            TreeNode* node = que.front();
            que.pop();

            // Calculate the maximum path sum including the current node as the root
            int currMax = helper(node, maxSum);

            // Enqueue the left and right children for further exploration
            if(node -> left)  que.push(node -> left);
            if(node -> right) que.push(node -> right);
        }
        return maxSum;
    }
private:
    int helper(TreeNode* node, int& maxSum) {
        if(!node) return 0;

        // Calculate the maximum path sum in the left and right subtrees
        int leftMax  = max(0, helper(node -> left,  maxSum));
        int rightMax = max(0, helper(node -> right, maxSum));

        // Calculate the maximum path sum that includes the current node
        int currMax = node -> val + leftMax + rightMax;

        // Update the global maxSum if the current path is greater
        maxSum = max(maxSum, currMax);

        // Return the maximum path sum that can extend upwards to the parent
        return node -> val + max(leftMax, rightMax);
    }
};






// A 4 - post-order traversal without recursion

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        unordered_map<TreeNode*, int> mp;
        stack<TreeNode*> stk;

        TreeNode* prev = nullptr;
        while(root || !stk.empty()) {
            while(root) {
                stk.push(root);
                root = root -> left;
            }
            root = stk.top();

            // Check if we should process this node
            if(!root -> right || root -> right == prev) {
                int leftMax  = max(0, mp[root -> left]);
                int rightMax = max(0, mp[root -> right]);

                int tmp = root->val + leftMax + rightMax;
                maxSum = max(maxSum, tmp);

                // Update the max path sum for the current node
                mp[root] = root -> val + max(leftMax, rightMax);

                stk.pop();
                prev = root;
                root = nullptr;
            }
            else root = root -> right;
        }
        return maxSum;
    }
};






// A 5 -  Iterative DFS - gfg
// T.C. --> O(N)
// S.C. --> O(H)

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int mx = INT_MIN;
        stack<pair<TreeNode*, int>> stk;
        stk.push(make_pair(root, 0));

        while(!stk.empty()) {
            auto node = stk.top().first;
            int state = stk.top().second;
            stk.pop();

            if(node == nullptr) continue;

            if(state == 0) {
                // First visit to the node
                stk.push(make_pair(node, 1));
                stk.push(make_pair(node -> left, 0));
            }
            else if(state == 1) {
                // Second visit to the node
                stk.push(make_pair(node, 2));
                stk.push(make_pair(node -> right, 0));
            }
            else {
                // Third visit to the node
                int Lsum = (node -> left  != nullptr) ? node -> left  -> val : 0;
                int Rsum = (node -> right != nullptr) ? node -> right -> val : 0;
                mx = max(mx, node -> val + max(0, Lsum) + max(0, Rsum));
                int tmpSum = max(Lsum, Rsum);
                node -> val += max(0, tmpSum);
            }
        }
        return mx;
    }
};



