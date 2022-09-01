// https://leetcode.com/problems/container-with-most-water/

class Solution {
public:
    int maxArea(vector<int>& height) {
        int L = 0;
        int R = height.size() - 1;
        int sum = 0;
        
        while(L < R){
            int h = min(height[L], height[R]);
            sum = max(sum, h*(R-L));
            
            while(height[L] <=h && L<R ){
                L++;
            }
            while(height[R] <=h && L<R){
                R--;
            }            
        }
        return sum;
    }
};
