//Sure... I did it with a two pointer approach, my intuition is that I took two pointers named start and end initially kept start at the last index i.e. n-1 and kept end at first index i.e. 0.
//I made a variable cap which will calculate the capacity of tank at every end point. If at any end point cap goes negative it means that travelling further is not possible from that start point, so we shift the start pointer to left and include this new start value too in cap. If at any point start becomes equal to end, it means we have complete one cycle. So we will check the value of cap, if it is positive or zero it means from that start point cycle can be completed so we will return the value of start. Else we will return -1.

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int L = 0;
        int R = gas.size() - 1; 
        int capacity = gas[R] - cost[R];
        
        while(L < R){
            if(capacity > 0){
                capacity += gas[L] - cost[L];
                L++;
            }
            else{
                R--;
                capacity += gas[R] - cost[R];
                
            }
        }
        
        if(capacity >= 0)
            return R;
        else
            return -1;
    }
};





//Basic Idea :- The difference of gas[i] - cost[i] should always be >= 0, 
// else we can't move to the next index.

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





