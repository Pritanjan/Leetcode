// A 1 [ RECURSIVE ]
// SUBTRACT THE VALUE OF CURRENT NODE FROM SUM UNTILL IT
// REACHES A LEAF NODE & THE SUBTRACTION EQUALS TO 0, 
// THEN WE KNOW THAT WE GOT THE PATH.

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL) return false;
        if(root->left == NULL && root->right == NULL && targetSum  - root->val == 0) return true;
        // if(root->left == NULL && root->right == NULL) return targetSum == root->val;
        else return hasPathSum(root->left, targetSum - root->val) || hasPathSum(root->right, targetSum - root->val) ;
    }
};

// root.left == null && root.right == null
// This tells us if the current node is a leaf node

// sum - root.val == 0
// This checks that, if we add this leaf node's value to our current sum, 
// will it be equal to the target sum?


// T.C. --> O(N), 
// In Worst case, you check all elements and still find no path.

// S.C. --> O(log(n)) 
// height of the tree is the max space taken up at any point in the stack


// OR


class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;

        targetSum -= root->val;

        if(!root -> left && !root -> right) return targetSum == 0;

        bool LRes = hasPathSum(root -> left, targetSum);
        bool RRes = hasPathSum(root -> right, targetSum);

        return LRes || RResult;
    }
};


// OR


class Solution {
public:
    bool helper(TreeNode* root, int tgtSum, int currSum) {
        if(!root) return false;
        
        currSum += root -> val;

        if(!root -> left && !root -> right) return currSum == tgtSum;
        
        return helper(root -> left, tgtSum, currSum) || helper(root -> right, tgtSum, currSum);
    }

    bool hasPathSum(TreeNode* root, int tgtSum) {
        return helper(root, tgtSum, 0);
    }
};





// A 2 - Iterative DFS using a stack ]

class Solution {
public:        
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;            // base case: empty tree
        stack<pair<TreeNode*, int>> stk;

        stk.push(make_pair(root, targetSum - root->val));
        while(!stk.empty()) {
            auto p = stk.top();
            stk.pop();

            TreeNode* node = p.first;
            int sum = p.second;
            
            if(!node->left && !node->right && sum == 0) return true; // found a path
            if(node -> right) stk.push(make_pair(node->right, sum - node->right->val));
            if(node -> left)  stk.push(make_pair(node->left, sum - node->left->val));
        }
        return false;   // no path found
    }
};

// T.C. --> O(N)
// S.C. --> O(H), it has a recursive call stack depth of h


// OR 

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
    
        stack<TreeNode*> nodes;
        stack<int> sums;
        
        nodes.push(root);
        sums.push(targetSum - root -> val);

        while(!nodes.empty()) {
            TreeNode* curr = nodes.top(); nodes.pop();
            int currSum = sums.top(); sums.pop();

            if(!curr -> left && !curr -> right && currSum == 0) return true;
            if(curr -> right) {
                nodes.push(curr -> right);
                sums.push(currSum - curr -> right -> val);
            }
            if(curr -> left) {
                nodes.push(curr -> left);
                sums.push(currSum - curr -> left -> val);
            }
        }
        return false;
    }
};





// A 3 [ Iterative solution using queue ]

class Solution {
public:        
    bool hasPathSum(TreeNode* root, int targetSum) {    
        if(!root) return false;        // base case: empty tree
        queue<TreeNode*> que;
        
        queue<int> sums;
        que.push(root);

        sums.push(targetSum - root->val);
        while (!que.empty()) {
            TreeNode* node = que.front();
            que.pop();

            int sum = sums.front();
            sums.pop();

            if(!node -> left && !node -> right && sum == 0) return true; // found a path
            if(node -> left) {
                que.push(node -> left);
                sums.push(sum - node -> left -> val);
            }
            if(node -> right) {
                que.push(node -> right);
                sums.push(sum - node -> right -> val);
            }
        }
        return false; // no path found
    }
};

// T.C. --> O(N)
// S.C. --> O(H), it uses stack or a queue to traverse the tree in a depth-first or breadth-first manner.






// A 4 - Memorization

class Solution {
public:
    bool memo(TreeNode* root, int tgtSum, unordered_map<TreeNode*, bool>& mp) {
        if(!root) return false;
        if(mp.find(root) != mp.end()) return mp[root];

        bool res = false;
        if(!root -> left && !root -> right) res = tgtSum == root -> val;
        else res = memo(root->left, tgtSum - root -> val, mp) || memo(root -> right, tgtSum - root -> val, mp);
        
        mp[root] = res;
        return res;
    }

    bool hasPathSum(TreeNode* root, int tgtSum) {
        unordered_map<TreeNode*, bool> mp;
        return memo(root, tgtSum, mp);
    }
};





// A 5

class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        
        // Use a set to store the sums reached so far
        unordered_set<int> sums;
        sums.insert(0); // Starting with 0 as the initial sum

        return helper(root, targetSum, 0, sums);
    }
private:
    bool helper(TreeNode* root, int targetSum, int currSum, unordered_set<int>& sums) {
        if(!root) return false;
        
        currSum += root -> val;

        if(!root -> left && !root -> right) return sums.count(currSum - targetSum) > 0;
        
        bool LRes = helper(root -> left,  targetSum, currSum, sums);
        bool RRes = helper(root -> right, targetSum, currSum, sums);

        sums.insert(currSum);

        return LRes || RRes;
    }
};

