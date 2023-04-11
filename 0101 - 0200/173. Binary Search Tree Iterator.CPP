// APPROACH 1
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




// APPROACH 2 
// WE WILL FIND INORDER OF THE TREE AND CHECK IF NEXT IS AVAILABLE OR NOT

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







// APPROACH 3


class BSTIterator {
public:
    queue<TreeNode*> nodes;

    void mid(TreeNode* root){
        if(root == NULL)return;

        mid(root->left);
        nodes.push(root);
        mid(root->right);
    }

    BSTIterator(TreeNode* root) {
        mid(root);
    }
    
    int next() {
        int ans = nodes.front()->val;
        nodes.pop();
        return ans;
    }
    
    bool hasNext() {
        return !nodes.empty();
    }
};





// APPROACH 4

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





