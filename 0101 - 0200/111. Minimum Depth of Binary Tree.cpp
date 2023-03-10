// Approach 1: Top-down DFS

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == NULL) return 0;
        if(root->left == NULL && root->right == NULL) return 1;
        if(root->left == NULL) return minDepth(root->right) + 1;
        if(root->right == NULL) return minDepth(root->left) + 1;
        return min(minDepth(root->left), minDepth(root->right)) + 1;
    }
};



// In this code, we first check if the root node is NULL, and if so, we return 0.
// If the root node has no left or right child, we return 1 since the depth is just 1.
// If the root node has only one child, we recurse on that child and add 1 to the result. 
// If the root node has two children, we take the minimum of the depths of the left and right
// subtrees and add 1 to the result. Finally, we create a new tree and test the code on it.

// T.C. --> O(N)
// S.C. --> O(h)







class Solution {
public:
    int minDepth(TreeNode* root) {
        if(root == nullptr) return 0;
        
        deque<TreeNode*> d;
        d.push_back(root);
        
        int res = 1;
        while(d.size()) {
            int n = d.size();
            for (int i=0; i<n; i++){
                TreeNode* cur = d.front();
                d.pop_front();
                if(cur->left == nullptr && cur->right == nullptr) return res;
                if(cur->left)  d.push_back(cur->left);
                if(cur->right) d.push_back(cur->right);
            }
            res++;
        }
        return res;
    }
};



class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL) return 0;
        
        queue<pair<TreeNode*, int>> q;
        q.push({root, 1});
        
        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int depth = q.front().second;
            q.pop();
            
            if (node->left == NULL && node->right == NULL) return depth;            
            if (node->left != NULL) q.push({node->left, depth + 1});
            if (node->right != NULL) q.push({node->right, depth + 1});

        }        
        return -1;
    }
};

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);    // q.emplace(root);
        int height = 0;
        while(!q.empty()) {
            int nodes = q.size();
            height++;
            while(nodes--) {
                TreeNode* node = q.front();
                q.pop();
                if(node->left == NULL && node->right==NULL) return height;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }

        return height;
    }
};


class Solution {
public:
    int minDepth(TreeNode* root) {
        return depth(root);
    }

    int depth(TreeNode* node) {
        if (node == nullptr) { return 0; }

        int left = depth(node->left);
        int right = depth(node->right);
        if (node->left == nullptr || node->right == nullptr) {
            return node->left == nullptr ? right + 1 : left + 1;
        }
        node->left = nullptr;
        node->right = nullptr;

        return std::min(left, right) + 1;
    }
};
