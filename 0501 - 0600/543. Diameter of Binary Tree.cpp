// A 1

class Solution {
public:
    int height(TreeNode* root){
        if(!root) return 0;
        int Lheight = height(root -> left);
        int Rheight = height(root -> right);
        return max(Lheight, Rheight) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;
        int op1 = diameterOfBinaryTree(root -> left);
        int op2 = diameterOfBinaryTree(root -> right);
        int op3 = height(root -> left) + height(root -> right);
        return max(op1, max(op2, op3));
    }
};

// T.C. --> O(N^2)






// A 2  -   DFS -  Recursive Approach:

class Solution {
public:
    int height(TreeNode* root, int &diameter){
        if(!root) return 0;
        int Lheight = height(root -> left, diameter);
        int Rheight = height(root -> right, diameter);
        diameter = max(diameter, Lheight + Rheight);
        return max(Lheight, Rheight) + 1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int Ldiameter = 0;
        height(root, Ldiameter);
        return Ldiameter;
    }
};


// OR


class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int dia = 0;
        function<int(TreeNode*)> dfs = [&](TreeNode* node) {
            if(!node) return 0;
            int L = dfs(node -> left);
            int R = dfs(node -> right);
            dia = max(dia, L + R);
            return 1 + max(L, R);
        };
        dfs(root);
        return dia;
    }
};






// A 3

class Solution {
public:
    pair<int, int> D(TreeNode* root){
        if(root == NULL) {
            pair<int, int> p = make_pair(0,0);
            return p;
        }
        pair<int, int> L = D(root -> left);
        pair<int, int> R = D(root -> right);
        
        int op1 = L.first; 
        int op2 = R.first;
        int op3 = L.second + R.second;

        pair<int, int>  res;
        res.first = max(op1, max(op2, op3));
        res.second = max(L.second, R.second) + 1;
        return res;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        return D(root).first;
    }
};


// OR

class Solution {
public:
    pair<int, int> helper(TreeNode* root){
        if(root == NULL) return {0, 0};
        pair<int, int> L = helper(root -> left);
        pair<int, int> R = helper(root -> right);    
        int h = 1 + max(L.first, R.first);
        int dia = max({L.first + R.first, L.second, R.second });
        return {h, dia};        
    }

    int diameterOfBinaryTree(TreeNode* root) {
        return helper(root).second;
    }
};

// T.C. --> O(N)






// A4 - BFS

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        int diameter = 0;
        queue<TreeNode*> que;
        que.push(root);
        while(!que.empty()) {
            int levelSize = que.size();
            for(int i=0; i<levelSize; ++i) {
                TreeNode* node = que.front();
                que.pop();
                
                int LD = depth(node -> left);
                int RD = depth(node -> right);
                diameter = max(diameter, LD + RD);
                
                if(node -> left)  que.push(node -> left);
                if(node -> right) que.push(node -> right);
            }
        }
        return diameter;
    }    
    int depth(TreeNode* node) {
        if(!node) return 0;
        return 1 + max(depth(node -> left), depth(node -> right));
    }
};






// A 5  -  Using a Class with Member Variables - Chat gpt

class Solution {
private:
    struct TreeInfo {
        int diameter;
        int depth;
    };
public:
    int diameterOfBinaryTree(TreeNode* root) {
        TreeInfo treeInfo = getTreeInfo(root);
        return treeInfo.diameter;
    }    
    TreeInfo getTreeInfo(TreeNode* node) {
        if(!node) return {0, 0};
        
        TreeInfo leftTree  = getTreeInfo(node->left);
        TreeInfo rightTree = getTreeInfo(node->right);
        
        int diameterThroughNode = leftTree.depth + rightTree.depth;
        int maxDiameter = max({diameterThroughNode, leftTree.diameter, rightTree.diameter});
        
        TreeInfo res;
        res.diameter = maxDiameter;
        res.depth = 1 + max(leftTree.depth, rightTree.depth);
        return res;
    }
};






// A 6  - iterative  approach using stack

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root) return 0;
        unordered_map<TreeNode*, int> heights; // store the heights
        stack<TreeNode*> nodes;    // store the value of nodes
        
        TreeNode* curr = root;
        TreeNode* prev = nullptr;
        int dia = 0;
        while(curr || !nodes.empty()) {
            while(curr) {
                nodes.push(curr);
                curr = curr -> left;
            }
            curr = nodes.top();
            if(curr -> right && curr -> right != prev) curr = curr -> right;
            else {
                nodes.pop();
                int LH = heights[curr->left];
                int RH = heights[curr->right];
                heights[curr] = 1 + max(LH, RH);
                dia = max(dia, LH + RH);
                prev = curr;
                curr = nullptr;
            }
        }
        return dia;
    }
};


