// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/solutions/1929126/o-n-time-complexity-cpp-solution-find-all-numbers-disappeared-in-an-array/

// APPROACH 1 [ TLE ]


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> v;
        int n = nums.size();
        for(int i=0; i<n; i++){
            if(find(nums.begin(), nums.end(), i+1) == nums.end()) v.push_back(i+1);
        }
        return v;
    }
};


// T.C. --> O(n^2), where n is the size of the input vector nums. 
// Because for each element in nums, we perform a linear search in the vector using find() 
// function which has a time complexity of O(n).
// Therefore, the total time complexity is O(n * n) = O(n^2).

// S.C. --> O(n), since we create a new vector v to store the missing numbers. 
// The size of this vector can be at most n, if all the no. from 1 to n are missing in nums.
// Therefore, the space complexity is O(n).
    
    


// APPROACH 2    


class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        for(int i=0; i<n; i++){
            int p = abs(nums[i]) - 1;
            if(nums[p] > 0) nums[p] =- nums[p];
        }
        
        for(int i=0; i<n; i++){
            if(nums[i] > 0) ans.push_back(i+1);
        }
        return ans;
    }
};



// T.C. --> O(n) 
// S.C. --> O(1), 
// Here, we are modifying the input vector nums in place & using a separate output 
// vector ans to store the missing numbers.




// APPROACH 3

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        int n = nums.size();
        
        for(int i=0;i<n; i++){
            while(nums[nums[i] - 1] != nums[i] ){
                swap(nums[i], nums[nums[i]-1]);
            }
        }
        
        for(int i=0; i<n; i++){
            if(nums[i] != i+1) ans.push_back(i+1);
        }        
        return ans;
    }
};





