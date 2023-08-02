// APPROACH 1 

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        if(nums.size() <= 1) return {nums};
        vector<vector<int>> ans;
        for(int i=0; i<nums.size(); i++){
            vector<int> v(nums.begin(), nums.end());
            v.erase(v.begin() + i);
            auto a = permute(v);
            
            for(int j=0; j<a.size(); j++){
                vector<int> v1 = a[j];
                v1.insert(v1.begin(), nums[i]);
                ans.push_back(v1);
            }
        }
        return ans;
    }
};






// APPROACH 2  BACKTRACKING

// Swap elements to generate permutations and then swapping them back.

class Solution {
public:
    vector<vector<int>> ans;
    void permute(int idx, vector<int>& nums){
        int n = nums.size();
        if(idx >= n){
            ans.push_back(nums);
            return ;
        }
        for(int i=idx; i<n; i++){
            swap(nums[idx], nums[i]);
            permute(idx+1, nums);
            swap(nums[idx], nums[i]); 
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        permute(0, nums);
        return ans;
    }
};




// Approach 3 STL

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        do{
            res.push_back(nums);
        }while(next_permutation(nums.begin(), nums.end()));

        return res;
    }
};







// Approach 4 More Efficient than backtracking (Heap's Algorithm)

class Solution {
public:
    void f(vector<int>& nums, int n, vector<vector<int>>& res) {
        if(n == 1) {
            res.push_back(nums);
            return ;
        }

        for(int i=0; i<n; ++i) {
            f(nums, n-1, res);
            if(n%2 == 0) swap(nums[i], nums[n-1]);
            else swap(nums[0], nums[n-1]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        f(nums, nums.size(), res);
        return res;
    }
};






// APPROOACH 5 Bitmaskng Approach
 // wrong

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        int totalPermutations = 1 << n;
        vector<vector<int>> result;

        for (int i = 0; i < totalPermutations; ++i) {
            vector<int> permutation;

            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    permutation.push_back(nums[j]);
                }
            }

            result.push_back(permutation);
        }

        return result;
    }
};






// APPROACH  6 uSING count array approach

class Solution {
public:        
    void f(vector<int>& nums, vector<int>& cnt, int level, vector<int>& per, vector<vector<int>>& res) {
        if(level == nums.size()) {
            res.push_back(per);
            return ;
        }

        for(int i=0; i<nums.size(); ++i) {
            if(cnt[i] == 0) continue;
            
            cnt[i]--;
            per[level] = nums[i];
            f(nums, cnt, level+1, per, res);
            cnt[i]++;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> cnt(nums.size(), 1); // Count array to track usage of elements
        vector<int> per(nums.size());
        f(nums, cnt, 0, per, res);
        return res;
    }
};


