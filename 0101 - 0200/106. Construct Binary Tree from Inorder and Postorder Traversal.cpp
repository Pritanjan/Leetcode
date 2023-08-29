// A 1

class Solution {
public:
    int findPos(vector<int> &in, int ele, int n){
        for(int i=0; i<n; i++){
            if(in[i] == ele) return i;
        }
        return -1;
    }
    
    TreeNode* f(vector<int>& inorder, vector<int>& postorder, int &idx, int start, int end, int n){
        if(start > end) return NULL;
        int ele = postorder[idx];
        TreeNode* root = new TreeNode(ele);
        int pos = findPos(inorder, ele, n);
        idx--;
        
        root -> right = f(inorder, postorder, idx, pos + 1, end, n);
        root -> left  = f(inorder, postorder, idx, start,   pos - 1, n);

        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int idx = n-1;
        TreeNode* res = f(inorder, postorder, idx, 0, n-1, n);
        return res;
    }
};


// OR


class Solution {
public:
    TreeNode* buildTreeHelper(vector<int>& inorder, int inStart, int inEnd,
                           vector<int>& postorder, int postStart, int postEnd) {
        if(inStart > inEnd || postStart > postEnd) return nullptr;
        int rootVal = postorder[postEnd];
        TreeNode* root = new TreeNode(rootVal);
        int idx;  // rootIdxInorder
        for(int i=inStart; i <= inEnd; ++i) {
            if(inorder[i] == rootVal) {
                idx = i;
                break;
            }
        }

        int n = idx - inStart;  // leftSubtreeSize
        root -> left =  buildTreeHelper(inorder, inStart, idx-1, 
                                    postorder, postStart, postStart + n-1);
        root -> right = buildTreeHelper(inorder, idx + 1, inEnd,
                                    postorder, postStart + n, postEnd - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        return buildTreeHelper(inorder, 0, n-1, postorder, 0, n-1);
    }
};





//  A 2 
