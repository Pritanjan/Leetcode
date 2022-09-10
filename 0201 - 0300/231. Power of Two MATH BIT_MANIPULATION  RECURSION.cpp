// https://leetcode.com/problems/power-of-two/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n == 1073741824)
            return true;
        int  q = 1;
        for(int i=0; i<30; i++){
            // if(n == pow(2,i))
            if(n == q)
                return true;
                
            q = 2 * q;
        }
        return false;
    }
};
