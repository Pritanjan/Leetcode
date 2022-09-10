// https://leetcode.com/problems/power-of-four/

class Solution {
public:
    bool isPowerOfFour(int n) {
        for(int i=0; i<30; i++ ){
            if(n == pow(4,i))
                return true;
        }
        return false;
    }
};
