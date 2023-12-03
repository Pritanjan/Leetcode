// A 1

class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end());
        long long mx = 0; 
        int res = 0; 
        int i = 0;        
        while(mx < target) {
            if(i < coins.size() && coins[i] <= mx + 1) mx += coins[i++];
            else {                
                mx = 2*mx + 1;
                res++;
            }
        }
        return res;
    }
};






// A 2

class Solution {
public:
    int minimumAddedCoins(vector<int>& coins, int target) {
        sort(coins.begin(), coins.end()); 
        int curr = 1;
        int need = 0;
        for(int coin : coins) {
            while (coin > curr) { 
                need += 1;
                curr *= 2;
            }
            curr += coin; 
            if(curr > target) break;
        }
        while(curr <= target) { 
            need += 1;
            curr *= 2;
        }
        return need;
    }
};

