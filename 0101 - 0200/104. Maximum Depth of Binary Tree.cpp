// A 1 [ RECURSION -- Top To Bottom ]

class Solution {
public:
    int Mdepth = 0;
    int maxDepth(TreeNode* root, int depth = 1) {
        if(root == NULL) return 0;        
        if(!root->left && !root->right) {
            if(depth > Mdepth) Mdepth = depth;
            return Mdepth;
        }
        
        maxDepth(root->left, depth+1);
        maxDepth(root->right,depth+1);
        return Mdepth;
    }
};

// T.C. --> O(N)
// S.C. --> O(H)


// OR


class Solution {
public:
    int depth(TreeNode* node){
        // IF NODE IS NULL THEN DEPTH IS 0
        if(!node) return NULL;
        int LD = depth(node->left) ;    // RETURNS LENGTH OF LEFT NODE
        int RD = depth(node->right);    // RETURNS LENGTH OF RIGHT NODE
        return 1 + max(LD, RD);          // 1 IS ADDED FOR ROOT NODE 
    }    
    int maxDepth(TreeNode* root) {
        return depth(root);
    }
};


// OR


class Solution {
public:
   int maxDepth(TreeNode* root) {
       if(!root) return NULL;
       return 1 + max(maxDepth(root->left), maxDepth(root->right));
   }
};






// A 2 [ BFS ]
// It uses the concept of Level Order Traversal but we wont be adding null in the Queue.
// We will simply increase the counter when the level will increase and then remove all the nodes
// from the queue of the current Level.

class Solution {
public:
    int maxDepth(TreeNode* root) {
        int depth = 0;
        if(root == NULL) return 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()) {
            ++depth;            
            int size = q.size();
            // while(size--){
            for(int i=0; i<size; ++i){
                TreeNode* temp = q.front(); q.pop();
                if(temp -> left)  q.push(temp -> left);
                if(temp -> right) q.push(temp -> right);
            }
        }
        return depth;
    }
};






// A 3

class Solution {
public:
    int maxii = 1;
    int ans = 1;
    int solve(TreeNode* root){
        if(root == NULL) return 0;
        if(root->left){
            ans+=1 ;
            solve(root->left);
            maxii = max(ans, maxii);
            ans -= 1;
        }
        if(root->right){
            ans+=1;
            solve(root->right);
            maxii = max(ans, maxii);
            ans -= 1;
        }
        return 1;
    }
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        solve(root);
        return maxii;
    }
};






// A 4  [ DFS ]

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        stack<TreeNode*> stk1;   // store the node value
        stk1.push(root);         
        stack<int> stk2;         // store the depth 
        stk2.push(1);

        int maxDepth = 0;        
        while(!stk1.empty()) {
            TreeNode* node = stk1.top(); stk1.pop();
            int depth = stk2.top(); stk2.pop();
            
            maxDepth = max(maxDepth, depth);
            if(node -> right) {
                stk1.push(node -> right);
                stk2.push(depth + 1);
            }             
            if(node -> left) {
                stk1.push(node->left);
                stk2.push(depth + 1);
            }
        }
        return maxDepth;
    }
};






// A 5  - DFS with Stack

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        stack<pair<TreeNode*, int>> stk;
        stk.push(make_pair(root, 1));
        
        int maxDepth = 0;
        while(!stk.empty()) {
            TreeNode* node = stk.top().first;
            int depth = stk.top().second;
            stk.pop();
            if(node) {
                maxDepth = max(maxDepth, depth);
                stk.push(make_pair(node -> left,  depth + 1));
                stk.push(make_pair(node -> right, depth + 1));
            }
        }        
        return maxDepth;
    }
};


// OR


class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL) return 0;
        stack<pair<TreeNode*, int>> stk;
        stk.push({root, 1});

        int maxDepth = 0;
        while(!stk.empty()) {
            auto [node, depth] = stk.top(); stk.pop();            
            maxDepth = max(maxDepth, depth);
            if(node -> left)  stk.push({node -> left, depth + 1});
            if(node -> right) stk.push({node -> right, depth + 1});            
        }        
        return maxDepth;
    }
};






// A 6 - Morris Traversal

class Solution {
public:
	int maxDepth(TreeNode* root) {
		int currDepth = 0;
		int maxDepth = 0;

		while(root != nullptr) {
			if(root -> left == nullptr) {
				root = root -> right;
				++currDepth;
				maxDepth = max(maxDepth, currDepth);
			}
            else {
				TreeNode* pred = root -> left;
				int depth = 2;
				while(pred -> right != nullptr && pred -> right != root) {
					pred = pred -> right;
					++depth;
				}

				if(pred -> right == nullptr) {
					pred -> right = root;
					root = root -> left;
					++currDepth;
				} 
                else {
					pred -> right = nullptr;
					root = root -> right;
					currDepth -= depth;
					++currDepth;
					maxDepth = max(maxDepth, currDepth);
				}
			}
		}
		return maxDepth;
	}
};


