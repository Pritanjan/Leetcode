// https://leetcode.com/problems/spiral-matrix-ii/

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int> (n,0));
        int left = 0, right = n-1, top = 0, bottom = n-1; 
        
        int a = 1;
        
        while(left <= right || top <= bottom){
            for(int i=left; i<=right; i++){
                ans[top][i] = a++;
            }
            top ++;
            
            for(int i=top; i<=bottom; i++){
                ans[i][right] = a++;
            }
            right--;
            
            for(int i=right; i>=left; i--){
                ans[bottom][i] = a++;
            }
            bottom--;
            
            for(int i = bottom; i>=top; i--){
                ans[i][left] =a++;
            }
            left++;
        }
        return ans;
        
    }
};
