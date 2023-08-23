// APPROACH 1 backtracking  take u forward

class Solution {
private:
    void f(int idx, vector<int>& arr, vector<int>& ds, vector<vector<int>> &ans){
        ans.push_back(ds);      // to print empty set
        for(int i=idx; i<arr.size(); i++){
            if(i != idx and arr[i] == arr[i-1])   // if duplicate element if found then ignore it 
                continue;
            ds.push_back(arr[i]);   // else push the element into the ds 
            f(i+1, arr, ds, ans);   // recursive call the function
            ds.pop_back();          // remove the first element form the top of the array
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        vector<vector<int>> ans;    // to store all the required pair 
        vector<int> ds;             // creating the pair
        
        sort(arr.begin(), arr.end());   // sorting the array as we can ignore the element the duplicate the pair
        f(0, arr, ds, ans);         
        
        return ans;
    }
};





// APPROACH 2

// take/not_take approach.

// If take nums[i],                     then go to index = i+1
// If not take nums[i],                 then go to index = upper_bound(nums[i])
                    
                    
class Solution {
private:
    void f(int idx, vector<int>& arr, vector<int>& ds, vector<vector<int>> &ans){
        if (idx == arr.size()){
            ans.push_back(ds);
            return;
        }
        
        ds.push_back(arr[idx]);   
        f(idx+1, arr, ds, ans);   
        ds.pop_back();          
        
        int nextIdx = upper_bound(arr.begin(), arr.end(), arr[idx]) - arr.begin();
        
        f(nextIdx, arr, ds, ans);
    }
    
public:
    vector<vector<int>> subsetsWithDup(vector<int>& arr) {
        vector<vector<int>> ans;    // to store all the required pair 
        vector<int> ds;             // creating the pair
        
        sort(arr.begin(), arr.end());   // sorting the array as we can ignore the element the duplicate the pair
        f(0, arr, ds, ans);         
        
        return ans;
    }
};






// A3 - Iterative Approach:

// An iterative approach can also be used to generate subsets. 
// We can think of it as a loop that iterates through the input array and updates the 
// existing subsets by adding the current element.

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort to handle duplicates
        vector<vector<int>> res = {{}};
        int idx, cnt;
        for(int i=0; i<nums.size(); ++i) {
            idx = (i>0 && nums[i] == nums[i-1]) ? cnt : 0;
            cnt = res.size();
            for(int j=idx; j<cnt; ++j) {
                vector<int> subset = res[j];
                subset.push_back(nums[i]);
                res.push_back(subset);
            }
        }        
        return res;
    }
};






// A4 - Bit Manipulation:

// It uses the binary representation of numbers to generate subsets. 
// Each bit represents whether an element is included or excluded in the subse

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // Sort to handle duplicates
        
        int n = nums.size();
        int subsetCount = pow(2, n);
        vector<vector<int>> result;
        
        for (int i = 0; i < subsetCount; ++i) {
            vector<int> subset;
            for (int j = 0; j < n; ++j) {
                if (i & (1 << j)) {
                    subset.push_back(nums[j]);
                }
            }
            result.push_back(subset);
        }
        
        return result;
    }
};





