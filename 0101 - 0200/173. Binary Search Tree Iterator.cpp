// A 1
// https://www.youtube.com/watch?v=D2jMcmxU4bs

class BSTIterator {
public:    
    stack<TreeNode *> stack;
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    
    int next() {
        TreeNode *top = stack.top();
        stack.pop();
        pushAll(top -> right);
        return top -> val;
    }
    
    bool hasNext() {
        return !stack.empty();
    }
    
    void pushAll(TreeNode *node){
        for(; node != NULL; stack.push(node), node = node -> left);
    }
};

// T.C  = O(1)
// S.C. = O(H)






// A 2 -  Using In-Order Traversal and List
// WE WILL FIND INORDER OF THE TREE AND CHECK IF NEXT IS AVAILABLE OR NOT

// This approach uses the in-order traversal of the binary tree to generate a list of elements, 
// and then the iterator functions (next and hasNext) work with this list.

class BSTIterator {
public:
    vector <int> nums;
    int i = 0;
    void inorder(TreeNode *&root){
        if(!root) return;
        inorder(root -> left);
        nums.push_back(root -> val);
        inorder(root -> right);
    }
    
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    int next() {
        int a = nums[i];
        i++;
        return a;
    }
    
    bool hasNext() {
        if(i < nums.size()) return true;
        return false;
    }
};






// A 3

class BSTIterator {
public:
    queue<TreeNode*> nodes;
    void mid(TreeNode* root){
        if(root == NULL) return ;
        mid(root -> left);
        nodes.push(root);
        mid(root -> right);
    }

    BSTIterator(TreeNode* root) {
        mid(root);
    }
    
    int next() {
        int ans = nodes.front() -> val;
        nodes.pop();
        return ans;
    }
    
    bool hasNext() {
        return !nodes.empty();
    }
};






// A 4

class BSTIterator {
    deque<TreeNode*> d;
public:
    BSTIterator(TreeNode* root) {
        dfsLeft(root);
    }
    int next() {
        TreeNode* root = d.back();
        int ans = root->val;
        d.pop_back();
        root = root->right;
        dfsLeft(root);
        return ans;
    }

    bool hasNext() {
        return !d.empty();
    }

    void dfsLeft(TreeNode* root) {
        while (root != nullptr) {
            d.push_back(root);
            root = root->left;
        }
    }
};






// A 5 -  Using Two Stacks

// we use two stacks to simulate the in-order traversal of the binary tree. 
// One stack is used for traversing left nodes, and the other is used to keep track 
// of nodes with right children.

class BSTIterator {
private:
    stack<TreeNode*> leftStack;
    stack<TreeNode*> rightStack;
    
    void pushLeft(TreeNode* node) {
        while (node) {
            leftStack.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }
    
    int next() {
        TreeNode* node = leftStack.top();
        leftStack.pop();
        pushLeft(node->right);
        return node->val;
    }
    
    bool hasNext() {
        return !leftStack.empty();
    }
};






// A 6 - Morris Traversal

class BSTIterator {
private:
    TreeNode* curr;
    TreeNode* findPredecessor(TreeNode* node) {
        TreeNode* pred = node->left;
        while(pred -> right && pred -> right != node) pred = pred - >right;
        return pred;
    }

public:
    BSTIterator(TreeNode* root) {
        curr = root;
    }
    int next() {
        while(curr -> left) {
            TreeNode* pred = findPredecessor(current);
            if(!pred -> right) {
                pred -> right = curr;
                curr = curr -> left;
            } 
            else {
                pred -> right = nullptr;
                int val = curr -> val;
                curr = curr -> right;
                return val;
            }
        }
        int val = curr -> val;
        curr = curr -> right;
        return val;
    }
    
    bool hasNext() {
        return curr != nullptr;
    }
};






// A 7 
