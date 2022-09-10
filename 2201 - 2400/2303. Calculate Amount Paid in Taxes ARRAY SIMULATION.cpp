//https://leetcode.com/problems/calculate-amount-paid-in-taxes/

class Solution {
public:
    double calculateTax(vector<vector<int>>& b, int income) {
        double ans = 0;
        int u0 = 0;
        
        for(auto a : b){
            int upper = a[0];
            int amt = min((upper - u0), income);
            ans += amt * (a[1]/100.0);
            u0 = upper;
            income -= amt;
        }
        return ans;
    }
};

// APPROACH 2

class Solution {
public:
    double calculateTax(vector<vector<int>>& b, int income) {
        double ans = 0;
        int u0 = 0;
        
        for(int i=0; i<b.size(); i++){
            int upper = b[i][0];
            int amt = min((upper - u0), income);
            ans += amt * (b[i][1]/100.0);
            u0 = upper;
            income -= amt;
        }
        return ans;
    }
};
