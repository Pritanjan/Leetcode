// kth max in binary tree
// https://github.com/Pritanjan/Leetcode/blob/main/2401%20-%202600/2583.%20Kth%20Largest%20Sum%20in%20a%20Binary%20Tree.cpp


// https://practice.geeksforgeeks.org/problems/4b7ff87c26ed23b3f63c25c611690213d44fb6aa/1

class Solution{
  public:
    int maxLevelSum(Node *root) {
        // Base case
        if (root == NULL) return 0;
    
        // Initialize result
        int result = root->data;
    
        // Do Level order traversal keeping track of number
        // of nodes at every level.
        queue<Node *> q;
        q.push(root);
        while (!q.empty()) {
            // Get the size of queue when the level order
            // traversal for one level finishes
            int count = q.size();
    
            // Iterate for all the nodes in the queue currently
            int sum = 0;
            while (count--) {
                // Dequeue an node from queue
                Node *temp = q.front();
                q.pop();
    
                // Add this node's value to current sum.
                sum = sum + temp->data;
    
                // Enqueue left and right children of
                // dequeued node
                if (temp->left != NULL) q.push(temp->left);
                if (temp->right != NULL) q.push(temp->right);
            }
    
            // Update the maximum node count value
            result = max(sum, result);
        }
    
        return result;
    }

};


// Time Complexity: O(N), Here every node of the tree is processed once, and
// hence the complexity due to the level order traversal is O(N) if there are
// total N nodes in the tree.

// Space Complexity: O(W), where W is the maximum width of the tree,
// In level order traversal, a queue is maintained whose maximum size at any moment
// can go up to the maximum width of the binary tree.





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
    void dfs(TreeNode* node, int level, vector<int>& level_sum) {
        if (node == NULL) return;
        if (level > level_sum.size()) level_sum.push_back(node->val);
        else level_sum[level - 1] += node->val;
        dfs(node->left, level + 1, level_sum);
        dfs(node->right, level + 1, level_sum);
    }

    int maxLevelSum(TreeNode* root) {
        vector<int> level_sum;
        dfs(root, 1, level_sum);
        int max_sum = level_sum[0];
        int max_level = 1;
        for(int i = 1; i < level_sum.size(); i++) {
            if(level_sum[i] > max_sum) {
                max_sum = level_sum[i];
                max_level = i + 1;
            }
        }
        return max_level;
    }
};



