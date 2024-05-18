// A 1 

class Solution {
public:
    int distributeCoins(TreeNode* root) {
        moves = 0;
        dfs(root);
        return moves;
    }

private:
    int moves;
    int dfs(TreeNode* curr) {
        if (curr == nullptr) return 0;

        // Calculate the coins each subtree has available to exchange
        int L = dfs(curr -> left);
        int R = dfs(curr -> right);

        // Add the total number of exchanges to moves
        moves += abs(L) + abs(R);

        // The number of coins current has available to exchange
        return (curr->val - 1) + L + R;
    }
};




