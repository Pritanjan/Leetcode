// APPROACH 1 [ RECURSIVE ]

class Solution {
public:
    void in(TreeNode* root, vector<int> &res){
        if(!root) return ;
        in(root -> left, res);
        res.push_back(root -> val);
        in(root -> right, res);
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        in(root, res);
        return res;
    }
};

//Time complexity: O(n)
//The time complexity is O(n) because the recursive function is T(n)=2·T(n/2)+1.

//Space complexity: O(n)
//The worst case space required is O(n), and in the average case it's O(logn) where n is number of nodes.






// APPROACH 2 [ Iterative method using Stack ]

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> s;
        while (root || !s.empty()) {
            while (root) {
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            res.push_back(root->val);
            root = root->right;
        }
        return res;
    }
};

// Time complexity: O(n)
// Space complexity: O(n)






// APPROACH 3 [ Morris Traversal ]

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        while(root) {
            if(root->left) {
                TreeNode* pre = root->left;
                while(pre->right && pre->right != root) pre = pre->right;
                if(!pre -> right) {
                    pre -> right = root;
                    root = root -> left;
                } 
                else {
                    pre -> right = nullptr;
                    res.push_back(root -> val);
                    root = root -> right;
                }
            } 
            else {
                res.push_back(root->val);
                root = root->right;
            }
        }
        return res;
    }
};

// Time complexity: O(n)
// Space complexity: O(1)






// APPROACH 4 [ Iterative approach using a stack and flag ]

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<pair<TreeNode*, bool>> s;
        s.push(make_pair(root, false));
        
        while(!s.empty()) {
            auto cur = s.top();
            s.pop();            
            if(!cur.first) continue;
            if(cur.second) res.push_back(cur.first->val);
            else {
                s.push(make_pair(cur.first->right, false));
                s.push(make_pair(cur.first, true));
                s.push(make_pair(cur.first->left, false));
            }
        }
        return res;
    }
};






// A 5  - Use 2 Stack

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> nodes;
        stack<bool> visited;

        if(root != nullptr) {
            nodes.push(root);
            visited.push(false);
        }

        while(!nodes.empty()) {
            TreeNode* curr = nodes.top();
            bool isVisited = visited.top();
            nodes.pop();
            visited.pop();

            if(curr == nullptr) continue;
            if(isVisited) res.push_back(curr -> val);
            else {
                if(curr -> right != nullptr) {
                    nodes.push(curr -> right);
                    visited.push(false);
                }
                nodes.push(curr);
                visited.push(true);
                if(curr -> left != nullptr) {
                    nodes.push(curr -> left);
                    visited.push(false);
                }
            }
        }
        return res;
    }
};





// A 6 
