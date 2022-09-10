//https://leetcode.com/problems/check-if-number-is-a-sum-of-powers-of-three/

class Solution {
public:
    bool checkPowersOfThree(int n) {
        while(n>0){
            if(n%3==2){
                return false;
            }
            n/=3;
        }
        
        return true;
    }
};

// The number can not be represented as a sum of powers of 3 if it's ternary presentation has a 2 in it
