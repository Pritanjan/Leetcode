//https://leetcode.com/problems/sum-of-square-numbers/

class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c==0)
            return true;
        for(long long int i=0; i<sqrt(c); i++){
        	int diff(c - i*i);
        	if(int(sqrt(diff)) * int(sqrt(diff)) == diff )
        	return true;
		}
        return false;
    }
};

