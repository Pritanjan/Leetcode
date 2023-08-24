// A1 - Brute Force - TLE

class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        vector<long long> res;
        for(int num1 : nums1) {
            for(int num2 : nums2) {
                res.push_back(static_cast<long long>(num1) * num2);
            }
        }

        sort(res.begin(), res.end());
        return res[k-1];
    }
};





// A2

