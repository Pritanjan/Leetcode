// A 1  - Using is_sorted function

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        return is_sorted(nums.begin(), nums.end() ) || is_sorted(nums.rbegin(), nums.rend());
    }
};


// OR
// Using adjacent_find

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        return adjacent_find(nums.begin(), nums.end(), greater<int>()) == nums.end() || adjacent_find(nums.begin(), nums.end(), less<int>()) == nums.end();
    }
};






// A 2 [ Comparing with Previous Element]

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {    	
        bool decrease = true;
        bool increase = true;
        for(int i=0; i<nums.size()-1; i++){
            if(nums[i] > nums[i+1]) increase = false;
            if(nums[i] < nums[i+1]) decrease = false;
            // if(increase == false && decrease == false) return false;
        }
        return increase or decrease;
    }
};


// OR
// Here, we are using a single loop with a direction variable

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int dir = 0;
        // 0 --> not determined
        // 1 --> increasing
        // -1 --> decreasing

        for(int i=1; i<nums.size(); i++) {
            if(nums[i] > nums[i-1]) {
                if(dir == -1) return 0;
                dir = 1;
            }
            else if(nums[i] < nums[i-1]) {
                if(dir == 1) return 0;
                dir = -1;
            }
        }
        return 1;
    }
};






// A 3 Use Set
// use a set to track the signs of differences between consecutive elements. 
// If the size of the set is less than or equal to 2, then the array is monotonic.

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        set<int> st;
        for(int i=1; i<nums.size(); ++i) {
            int diff = nums[i] - nums[i - 1];
            if(diff != 0) st.insert(diff > 0 ? 1 : -1);
        }
        return st.size() <= 1;
    }
};






// A 4 
// Sorting the array and comparing it with the original array

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        vector<int> res = nums;
        sort(nums.begin(), nums.end());
        return nums == res or vector<int> (res.rbegin(), res.rend()) == nums;
    }
};






// A 5 


