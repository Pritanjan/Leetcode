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





// A3 - Iterative 

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res = {{}};
        
        for(int num : nums) {
            int n = res.size();
            for(int i=0; i<n; ++i) {
                vector<int> subset = res[i];
                subset.push_back(num);
                res.push_back(subset);
            }
        }        
        return res;
    }
};


// OR


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();        
        for(int i=0; i<(1 << n); ++i) {
            vector<int> subset;
            for(int j=0; j<n; ++j) {
                if(i & (1 << j)) {
                    subset.push_back(nums[j]);
                }
            }
            res.push_back(subset);
        }        
        return res;
    }
};






// A4 - Lexicographic (Binary Sorted) Subsets:

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        int n = nums.size();        
        for(int i=0; i<(1 << n); ++i) {
            vector<int> subset;
            for(int j=0; j<n; ++j) {
                if(i & (1 << j)) {
                    subset.push_back(nums[j]);
                }
            }
            res.push_back(subset);
        }        
        return res;
    }
};






// A5

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        if(nums.empty()) return {{}};        

        int last = nums.back();
        nums.pop_back();
        vector<vector<int>> v1 = subsets(nums);   // subsetsWithoutLast
        vector<vector<int>> v2 = v1;              // subsetsWithLast
        
        for(auto& subset : v2) {
            subset.push_back(last);
        }        
        v1.insert(v1.end(), v2.begin(), v2.end());
        return v1;
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






