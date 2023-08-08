// APPROACH 1 

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        return is_sorted(nums.begin(), nums.end() ) || is_sorted(nums.rbegin(), nums.rend());
    }
};




// APPROACH 2 [ Comparing with Previous Element]

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






// APPROACH 3 Use Set
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




