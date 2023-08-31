// A 1 -  Using Inorder and Two Pointers

// The main idea is to use a sorted array to save the values of the nodes in the BST .`
// We can use any tree traversal like inOrder, preorder, or postorder  to put the element 
// in the array in ascending order . `
// 1. We will use two pointers to point at start and end of the array.
// 2. Traverse while L < R .
// 3. if ` A[L] + A[R] == K ` return True .
// 4. if ` A[L] + A[R] > K `  do R-- (i.e. Remove the element from the right side) .
// 5. if ` A[L] + A[R] < K `  do L++ (i.e. Remove the element from the left side).
// 6. If the required pair is not found the return false.	

class Solution {
private:
    void inorder(TreeNode* root, vector<int>& A){
        if(root == NULL) return ;
        inorder(root -> left, A);
        A.push_back(root -> val);
        inorder(root -> right, A);
    }
public:
    bool findTarget(TreeNode* root, int K) {
        vector<int> A;
        inorder(root, A);
        int L = 0;
        int R = A.size() - 1;
        
        while(L < R) {
            if(A[L] + A[R] == K) return true;
            else if(A[L] + A[R] > K) R--;
            else L++;
        }
        return false;
    }
};

// Time Complexity : -**  ` O(N) `
// Space Complexity : -**  ` O(N) `





// A 2 -  Using HashSet
// This method also works for those who are not BSTs.
// 1. We will traverse the tree by any way, and record the node value in a Set.
// 2. The idea is to use a unordered_set to save the values of the nodes in the BST. 
// 3. Each time when we insert the value of a new node into the unordered_set, we check 
// if the unordered_set  contains k - node val.

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        unordered_set <int> us;
	return dfs(root,us,k);
    }
    
    bool dfs(TreeNode* root, unordered_set<int>& us, int k){
        if(root == NULL) return false;
        if(us.count(k - root -> val)) return true;
        us.insert(root -> val);
        return dfs(root -> left, us, k) || dfs(root -> right, us, k);
    }
};

// Time Complexity : -**  ` O(N) `
// Space Complexity : -**  ` O(N) `

// The idea is to use binary search method. 
// For each node, we check if k - node.val exists in this BST.

// Time Complexity: O(nh), Space Complexity: O(h).
// h is the height of the tree, which is log n at best case, 
// and n at worst case.


	
	
	

// A 3 - Using a Stack (Iterative Inorder Traversal)

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> stk1;   // leftS tack
        stack<TreeNode*> stk2;   // right Stack

        // Initialize left stack with nodes in increasing order (left subtree)
        TreeNode* curr = root;
        while(curr != nullptr) {
            stk1.push(curr);
            curr = curr -> left;
        }

        // Initialize right stack with nodes in decreasing order (right subtree)
        curr = root;
        while(curr != nullptr) {
            stk2.push(curr);
            curr = curr -> right;
        }

        while(!stk1.empty() && !stk2.empty() && stk1.top() != stk2.top()) {
            int sum = stk1.top() -> val + stk2.top() -> val;
            if(sum == k) return true;
            else if(sum < k) {
                curr = stk1.top() -> right;
                stk1.pop();
                while(curr != nullptr) {
                    stk1.push(curr);
                    curr = curr -> left;
                }
            } 
            else {
                curr = stk2.top() -> left;
                stk2.pop();
                while(curr != nullptr) {
                    stk2.push(curr);
                    curr = curr -> right;
                }
            }
        }
        return false;
    }
};






// A 4 -  Using a HashSet (Iterative Inorder Traversal)

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        stack<TreeNode*> stk;
        unordered_set<int> values;

        while(root != nullptr || !stk.empty()) {
            while(root != nullptr) {
                stk.push(root);
                values.insert(root -> val);
                root = root -> left;
            }
            root = stk.top();
            stk.pop();

            if(values.count(k - root -> val) > 0 && k - root -> val != root -> val) return true;
            root = root -> right;
        }
        return false;
    }
};






// A 5 
