// A 1

class Solution {
public:
    int height(TreeNode* root) {
        if(!root) return NULL;
        return 1 + max(height(root->left), height(root->right));
    }
    bool isBalanced(TreeNode* root) {
        int LH = 0, RH = 0;
        if(root == NULL) return true;

        LH = height(root -> left);
        RH = height(root -> right);
        if(abs(LH - RH) > 1) return 0;
        // this function only checks if the root node is balanced or not, 
        // but it does not check if its subtrees are balanced. 
      
        // To check if a tree is balanced, we need to recursively check if its left and
        // right subtrees are balanced as well.
        // So we need to call the isBalanced function recursively on the left and right subtrees
        // and return true only if both subtrees are balanced and the difference in height 
        // between them is less than or equal to 1.
        return isBalanced(root->left) && isBalanced(root->right);
    }
};

// T.C. O(N^2)






// A 2

class Solution {
public:
    int height(TreeNode* root) {
        if (!root) return 0;        
        int LH = height(root->left);
        if (LH == -1) return -1;
        int RH = height(root->right);
        if (RH == -1) return -1; 
        
        if (abs(LH - RH) > 1) return -1;
        return max(LH, RH) + 1;
    }
    bool isBalanced(TreeNode* root) {
        return height(root) != -1;
    }
};

// T.C. --> O(N), As the height function is called once for each node in the tree.
// S.C. --> O(log N)
// On the basis of height function
// O(log N)  [best  case] (when the tree is balanced)
// O(N)      [Wrost Case] (when the tree is completely unbalanced).
// O(log N)  [avg   case]






// A 3

class Solution {
public:
    static bool isBalanced(TreeNode* root) {
        if (root == NULL) return true;        
        dfs(root);
        queue<TreeNode*> que;
        que.push(root);
        
        while(!que.empty()) {
            TreeNode* node = que.front();
            que.pop();
            int leftHeight = (node->left == NULL) ? 0 : node->left->val;
            int rightHeight = (node->right == NULL) ? 0 : node->right->val;
            
            if(abs(leftHeight - rightHeight) > 1) return false;
            if(node->left != NULL) que.push(node->left);
            if(node->right != NULL) que.push(node->right);
        }
        return true;
    }
private:
    static void dfs(TreeNode* root) {
        if(root == NULL) return ;    
        dfs(root->left);
        dfs(root->right);
        
        if(root != NULL && root->left == NULL && root->right == NULL) root->val = 1;
        else {
            int leftHeight = (root->left == NULL) ? 0 : root->left->val;
            int rightHeight = (root->right == NULL) ? 0 : root->right->val;
            root->val = max(leftHeight, rightHeight) + 1;
        }
    }
};


// OR


class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        queue<TreeNode*> nodes;
        nodes.push(root);
        while(!nodes.empty()) {
            TreeNode* node = nodes.front();
            nodes.pop();
            
            if(abs(Height(node -> left) - Height(node -> right)) > 1) return false;
            if(node -> left)  nodes.push(node -> left);
            if(node -> right) nodes.push(node -> right);
        }
        return true;
    }
private:
    int Height(TreeNode* node) {
        if(node == nullptr) return 0;
        return max(Height(node -> left), Height(node -> right)) + 1;
    }
};


// OR


class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        
        queue<TreeNode*> nodes;
        nodes.push(root);        
        while(!nodes.empty()) {
            int n = nodes.size();
            // bool level_balanced = true; // Assume the current level is balanced            
            for(int i=0; i<n; i++) {
                TreeNode* node = nodes.front();
                nodes.pop();
                
                int LH = getHeight(node->left);
                int RH = getHeight(node->right);
                
                // If the current node is unbalanced, return false
                if(abs(LH - RH) > 1) return false;                 
                if(node -> left)  nodes.push(node -> left);
                if(node -> right) nodes.push(node -> right);
            }
        }
        
        return true; // If the tree is balanced at every level, return true
    }
private:
    int getHeight(TreeNode* root) {
        if(root == nullptr) return 0;
        int LH = getHeight(root -> left);
        int RH = getHeight(root -> right);
        return 1 + max(LH, RH);
    }
};






// A 4  Recursion

class Solution {
public:
    int height(TreeNode* root) {
        if(root == NULL) return 0;
        else return max(height(root -> left), height(root -> right)) + 1;
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return true;
        else return abs(height(root -> left) - height(root -> right)) <= 1 && isBalanced(root -> left) && isBalanced(root -> right);
    }
};






// A 5  - DFS - Iterative 
// Maintain a stack to simulate the DFS traversal and use a hash map to store the heights
// of each node to avoid redundant calculations. 
// Also keep track of the maximum height encountered during the traversal and
// check if the tree remains balanced while traversing.

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        
        stack<TreeNode*> nodes;   // store the value of nodes
        unordered_map<TreeNode*, int> heights;  // store the height
        TreeNode* prev = nullptr;
        int maxHeight = 0;

        while(root || !nodes.empty()) {
            while(root) {
                nodes.push(root);
                root = root -> left;
            }
            root = nodes.top();
            if(root -> right && root -> right != prev) root = root -> right;
            else {
                nodes.pop();
                int LH = heights[root -> left];
                int RH = heights[root -> right];
                heights[root] = 1 + max(LH, RH);
                if(abs(LH - RH) > 1) return false;
                maxHeight = max(maxHeight, heights[root]);
                prev = root;
                root = nullptr;
            }
        }
        return true;
    }
};






// A 6

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        if(root == nullptr) return true;
        queue<TreeNode*> nodes;
        nodes.push(root);        
        while(!nodes.empty()) {
            int n = nodes.size();
            for(int i=0; i<n; i++) {
                TreeNode* node = nodes.front();
                nodes.pop();
                
                int LH = getHeight(node->left);
                int RH = getHeight(node->right);                
                if(abs(LH - RH) > 1) return false;                 
                if(node -> left)  nodes.push(node -> left);
                if(node -> right) nodes.push(node -> right);
            }
        }
        
        return true; 
    }
private:
    int getHeight(TreeNode* root) {
        if(root == nullptr) return 0;
        int LH = getHeight(root -> left);
        int RH = getHeight(root -> right);
        return 1 + max(LH, RH);
    }
};






// A 7 - DFS

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        return checkBalance(root).first;
    }
    
private:
    // Returns a pair of bool (balance status) and int (height)
    pair<bool, int> checkBalance(TreeNode* root) {
        if (root == nullptr) {
            // A null node is balanced with a height of 0
            return make_pair(true, 0);
        }
        
        // Recursively check left subtree
        pair<bool, int> left = checkBalance(root->left);
        if (!left.first) {
            // If the left subtree is unbalanced, no need to proceed further
            return make_pair(false, 0);
        }
        
        // Recursively check right subtree
        pair<bool, int> right = checkBalance(root->right);
        if (!right.first) {
            // If the right subtree is unbalanced, no need to proceed further
            return make_pair(false, 0);
        }
        
        // Check balance at the current node
        bool isBalanced = abs(left.second - right.second) <= 1;
        
        // Calculate the height of the current node
        int height = 1 + max(left.second, right.second);
        
        return make_pair(isBalanced, height);
    }
};





