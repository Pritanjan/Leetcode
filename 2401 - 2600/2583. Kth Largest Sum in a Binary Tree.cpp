// A 1 RECURSIVE SOLUTION

class Solution {
public:
    void traverse(TreeNode* root, int level, unordered_map<long long, long long>& levelSums) {
        if(!root) return;
    
        levelSums[level] += root->val;
        traverse(root->left, level + 1, levelSums);
        traverse(root->right, level + 1, levelSums);
    }

    long long kthLargestLevelSum(TreeNode* root, int k) {
        unordered_map<long long, long long> levelSums;    
        traverse(root, 0, levelSums);
        
        vector<long long> sums;
        for(auto& i : levelSums) sums.push_back(i.second);
        
        sort(sums.rbegin(), sums.rend());
        if(sums.size() < k)  return -1;
        return sums[k - 1];
    }
};






// A 2  - ITERTIVE SOLUTION

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        unordered_map<int, int> levelSums;
    
        auto updateQueue = [&](int sum) {
            if(pq.size() < k) pq.push(sum);        
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






// A 3

class Solution {
public:
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long> pq;
        queue<TreeNode*> que;
        que.push(root);
        while (!que.empty()) {
            long size = que.size();
            long sum = 0;
            for (int i = 0; i < size; i++) {
                TreeNode* pop = que.front();
                que.pop();
                sum += pop->val;
                if (pop->left != NULL) que.push(pop->left);
                if (pop->right != NULL) que.push(pop->right);
            }
            pq.push(sum);
        }
        if (pq.size() < k) return -1;
        for (int i = 0; i < k - 1; i++) pq.pop();
        return pq.top();
    }
};
