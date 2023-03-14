class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int totalSum = 0;
        sumNumbersHelper(root, 0, totalSum);
        return totalSum;
    }
    
    void sumNumbersHelper(TreeNode* node, int currentSum, int& totalSum) {
        if(node == NULL) return;
        
        currentSum = currentSum * 10 + node->val;
        
        if(node->left == NULL && node->right == NULL) {
            totalSum += currentSum;
            return;
        }
        
        sumNumbersHelper(node->left, currentSum, totalSum);
        sumNumbersHelper(node->right, currentSum, totalSum);
    }
};




class Solution {
public:
    int sumNumbers(TreeNode* root) {
        int totalSum = 0;
        
        if (root == NULL) return totalSum;
        
        stack<pair<TreeNode*, int>> stk;
        stk.push({root, root->val});
        
        while(!stk.empty()) {
            auto [node, currentSum] = stk.top();
            stk.pop();
            
            if(node->left == NULL && node->right == NULL) totalSum += currentSum;
            if(node->left != NULL) stk.push({node->left, currentSum * 10 + node->left->val});
            if(node->right != NULL) stk.push({node->right, currentSum * 10 + node->right->val});
        }
        return totalSum;
    }
};









class Solution {
public:
    int sumNumbers(TreeNode* root) {
        if(!root) return 0;

        int sum = 0;
        queue<pair<TreeNode*, int>> q;
        q.push({root, root -> val});

        while(!q.empty()) {
            int size = q.size();
            while(size--) {
                auto node = q.front();
                q.pop();

                if(!node.first -> left && !node.first -> right) sum += node.second;

                if(node.first -> left) q.push({node.first -> left, node.second * 10 + node.first -> left -> val});
                if(node.first -> right) q.push({node.first -> right, node.second * 10 + node.first -> right -> val});
            }
        } 

        return sum;
    }
};



class Solution {
public:
    int ans=0;
    void dfs(TreeNode* root,vector<int>&v){
        if(root->left==NULL and root->right==NULL){
            v.push_back(root->val);
            int sum=0;
            for(int i=0;i<v.size();i++){
                sum=10*sum+v[i];
            }
            ans+=sum;
            v.pop_back();
            return;
        }
        v.push_back(root->val);
        if(root->left)dfs(root->left,v);
        if(root->right)dfs(root->right,v);
        v.pop_back();
    }

    int sumNumbers(TreeNode* root) {
        vector<int>v;
        dfs(root,v);
        return ans;
    }
};



class Solution {
public:
    void func(TreeNode *root,string &temp,vector<string> &ans)
    {
        if(!root->left && !root->right)
        {
            temp+=to_string(root->val);
            ans.push_back(temp);
            temp.pop_back();
            return;
        }
        temp+=to_string(root->val);
        if(root->left)
            func(root->left,temp,ans);
        if(root->right)
            func(root->right,temp,ans);
        temp.pop_back();
    }
    int sumNumbers(TreeNode* root) {
        if(!root)
            return 0;
        vector<string> ans;
        string temp="";
        func(root,temp,ans);
        int finalSum=0;
        for(auto it:ans)
        {
            finalSum+=stoi(it);
        }
        return finalSum;
    }
};


class Solution {
public:
    void solve(TreeNode * root , vector<string>&ans , string temp)
    {
        if(root == NULL)
        return;
        temp = temp + to_string(root->val);
        if(root->left == NULL and root->right == NULL)
        {
            ans.push_back(temp);
        }
        solve(root->left , ans , temp);
        solve(root->right , ans , temp);

    }
    int sumNumbers(TreeNode* root) 
    {
        vector<string>ans;
        string temp = "";
        solve(root , ans , temp );
        long long int res = 0;
        for(int i = 0 ;i<ans.size();i++)
        {
            cout<<ans[i]<<"  ";
            res = res  + stoi(ans[i]);
        }

        return res;
        
        
    }
};


class Solution {
public:
    vector<string> v;
    int sumNumbers(TreeNode* root) {
        string s = "";
        int sum = 0;
        collect(root, s);
        for(int i=0;i<v.size();i++) {
            sum += stoi(v[i]);
        }
        return sum;
    }
    void collect(TreeNode* root, string s) {
        s += to_string(root->val);
        if(root->right != NULL && root->left != NULL) {
            collect(root->right, s);
            collect(root->left, s);
        }
        else if(root->right != NULL) {
            collect(root->right, s);
        }
        else if(root->left != NULL) {
            collect(root->left, s);
        }
        else {
            v.push_back(s);
            return;
        }
    }
};


class Solution {
public:
    vector<string> nums;
    void recurAdd(string init, TreeNode* root){
        if(root==nullptr){
            return;
        }
        string num = init + to_string(root->val);
        if(root->left == nullptr && root->right == nullptr){
            nums.push_back(num);
        }else if(root->left == nullptr){
            recurAdd(num,root->right);
        }else if(root->right == nullptr){
            recurAdd(num,root->left);
        }else{
            recurAdd(num, root->left);
            recurAdd(num,root->right);
        }
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;
        recurAdd("",root);
        for(auto i: nums){
            sum+=stoi(i);
        }
        return sum;
    }
};

