// https://leetcode.com/problems/a-number-after-a-double-reversal/

class Solution {
public:
    bool isSameAfterReversals(int n) {
        if(n==0)
            return true;
        if(n%10==0)
            return false;
        else
            return true;
    }
};
