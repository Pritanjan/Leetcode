//https://leetcode.com/problems/min-cost-climbing-stairs/

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


