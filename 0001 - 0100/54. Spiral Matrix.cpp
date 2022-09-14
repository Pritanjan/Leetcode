// https://leetcode.com/problems/spiral-matrix/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();
                
        int top = 0, bottom = n - 1, left = 0, right = m - 1;
        int x = 1;
        
        while(top <= bottom && left <= right){
            if(x == 1){
                for(int i=left; i<=right; i++){
                    ans.push_back(matrix[top][i]);
                }
                top++;
                x = 2;
            }
            else if(x == 2){
                for(int i=top; i<=bottom; i++){
                    ans.push_back(matrix[i][right]);
                }
                right--;
                x = 3;
            }
            else if(x == 3){
                for(int i=right; i>=left; i--){
                    ans.push_back(matrix[bottom][i]);
                }
                bottom--;
                x = 4;
            }
            else if(x == 4){
                for(int i=bottom; i>=top; i--){
                    ans.push_back(matrix[i][left]);
                }
                left++;
                x = 1;
            }
        }
        return ans;
    }
};
