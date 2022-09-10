//https://leetcode.com/problems/sum-of-square-numbers/

class Solution {
public:
    bool judgeSquareSum(int c) {
        
        if(c<=2)
            return true;
        long long int L = 0, R = sqrt(c);
        
        while(L<=R){
            if(L*L + R*R == c)
                return true;
            else if(L*L + R*R < c)
                L++;
            else
                R--;
        }
        return false;
    }
};


// SOLUTIONS
// https://leetcode.com/problems/sum-of-square-numbers/discuss/1424993/Sum-of-Square-Numbers-oror-2-Approaches-oror-C%2B%2B-or-Python-or-JAVA


