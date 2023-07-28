// APPROACH 1 [ ITERATIVELY ]

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* temp = root;
        while(1){
            if((temp->val > p->val) && (temp->val > q->val)) temp = temp->left;
            else if((temp->val < p->val) && (temp->val < q->val)) temp = temp->right;
            else break;
        }
        return temp;
    }
};

// T.C. --> O(H)
// T.C. --> O(H)


// OR


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        while((root->val - p->val) * (root->val - q->val) > 0) {
            root = p->val < root->val ? root->left : root->right;
        }
        return root;
    }
};




// APPROACH 2 [ RECURSIVE ]

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if((root->val > p -> val) && (root->val > q -> val)) return lowestCommonAncestor(root->left,p,q);
        if((root->val < p -> val) && (root->val < q -> val)) return lowestCommonAncestor(root->right,p,q);
        return root;
    }
};


// OR 


class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root || root == p || root == q) return root;
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(!left)  return right;
        if(!right) return left;
        return root;
    }
};

// T.C. --> O(H)
// T.C. --> O(H)





// APPROACH 3 [ fnding the path from the root to the given node ]

// The getPath function takes in the root of the tree and a target node, and returns a vector of nodes
// that represents the path from the root to the target node.
// We start with the root node and traverse down the tree, adding each node to the path vector 
// until we reach the target node. 
// We check if the target node is less than or greater than the current node and
// move left or rightaccordingly.

// Here, the lowestCommonAncestor function takes in the root of the tree and two target nodes p and q. 
// We uses getPath function to find the path from the root to p and q, and then iterate over both paths
// simultaneously to find the last common node. We start from the root and compare each node 
// of the paths until we find the last common node. Once we find the last common node, 
// we return it as the lowest common ancestor.


class Solution {
public:
    vector<TreeNode*> getPath(TreeNode* root, TreeNode* target) {
        vector<TreeNode*> path;
        TreeNode* temp = root;

        while(temp != target) {
            path.push_back(temp);
            if(target -> val < temp -> val) temp = temp -> left;
            else temp = temp -> right;
        }        
        path.push_back(temp);
        return path;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> path_p = getPath(root, p);
        vector<TreeNode*> path_q = getPath(root, q);
        TreeNode* ancestor;

        for(int i=0; i<path_p.size() && i<path_q.size(); ++i) {
            if(path_p[i] == path_q[i]) ancestor = path_p[i];
            else break;
        }
        return ancestor;
    }
};

// T.C. --> O(H),  where H is the height of the tree,
// we are traversing tree twice to find the paths from the root to the target nodes,
// and then iterate over the paths until we find the lowest common ancestor

// S.C. --> O(H)
// since we need to store the paths in separate vectors.

