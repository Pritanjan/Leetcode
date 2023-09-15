// A1 -  Backtracking (Recursive):
// It uses recursive backtracking to generate all possible subsets. 
// At each step, we decide whether to include the current element in the subset or not.

// 1. Define a function f, inside f, we add ds to the ans vector to store the current subset.
// 2. We iterate through the nums array starting from the current index idx. 
//    For each element, we include it in the ds, recursively call backtrack with the next index, 
//    and then remove the element to backtrack.
// 3. In the subsets function, we initialize the ans vector and call backtrack to generate all subsets.

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

// 1. Calculate the total no of subsets for an array of size n using bitwise left shift (1 << n).
// 2. Iterate from 0 to (1 << n ) - 1, representing each possible subset using inary number from 0 to 
//    2^n - 1.
// 3. Inside the loop, we check each bit in the binary representation of i using bitwise AND
//    (i & (1 << j)) and add the corresponding element from nums to the current subset 
//    if the bit is set (1).
// 4. We add each generated subset to the result vector.

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
        vector<vector<int>> res = {{ }};        
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

// 1. Sort input array nums to ensure that we get unique subsets & that they are in lexicographic order.
// 2. Iterate from 0 to (1 << n) - 1, where n is the no of elements in nums. 
//    This represents all possible combinations of elements using their binary representation.
// 3. Inside the loop, we check each bit of the binary representation of the current index i. 
//    If a bit is set (1), we add the corresponding element from nums to the current subset.
// 4. We add each generated subset to the result vector.
// It gives subsets that are lexicographically sorted

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






// A 6 
// Start from empty subset in output list.
// At each step one takes new integer into consideration and generates
// new subsets from the existing ones.
    
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        res.push_back(vector<int>());

        for(int num : nums) {
            vector<vector<int>> subsets;
            for(vector<int> curr : res) {
                curr.push_back(num);
                subsets.push_back(curr);
            }
            for(vector<int> curr : subsets) {
                res.push_back(curr);
            }
        }
        return res;
    }
};

// T.C. --> O(N * 2^N)
// S.C. --> O(N * 2^N)






// A 7

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int n = nums.size();

        for(int i=pow(2, n); i<pow(2, n+1); ++i) {
            // Generate bitmask, from 0..00 to 1..11
            string bitmask = bitset<32>(i).to_string().substr(32-n);

            // Append subset corresponding to that bitmask
            vector<int> curr;
            for(int j=0; j<n; ++j) {
                if(bitmask[j] == '1') curr.push_back(nums[j]);
            }
            res.push_back(curr);
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






