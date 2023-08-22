// A1 

class Solution {
public:
    int trap(vector<int>& h) {
        int L = 0, R = h.size()-1;
        int left_max = 0, right_max = 0;
        int water = 0;         
        while(L < R) {
            if(h[L] < h[R]) {
                if(h[L] >= left_max) left_max = h[L];
                else water += left_max - h[L];
                L++;
            }
            else {
                if(h[R] >= right_max) right_max = h[R];
                else water += right_max - h[R];
                R--;
            }
        }
        return water;
    }
};






