// https://leetcode.com/problems/maximum-of-absolute-value-expression/

class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int ans = 0;
        // int J = {1,-1};
        int small, current;
        
        for(int j : {1,-1} ){
            for(int k : {1,-1} ){
                small = j * arr1[0] + k * arr2[0];
                for(int i=1; i<arr1.size(); i++){
                    current = j * arr1[i] + k * arr2[i] + i;
                    ans = max(ans, current - small);
                    small = min(small, current);
                }
            }
        }
        return ans;
    }
};
