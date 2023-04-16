// APPROACH 1 [ RECURSIVE ]

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        inorder(root, res);
        return res;
    }
private:
    void inorder(TreeNode* root, vector<int>& res) {
        if (!root) return;
        inorder(root->left, res);
        res.push_back(root->val);
        inorder(root->right, res);
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



