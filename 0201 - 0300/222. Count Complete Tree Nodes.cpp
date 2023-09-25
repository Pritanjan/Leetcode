// A 1 Naive

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};

// T.C. --> O(n), As it visit each node exactly once & time required to process node is constant
// S.C. --> O(h), As algorithm uses a recursive call stack to traverse the tree, 
// and the max depth of call stack is equal to the height of the tree.
// Worst case, where the binary tree is a skewed tree (i.e., all nodes are either L or R children), 
// the height of the tree can be O(n), and S.C. can be O(n). 
// Best case, where the binary tree is a balanced tree, height of the tree can be O(log n),
// and the S.C. will be O(log n).






// A 2

class Solution {
public: 
    void f(TreeNode* root,int &count){
        if(root==NULL) return;
        count++;
        f(root -> left,  count);
        f(root -> right, count);
    }
    int countNodes(TreeNode* root) {
        int count = 0;
        f(root, count);
        return count;
    }
}


// OR


class Solution {
public:
    int ans = 0;
    int countNodes(TreeNode* root) {
        if(!root) return ans;
        ans++;
        countNodes(root -> left);
        countNodes(root -> right);
        return ans;
    }
};






// A 3  

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root==NULL)return 0;
        int lh = leftheight(root);
        int rh=rightheight(root);

        if(lh==rh)return ((1<<lh)-1) ;  //(2^lh-1)

        return 1+countNodes(root->left)+countNodes(root->right);
    }
    int leftheight(TreeNode* root){
        int count=0;
        while(root){
            count++;
            root=root->left;
        }
        return count;
    }
    int rightheight(TreeNode* root){
        int count=0;
        while(root){
            count++;
            root=root->right;
        }
        return count;
    }
};


// OR


class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;
        
        int left_height = 0;
        int right_height = 0;
        TreeNode* left_node = root;
        TreeNode* right_node = root;
        
        while (left_node) {
            left_height++;
            left_node = left_node->left;
        }
        
        // SAME AS LINE 67 - 70
        // for(TreeNode* p=root; p; p=p->left) ++leftH;
        
        while (right_node) {
            right_height++;
            right_node = right_node->right;
        }        
        
        if (left_height == right_height) {
            return pow(2, left_height) - 1;
        }
        
        // SAME AS LINE 72 - 79
        // if(left_height == right_height) {
        //    return (1 << left_height) - 1;
        // }
        return countNodes(root->left) + countNodes(root->right) + 1;
    }
};

// It uses recursion, but it first determines the height of the left & right subtrees of the root node.
// If the height of both subtrees is equal, the binary tree is a complete binary tree, and  
// we can use a formula to calculate the number of nodes in the tree.
// else, recursively count the no of nodes in the left and right subtrees, & add 1 for the root node.

// T.C. -->  O(log^2(n)), where n is the number of nodes in the binary tree.
// S.C. --> O(log(n)), because the maximum depth of the recursion is the height of the binary tree.

// It assumes that the binary tree is a perfect binary tree, which means that all internal nodes
// have two children and all leaves are at the same level. 
// If the binary tree is not a perfect binary tree, this solution may still work, 
// but it will not be as efficient.






// A 4 - Use a stack-based iterative 

class Solution {
public:
    int countNodes(TreeNode* root) {
        if(root == NULL) return 0;
        stack<TreeNode*> stk;
        stk.push(root);
        int count = 0;
        
        while(!stk.empty()) {
            TreeNode* node = stk.top();  stk.pop();
            count++;
            if(node->left != NULL)   stk.push(node->left);
            if(node->right != NULL)  stk.push(node->right);
        }
        return count;
    }
};

// It uses stack to keep track of the nodes in the binary tree.
// Start by pushing the root node onto the stack, and then enter into a loop that pops nodes from
// the stack, increments the count, and pushes any non-null children onto the stack. 
// When the stack is empty, we have visited all nodes in the tree, and we return the count.

// T.C. --> O(n), because we visit each node once. 
// S.C. --> O(h), because stack may contain up to h nodes at a time in worst case (for skewed binary tree). 






// A 5 - Using inorder traversal

class Solution {
public:
    void inorder(TreeNode* root, vector<int>& in) {
        if(root == NULL) return;
        inorder(root->left, in);
        in.push_back(root -> val);
        inorder(root -> right, in);
    }
    int countNodes(TreeNode* root) {
        vector<int> in;
        inorder(root, in);
        return in.size();
    }
};






// A 6

class Solution {
public:
    int countNodes(TreeNode* root) {
        int count = 0;
        if(!root){return count;}
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            TreeNode *temp = q.front();
            q.pop();
            count++;
            if(temp->left)  q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        return count;
    }
};


// OR


class Solution {
public:
    int countNodes(TreeNode* root) {
        int count = 0;
        queue<TreeNode*>q;
        q.push(root);
        if(root == NULL)    return 0;
        while(q.empty()==false) {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                auto curr = q.front();
                q.pop();
                count++;
                
                if(curr->left != NULL)  q.push(curr->left);
                if(curr->right != NULL) q.push(curr->right);
            }
        }
        return count;
    }
};






// A 7

class Solution {
public: 
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int LH = 0;
        int RH = 0;
        
        TreeNode* L = root;
        TreeNode* R = root;
        while(L) {
            L = L -> left;
            LH++;
        }
        while(R) {
            R = R->right;
            RH++;
        }
        // If the height of the left subtree and the height of the right subtree are the same,
        // it means the left subtree is a perfect binary tree, so we can calculate its nodes directly.
        if(LH == RH) return (1 << LH) - 1; // 2^leftHeight - 1
        // If the heights are not the same, we recursively count nodes in the left and right subtrees.
        else return 1 + countNodes(root -> left) + countNodes(root -> right);
    }
};






// A 8


