// A 0

// Brute Force (Recursive) - TLE
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        return min(minCost(cost, 0), minCost(cost, 1));
    }

    int minCost(vector<int>& cost, int i) {
        if(i >= cost.size()) return 0;
        return cost[i] + min(minCost(cost, i+1), minCost(cost, i+2));
    }
};



// Brute Force Memoization (Top-Down DP)
class Solution {
public:
    vector<int> v;
    int minCostClimbingStairs(vector<int>& cost) {
        v.resize(cost.size(), -1);
        return min(minCost(cost, 0), minCost(cost, 1));
    }

    int minCost(vector<int>& cost, int i) {
        if(i >= cost.size()) return 0;
        if(v[i] != -1) return v[i];
        v[i] = cost[i] + min(minCost(cost, i+1), minCost(cost, i+2));
        return v[i];
    }
};






// A 1 - DP  -  (Bottom-Up)
// in-place 

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        for(int i=0; i<n-2; i++){
            // it can take either 1 step or 2 step
            cost[i+2] += min(cost[i+1], cost[i]);
        }
        return min(cost[n-1], cost[n-2]);
    }
};


// OR

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n, 0);
        
        for(int i=2; i<n; i++) {
            dp[i] = min(dp[i-1] + cost[i-1], dp[i-2] + cost[i-2]);
        }        
        return min(dp[n-1] + cost[n-1], dp[n-2] + cost[n-2]);
    }
};







// A 2

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n <= 1) return 0;
        int zero = cost[0];
        int one = cost[1];

        for(int i=2; i<n; i++) {
            int tmp = cost[i] + min(zero, one);
            zero = one;
            one = tmp;
        }
        return min(zero, one);
    }
};






// A 3

