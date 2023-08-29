
class Solution {
public:
    int findPos(vector<int> &in, int ele, int n){
        for(int i=0; i<n; i++){
            if(in[i] == ele)
                return i;
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




