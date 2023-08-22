// A1 

class Solution {
public:
    int trap(vector<int>& h) {
        int L = 0;
        int R = h.size()-1;
        int ans = 0;
        int left_max = 0;
        int right_max = 0;
        
        while(L < R) {
            if(h[L] < h[R]) {
                if(h[L] >= left_max) left_max = h[L];
                else ans += left_max - h[L];
                L++;
            }
            else {
                if(h[R] >= right_max) right_max = h[R];
                else ans += right_max - h[R];
                R--;
            }
        }
        return ans;
    }
};




