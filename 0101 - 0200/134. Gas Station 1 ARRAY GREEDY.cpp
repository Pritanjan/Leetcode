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
