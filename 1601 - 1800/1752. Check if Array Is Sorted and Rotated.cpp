// A 1

class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        for(int i=1; i<n; i++){
            if(nums[i-1] > nums[i])
                cnt++;
        }
        if(nums[n-1] > nums[0])
            cnt++;
        
        return cnt <= 1;
    }
};


// OR


class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0; // Count of decreasing segments        
        for(int i=0; i<n; ++i) {
            if(nums[i] > nums[(i+1) % n]) {
                cnt++;
                if(cnt > 1) return false;
            }
        }
        return true;
    }
};






// A 2

class Solution {
public:
    bool check(vector<int>& nums) {   
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        for (int i = 0; i < n; ++i) {
            if (nums == sorted) {
                return true;
            }
            rotate(nums.begin(), nums.begin() + 1, nums.end());
        }

        return false;
    }
};






// A 3
