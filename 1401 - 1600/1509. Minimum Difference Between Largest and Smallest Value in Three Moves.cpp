// A 1

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n <= 4)
            return 0;
        int ans = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int i=0; i<4; i++){
            ans = min(ans, nums[n-1-3+i] - nums[i]);
        }
        return ans;
    }
};




// 0 1 6 10 13 14 15
// Sort the array 
// change one element
//     L1 - S1  or L1 - S2  = 14 - 0 or 15 - 1
    
// change two element
// L2 - S1 or L2 - S2 or L1 - S3

// change 3 element
// 3L + 0S  OR 2L + 1S OR 1L + 2S OR 0L + 3S



// OR

class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if(n <= 4) return 0;
        int ans = INT_MAX;
        sort(nums.begin(), nums.end());
        for(int L=0, R=n-4; L<4; L++, R++){ 
            ans = min(ans, nums[R] - nums[L]);
        }
        return ans;
    }
};


