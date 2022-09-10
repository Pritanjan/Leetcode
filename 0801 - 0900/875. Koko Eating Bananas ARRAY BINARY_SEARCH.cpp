//https://leetcode.com/problems/koko-eating-bananas/

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int L = 1;
        int R = *max_element(piles.begin(), piles.end());
        
        while(L < R){
            int mid = (L+R)/2;
            int hrs = 0;
            
            for(int i : piles)
                hrs += i/mid + (i % mid != 0);
            
            if(hrs <= h)
                R = mid;
            else 
                L = mid + 1;
        }
        return R;
    }
};

// T.C. --> O(n log m)
//The initial search space is from 1 to m, it takes logm comparisons to reduce the search space to 1.
//For each eating speed middle, we traverse the array and calculate the overall time Koko spends, which takes O(n) for each traversal.
//To sum up, the time complexity is O(n·logm)

// S.C. --> O(1)   
//For each eating speed middlemiddle, we iterate over the array and calculate the total hours Koko spends, which costs constant space.
//Therefore, the overall space complexity is O(1).
