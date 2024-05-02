// A 1 

class Solution {
public:
    int findMaxK(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), greater<int>());
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if(nums[i] == -nums[j]) return nums[i];
            }
        }
        return -1;
    }
};





// A 2 

