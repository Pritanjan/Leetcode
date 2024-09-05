// A 1 

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int totalRolls = rolls.size() + n;
        int totalSum = mean * totalRolls;        
        
        int currSum = 0;
        for(auto i : rolls) {
            currSum += i;
        }

        int remSum = totalSum - currSum;
        if(remSum < n or remSum > 6*n) {
            return {};
        }

        vector<int> res(n,1);
        remSum -= n;
        for (int i = 0; i < n && remSum > 0; ++i) {
            int add = min(5, remSum); 
            res[i] += add;
            remSum -= add;
        }
        return res;        
    }
};
