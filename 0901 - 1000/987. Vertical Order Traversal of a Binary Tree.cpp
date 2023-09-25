// A1 - BFS

class Solution{
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root == NULL) return {};
        
        map<int, map<int, multiset<int>>> nodes; 
        queue<pair<TreeNode*, pair<int, int>>> que;
        que.push({root, {0, 0}});        
        while(!que.empty()) {
            auto temp = que.front();
            que.pop();
            
            auto frontNode = temp.first;
            int hd = temp.second.first;
            int level = temp.second.second;
            nodes[hd][level].insert(frontNode->val);
            
            if(frontNode->left) que.push({frontNode->left, {hd-1, level+1}});
            if(frontNode->right) que.push({frontNode->right, {hd+1, level+1}});
        }
        
        vector<vector<int>> res;
        for(auto i : nodes) {
            res.emplace_back();
            for(auto j : i.second) {
                for(auto k : j.second) {
                    res.back().push_back(k);
                }
            }
        }
        return res;
    }
};


// OR


class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;

        map<int, vector<pair<int, int>>> mp;         // Map to store nodes at each column index
        queue<pair<TreeNode*, pair<int, int>>> que;  // Queue for BFS traversal
        que.push({root, {0, 0}});

        while(!que.empty()) {
            int n = que.size();
            for(int i=0; i<n; ++i) {
                TreeNode* node = que.front().first;
                int col = que.front().second.first;
                int row = que.front().second.second;
                que.pop();

                mp[col].push_back({row, node->val});
                if(node -> left)  que.push({node -> left,  {col - 1, row + 1}});
                if(node -> right) que.push({node -> right, {col + 1, row + 1}});
            }
        }

        // Populate the result by iterating over the mp
        for(auto& it : mp) {
            sort(it.second.begin(), it.second.end());   // Sort by row and value
            vector<int> colValues;
            for(const auto& p : it.second) {
                colValues.push_back(p.second);
            }
            res.push_back(colValues);
        }
        return res;
    }
};


// OR


class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;

        map<int, vector<int>> mp1; // Map to store nodes at each column index
        queue<pair<TreeNode*, int>> que1; // Queue for level order traversal
        queue<int> que2; // Queue for column indices

        que1.push({root, 0});
        que2.push(0);

        while (!que1.empty()) {
            int n = que1.size();
            map<int, vector<int>> mp2;

            for (int i = 0; i < n; ++i) {
                TreeNode* node = que1.front().first;
                int col = que2.front();

                que1.pop();
                que2.pop();

                mp2[col].push_back(node->val);

                if(node->left) {
                    que1.push({node->left, col - 1});
                    que2.push(col - 1);
                }
                if(node->right) {
                    que1.push({node->right, col + 1});
                    que2.push(col + 1);
                }
            }

            for(auto& it : mp2) {
                vector<int>& tmp1 = mp1[it.first];
                vector<int> tmp2 = it.second;
                sort(tmp2.begin(), tmp2.end());
                tmp1.insert(tmp1.end(), tmp2.begin(), tmp2.end());
            }
        }

        for(auto& it : mp1) {
            res.push_back(it.second);
        }
        return res;
    }
};






// A2 - DFS

class Solution {
public:        
    void dfs(TreeNode* root, int col, int row, map<int, vector<pair<int, int>>>& colMap) {
        if(!root) return;

        colMap[col].push_back({row, root->val});
        dfs(root -> left,  col - 1, row + 1, colMap);
        dfs(root -> right, col + 1, row + 1, colMap);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> res;
        if(!root) return res;

        map<int, vector<pair<int, int>>> colMap; // Map to store nodes at each column index
        dfs(root, 0, 0, colMap);

        // Populate the result by iterating over the columnMap
        for(auto& it : colMap) {
            sort(it.second.begin(), it.second.end()); // Sort by row and value
            vector<int> colVal;
            for(auto& p : it.second) {
                colVal.push_back(p.second);
            }
            res.push_back(colVal);
        }
        return res;
    }
};






// A 3 

