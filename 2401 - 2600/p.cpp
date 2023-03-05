/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, int> levelSums;
    
        auto updateQueue = [&](int sum) {
            if (pq.size() < k) pq.push(sum);        
            else if(sum > pq.top()) {
                pq.pop();
                pq.push(sum);
            }
        };
    
        queue<TreeNode*> que;    
        que.push(root);    
        int level = 0;
    
        while(!que.empty()) {
            int sum = 0;        
            int levelSize = que.size();
            for(int i=0; i<levelSize; i++){
                TreeNode* node = que.front();
                que.pop();
                sum += node->val;
                
                if (node->left) que.push(node->left);
                if (node->right) que.push(node->right);
            }
        
            level++;
            levelSums[sum]++;
            updateQueue(sum);
        }
    
        if (levelSums.size() < k) return -1;
        
        return pq.top();
    }
};
