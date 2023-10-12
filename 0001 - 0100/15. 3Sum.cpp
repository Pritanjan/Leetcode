// APPROACH 1 [ BRUTE FORCE ] TLE
// Use 3 nested loops to generate all possible combinations of triplets and then check if their sum is 0
// T.C. = O(n^3), 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for(int i=0; i<n-2; ++i) {
            if(i > 0 && nums[i] == nums[i-1]) continue;   // Skip duplicates
            
            for(int j=i+1; j<n-1; ++j) {
                if(j > i+1 && nums[j] == nums[j-1]) continue;  // Skip duplicates
            
                for(int k=j+1; k<n; ++k) {
                    if(k > j+1 && nums[k] == nums[k-1]) continue;   // Skip duplicates
                    if(nums[i] + nums[j] + nums[k] == 0) res.push_back({nums[i], nums[j], nums[k]});
                }
            }
        }
        return res;
    }        
};

// Space Complexity: O(1)






// APPROACH 2 [ 2 POINTER ]
// Use 2 pointers while iterating through the array after sorting it. 

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for(int i=0; i<n-2; ++i) {
            if(i > 0 && nums[i] == nums[i-1]) continue; // Skip duplicates
            int L = i + 1;
            int R = n - 1;
            int tgt = -nums[i];

            while(L < R) {
                int sum = nums[L] + nums[R];
                if(sum == tgt) {
                    res.push_back({nums[i], nums[L], nums[R]});
                    while(L < R && nums[L] == nums[L+1]) L++;
                    while(L < R && nums[R] == nums[R-1]) R--;
                    L++;
                    R--;
                } 
                else if(sum < tgt) L++;
                else R--;
            }
        }
        return res;
    }
};

// Time Complexity: O(N^2)
// Space Complexity: O(1)


// OR


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {        
        vector<vector<int>> res;
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size(); i++) {
            int sum  = 0 - nums[i];
            int L = i+1;
            int R = nums.size()-1;
            while(L < R){
                if(nums[L] + nums[R] == sum ){
                    vector <int> triplet = {nums[i], nums[L], nums[R]};
                    res.push_back(triplet);
                    
                    while(L < R && nums[L] == triplet[1]) L++;
                    while(L < R && nums[R] == triplet[2]) R--;
                }
                else if(nums[L] + nums[R] < sum) L++;
                else R--;
            }
            while (i+1 < nums.size() && nums[i+1] == nums[i]) 
            i++;            
        }
        return res;
    }
};






// APPROACH 3 USE HASH SET
// It involves using a hash set to keep track of seen elements while iterating through the array.
// T.C. =  of O(n^2).
    
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        unordered_set<int> seen;
        for(int i=0; i<n-2; ++i) {
            if(i > 0 && nums[i] == nums[i-1]) continue;  // Skip duplicates

            seen.clear();
            for(int j=i+1; j<n; ++j) {
                int complement = -nums[i] - nums[j];
                if(seen.count(complement)) {
                    res.push_back({nums[i], nums[j], complement});
                    while(j+1 < n && nums[j] == nums[j+1]) ++j;  // Skip duplicates
                }
                seen.insert(nums[j]);
            }
        }
        return res;
    }
};






// APPRAOCH 4 [ Using Sorting and Binary Search ]
// It involves sorting the array and then using binary search to find the third element that
// complements the sum of the first two elements to zero. 
// T.C. =  O(n^2 * log n).

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> res;
        for(int i=0; i<n-2; ++i) {
            if(i > 0 && nums[i] == nums[i-1]) continue;  // Skip duplicates
            for(int j=i+1; j<n-1; ++j) {
                if(j > i+1 && nums[j] == nums[j-1]) continue;  // Skip duplicates
                int target = -nums[i] - nums[j];
                if(binary_search(nums.begin() + j+1, nums.end(), target))
                    res.push_back({nums[i], nums[j], target});
            }
        }
        return res;
    }
};








