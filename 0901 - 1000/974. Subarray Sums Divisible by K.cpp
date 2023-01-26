// https://www.youtube.com/watch?v=u9m-hnlcydk

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        vector<int> cnt(k,0);
        int sum = 0;

        for(auto i : nums){
            sum += (i % k + k) % k;
            cnt[sum % k]++;
        }

        int res = cnt[0];
        for(auto c : cnt){
            res += (c * (c-1))/2;
        }
        return res;
    }
};



// +k is use becs if rem is -ve
//  outer %k is use becs if rem is +ve on adding k it will become double so to avoid it





