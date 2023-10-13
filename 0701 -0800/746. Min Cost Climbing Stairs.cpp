// A 1 

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

