// https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/

//the count of odd numbers between 1 and low - 1 is low / 2
//the count of odd numbers between 1 and high is (high + 1 ) / 2
//
//
//Complexity
//Time O(1)
//Space O(1)

class Solution {
public:
    int countOdds(int L, int R) {
        return (R+1)/2 - L/2;
    }
};




class Solution {
public:
    int countOdds(int L, int R) {
        int ans = (R-L)/2;
        if(L%2!=0 || R%2!=0)
            ans++;
        
        return ans;
        
    }
};
