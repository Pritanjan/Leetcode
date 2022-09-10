// https://leetcode.com/problems/power-of-three/

class Solution {
public:
    bool isPowerOfThree(int n) {
        for(int i=0; i<30; i++){
            if(n == pow(3,i))
                return true;
        }
        return false;
        
    }
};
