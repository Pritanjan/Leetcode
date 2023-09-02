// A 1

// use a nested loop to check all pairs of elements for their sum. 
// Time complexity of O(n^2).

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector <int> diff;
        for(int i=0;i<nums.size()-1;i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j] == target ){
		     diff.push_back(i);
                     diff.push_back(j);
                     // diff.push_back(min(nums[i], nums[j]));
                     // diff.push_back(max(nums[i], nums[j]));  // to get element  
		     break;
	        }
		else continue;
            }
        }
        return diff;
    }
};


// OR


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0; i<n; ++i) {
            for(int j=i+1; j<n; ++j) {
                if(nums[i] + nums[j] == target) return {i, j};
            }
        }
        return {};
    }
};





// A 2

// Use a hash map to store each element's index as we traverse through the array. 
// For each element, we can check if the difference between the target and the current element exists in
// the hash map. 

// Time complexity O(n), 
// It requires additional space for the hash map.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {        
        unordered_map<int,int> mp;
        for(int i=0; i<nums.size(); i++){
            if(mp.find(target - nums[i]) != mp.end() )
                return {mp[target - nums[i]], i};
            mp[nums[i]] = i;
        }
        return {};
    }
};





// A 3  Sorting 2 Pointer

// It involves sorting the array and then using two pointers to move towards each other
// while looking for the sum. 

// Time complexity of O(n log n) due to sorting.


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int, int>> res;
        for(int i=0; i<nums.size(); ++i) {
            res.push_back({nums[i], i});
        }
        sort(res.begin(), res.end());

        int L = 0;
        int R = nums.size() - 1;
        while(L < R) {
            int sum = res[L].first + res[R].first;
            if(sum == target) return {res[L].second, res[R].second};
            else if(sum < target) L++;
            else R--;
        }
        return {};        
    }
};





// A 5 . Using a Set:
// WE can use a set to store the elements you've seen so far while iterating through the array. 
// Time complexity of O(n) and requires additional space for the set.

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_set<int> st;
        for(int i=0; i<nums.size(); ++i) {
            int comp = target - nums[i];
            if(st.count(comp)) {
                // We found a pair that adds up to the target
                // Return the indices of the two numbers
                int compIdx;
                for(int j=0; j<i; ++j) {
                    if(nums[j] == comp) {
                        compIdx = j;
                        break;
                    }
                }
                return {compIdx, i};
            }
            st.insert(nums[i]);
        }
        return {};
    }
};






// A 6 

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ump;
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];

            if(ump.find(complement) != ump.end()) {
                res.push_back(ump[complement]);
                res.push_back(i);
                return res;
            }
            ump[nums[i]] = i;
        }
        return res;
    }
};






// A 7

// Create two hash tables (unordered maps): one to store the elements seen so far and their corresponding
//     indices and another to store the complements needed to reach the target.
// Iterate through the array from left to right.
// For each element, calculate its complement (the value needed to reach the target).
// Check if the complement exists in the complement hash table. If found, return the indices of the
//    current element and its complement.
// If the complement is not found, insert the current element into the seen hash table.
// If no solution is found after iterating through the array, return an empty vector.

// T.C. --> O(N)
// S.C. --> O(N)

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> seen; // Store elements and their indices
        unordered_map<int, int> complements; // Store complements needed to reach the target
        vector<int> res;

        for(int i=0; i<nums.size(); ++i) {
            int num = nums[i];
            int complement = target - num;

            if(complements.find(num) != complements.end()) {
                // Found complement in complements hash table
                res.push_back(complements[num]);
                res.push_back(i);
                return res;
            }
            seen[num] = i; // Store the current element and its index
            complements[complement] = i; // Store the complement needed for future lookups
        }
        return res;
    }
};






// A 8 









// If there is more than 1 pair it is used

#include <bits/stdc++.h> 
vector<vector<int>> pairSum(vector<int> &arr, int s){
    vector<vector<int>> ans;
    for(int i=0; i<arr.size(); i++){
       for(int j=i+1; j<arr.size(); j++){
           if(arr[i] + arr[j] == s){
               vector<int> v;
               v.push_back(min(arr[i], arr[j]));
               v.push_back(max(arr[i], arr[j]));
               ans.push_back(v);
           }
       }
   }
    sort(ans.begin(), ans.end());
    return ans;
}





