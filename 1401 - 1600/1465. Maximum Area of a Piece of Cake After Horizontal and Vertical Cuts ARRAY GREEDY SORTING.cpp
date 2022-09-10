//https://leetcode.com/problems/maximum-area-of-a-piece-of-cake-after-horizontal-and-vertical-cuts/

1. just sort the verticalCuts & horizontalCuts 
2. find the maximum difference of a consecutive element 
3. Return their products.

class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        horizontalCuts.push_back(h);
        verticalCuts.push_back(w);
        
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        
        int m1 = horizontalCuts[0];
        int m2 = verticalCuts[0];
        
        for(int i=0; i<horizontalCuts.size() - 1; i++){
            m1 = max(m1, (horizontalCuts[i+1] - horizontalCuts[i]));
        }
        
        for(int i=0; i<verticalCuts.size() - 1; i++){
            m2 = max(m2, (verticalCuts[i+1] - verticalCuts[i]));
        }
        
        // return (m1%1000000007 * m2%1000000007) % 1000000007;
        return ((long)m1 * (long)m2) % 1000000007L;
    }
};



