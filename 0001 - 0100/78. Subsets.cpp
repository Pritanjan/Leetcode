// A1 -  Backtracking (Recursive):

// It uses recursive backtracking to generate all possible subsets. 
// At each step, we decide whether to include the current element in the subset or not.

class Solution {
private:
    void f(int idx, vector<int>& arr, vector<int>& ds, vector<vector<int>> &ans){
        ans.push_back(ds);
        for(int i=idx; i<arr.size(); i++){
            ds.push_back(arr[i]);
            f(i+1, arr, ds, ans);            
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> subsets(vector<int>& arr) {
        vector<int> ds;
        vector<vector<int>> ans;
        f(0, arr, ds, ans);
        return ans;
    }
};





// A2 -  Bit Manipulation (Iterative)

// It uses bit manipulation to represent whether an element is included in the subset or not. 
// Each bit position corresponds to an element in the array.

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res; 
        for(int j=0; j<(1 << n); ++j) {
            vector<int> subset;
            for(int i=0; i<n; ++i) {
                if(j & (1 << i)) {
                    subset.push_back(nums[i]);
                }
            }
            res.push_back(subset);
        }        
        return res;
    }
};

















// Subset Sums
// https://practice.geeksforgeeks.org/problems/subset-sums2234/1

class Solution {
public:
    void f(int idx, int sum, vector<int>& arr,  vector<int> &ans){
        if(idx == arr.size()){
            ans.push_back(sum);
            return ;
        }
        // pick element
        f(idx+1, sum + arr[idx], arr, ans);
        // Not pick element
        f(idx+1, sum, arr, ans);
    }
    
    vector<int> subsetSums(vector<int> arr, int N) {
        vector<int> ans;
        f(0, 0, arr, ans);        
        sort(ans.begin(), ans.end());
        return ans;
    }
};






