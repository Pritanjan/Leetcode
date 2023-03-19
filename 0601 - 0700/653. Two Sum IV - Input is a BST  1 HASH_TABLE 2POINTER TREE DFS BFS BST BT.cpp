// Company Tag Amazon

// APPROACH 1 Using Inorder and Two Pointers

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
        if(root == NULL)   
            return ;
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
        
        while(L < R){
            if(A[L] + A[R] == K)
                return true;
            else if(A[L] + A[R] > K)
                R--;
            // if(A[L] + A[R] < K)
            else
                L++;
            
        }
        return false;
    }
};

// Time Complexity : -**  ` O(N) `
// Space Complexity : -**  ` O(N) `




// APPROACH 2 Using HashSet
// This method also works for those who are not BSTs.

// Explanation : 

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
        if(root == NULL)
            return false;
        if(us.count(k - root->val))
            return true;
        us.insert(root->val);
        return dfs(root->left,us,k) || dfs(root->right,us,k);
    }
};

// Time Complexity : -**  ` O(N) `
// Space Complexity : -**  ` O(N) `




3. 
//The idea is to use binary search method. 
//For each node, we check if k - node.val exists in this BST.

//Time Complexity: O(nh), Space Complexity: O(h).
//h is the height of the tree, which is log n at best case, 
//and n at worst case.

	
	
	
	
	
	
