class Solution{
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, map<int, multiset<int>>> nodes; 
        queue<pair<TreeNode*, pair<int, int>>> que;
        
        if(root == NULL) return {};
        
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



