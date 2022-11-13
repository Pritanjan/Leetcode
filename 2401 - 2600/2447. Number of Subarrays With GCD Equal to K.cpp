class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
		int cnt = 0;
        for (int i = 0; i < nums.size(); i++){
            int currGcd = 0;
            for (int j = i; j < nums.size(); j++){
                currGcd = gcd(currGcd, nums[j]);
                if (currGcd == k) cnt++;
            }
        }
        return cnt;
    }
};

