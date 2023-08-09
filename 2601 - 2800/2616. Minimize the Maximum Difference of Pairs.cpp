// APPROACH 1 [ SORTING & BINARY SEARCH ]

class Solution {
public:
    // min max -> think of binary search
    int minimizeMax(vector<int>& nums, int p) {
        // sort array
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int L = 0;
        // the possible difference ranges from 0 to the largest value - the smallest value
        int R = nums.back() - nums.front();
        
        // binary search the min max diff
        while(L < R) {
            int mid = L + (R - L) / 2;
            int cnt = 0;
            for(int i=1; i<n; i++) {
                // if it satisfy the condition, we can make a pair
                if(nums[i] - nums[i-1] <= mid) {
                    // increase the count of pairs
                    cnt += 1;
                    // increase i by 1
                    // since it is included in the pair already
                    i++;
                }
            }

            // if pairs is not enough, move L pointer excluding mid
            if(cnt < p) L = mid + 1;
            // too many pairs, move R to mid
            else R = mid;
        }
        return L;
    }
};





// APPROACH 2 


