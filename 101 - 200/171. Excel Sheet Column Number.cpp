//https://leetcode.com/problems/excel-sheet-column-number/

class Solution {
public:
    int titleToNumber(string s) {
        
        int ans=0;
        
        for(auto x: s){
            int q = x-'A'+1;
            ans=ans*26 + q;
        }
        return ans;
        
    }
};
