// https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& A, int k) {
        unordered_map<int, int> ump;
        int sum = 0;
        int ans = 0;
        ump[sum] = 1;
        
        for(int i=0; i<A.size(); i++){
            sum += A[i];
            if (ump.find(sum - k) != ump.end()) {
                ans += ump[sum - k];
            }
            ump[sum]++;
        }
        return ans; 
    }
};


