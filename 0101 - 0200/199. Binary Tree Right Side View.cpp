// Right View of Binary Tree

// APPROACH 2 DFS 

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


// T.C. O(N)
// S.C. O(h)


// APPROACH 2 BFS 

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
                TreeNode* temp = que.front();
                que.pop();

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

// Left View of Binary Tree
// https://www.geeksforgeeks.org/print-left-view-binary-tree/
// https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

void LEFT(Node* root, int level, int& mxLevel, vector<int>& res){
    if(root == nullptr) return ;
    
    if(level > mxLevel) {
        mxLevel = level;
        res.push_back(root -> data);
    }
    
    
    LEFT(root->left, level + 1, mxLevel, res);
    LEFT(root->right, level + 1, mxLevel, res);
}

vector<int> leftView(Node *root){
    vector<int> res;
    int mxLevel = -1;
    LEFT(root, 1, mxLevel, res);
    return res;
}





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


