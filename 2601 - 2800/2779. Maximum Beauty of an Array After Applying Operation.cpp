class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        map<int, int> ump;
        for(auto i : nums){
            ump[i-k]++;
            ump[i+k+1]--;
        }
        
        int p = 0;
        int res = 0;
        
        for(auto i : ump){
            p += i.second;
            res = max(res, p);
            
        }
        return res;
    }
};





class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0, j = 0; i < nums.size(); i++) {
            while (nums[j] + k < nums[i] - k) j++;
            res = max(res, i - j + 1);
        }
        return res;
    }
    
};


