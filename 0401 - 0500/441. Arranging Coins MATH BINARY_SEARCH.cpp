// https://leetcode.com/problems/arranging-coins/

// Intuitive Way

class Solution {
public:
    int arrangeCoins(int n) {
        
        int count = 0;
        int i = 1;
        
        while(n){
            n -= i++;
            
            if(n>=0)
                count++;
            else
                break;
            
        }
        return count;
        
    }
};
