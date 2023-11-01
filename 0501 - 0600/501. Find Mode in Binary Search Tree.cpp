// A 1 

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        vector<int> v;
        inOrder(root, v );
        
        vector<int> modes;
        int maxCount = 0, currentCount = 0;
        int currentMode = 0;
        
        // Finding the mode(s) in the sorted v array
        for(int i=0; i<v.size(); i++) {
            if(i == 0 || v[i] == v[i-1]) currentCount++;
            else currentCount = 1;
            
            
            if(currentCount > maxCount) {
                maxCount = currentCount;
                modes.clear();
                modes.push_back(v[i]);
            } 
            else if(currentCount == maxCount) modes.push_back(v[i]);
        }        
        return modes;
    }

    void inOrder(TreeNode* root, vector<int>& v) {
        if(root == NULL) return ;
        inOrder(root -> left, v);
        v.push_back(root -> val);
        inOrder(root -> right, v);
    }
};






// A 2 INORDER TRAVERSAL WITH HASH MAP
// S1 Perform inorder traversal to get array in sorted order
// S2 Now, traverse through array & keep the freq of each element in the array 
// S3 After trversal, find the maximum freq & collect all value witrh that freq in modes

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> freqMap;
        vector<int> v;    // to store inorder valus of a trees
        vector<int> modes;
        
        inOrder(root, v);        
        for(auto val : v) freqMap[val]++;
        
        int maxFreq = 0;
        for(auto& i : freqMap) maxFreq = max(maxFreq, i.second);
        for(auto& i : freqMap) {
            if(i.second == maxFreq) modes.push_back(i.first);
        }
        return modes;
    }

    void inOrder(TreeNode* root, vector<int>& V) {
        if(root == NULL) return;
        inOrder(root->left, V);
        V.push_back(root->val);
        inOrder(root->right, V);
    }
};


// OR


class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        // store element occurrences in in-order traversa
        unordered_map<int, int> occurrences;
        int maxCount = 0;

        // Perform the in-order traversal and update occurrences
        inOrderTraversal(root, occurrences, maxCount);

        // Collect all elements with the maximum occurrence count
        vector<int> modes;
        for(auto& entry : occurrences) {
            if(entry.second == maxCount) {
                modes.push_back(entry.first);
            }
        }
        return modes;
    }
private:
    void inOrderTraversal(TreeNode* node, unordered_map<int, int>& occurrences, int& maxCount) {
        if(node == nullptr) return ;

        inOrderTraversal(node -> left, occurrences, maxCount);
        occurrences[node -> val]++; // Update occurrences
        maxCount = max(maxCount, occurrences[node -> val]); // Update maxCount
        inOrderTraversal(node -> right, occurrences, maxCount);
    }
};






// A 3 

class Solution {
public:
    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> counter;
        vector<TreeNode*> stk;
        stk.push_back(root);

        while(!stk.empty()) {
            TreeNode* node = stk.back();
            stk.pop_back();

            counter[node->val]++;
            if(node -> left != nullptr) stk.push_back(node -> left);
            if(node -> right != nullptr) stk.push_back(node -> right);
        }        
        int maxFreq = 0;
        for(auto& [key, val] : counter) {
            maxFreq = max(maxFreq, val);
        }        
        vector<int> ans;
        for(auto& [key, val] : counter) {
            if(val == maxFreq) {
                ans.push_back(key);
            } 
        }
        return ans;
    }
};






// A 4 
