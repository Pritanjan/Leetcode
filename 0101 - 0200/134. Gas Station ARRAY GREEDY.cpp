//https://leetcode.com/problems/gas-station/

//Basic Idea :- The difference of gas[i] - cost[i] should always be >= 0, else we can't move to the next index.

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int idx = 0;
        int tc  = 0;
        int cc  = 0;
        
        for(int i=0; i<gas.size(); i++){
            // gas[i] - cost[i] >= 0  ALWAYS
            tc += (gas[i] - cost[i]);
            cc += (gas[i] - cost[i]);
            
            // if cc < 0  --> reset cc & incease idx by 1
            if(cc < 0){
                cc  = 0;
                idx = i+1;
            }
        }
        
        // tc should be >= 0
        if(tc >= 0)
            return idx;
        else
            return -1;
    }
};

// ans = ans + gas[i] - cost[i]

// T.C. --> O(n)
