// A 1 - Use ST sort

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        return nums[n-1] * nums[n-2] - nums[0] * nums[1];
    }
};

// T.C.  --> O(n log n)
// S.C.  --> O(log n)





// A 2 - 2 pass 
// find 2 min & 2 max

class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int ax1 = INT_MIN, mx2 = INT_MIN;
        int mi1 = INT_MAX, mi2 = INT_MAX;

        for(int num : nums) {
            if(num > mx1) {
                mx2 = mx1;
                mx1 = num;
            } 
            else if(num > mx2) {
                mx2 = num;
            }

            if(num < mi1) {
                mi2 = mi1;
                mi1 = num;
            } 
            else if(num < mi2) {
                mi2 = num;
            }
        }
        return (mx1 * mx2) - (mi1 * mi2);
    }
};

// T.C.  --> O(n)
// S.C.  --> O(1)





// A 3 

