// APPROACH 1 Using 1 extra variable x

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();      // NO. OF ROWS
        int m = matrix[0].size();   // NO. OF COLS
                
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






// APPROACH 2 Without Using  extra variable x

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int n = matrix.size();
        int m = matrix[0].size();
                
        int top = 0, bottom = n - 1, left = 0, right = m - 1;
        int cnt = 0;
                
        while(cnt < m*n) {
            for(int i=left; cnt < m*n and i<=right; i++){
                ans.push_back(matrix[top][i]);
                cnt++;
            }
            top++;
            
            for(int i=top; cnt < m*n and i<=bottom; i++){
                ans.push_back(matrix[i][right]);
                cnt++;
            }
            right--;
                
            for(int i=right; cnt < m*n and i>=left; i--){
                ans.push_back(matrix[bottom][i]);
                cnt++;
            }
            bottom--;
            
            for(int i=bottom; cnt < m*n and i>=top; i--){
                ans.push_back(matrix[i][left]);
                cnt++;
            }
            left++;   
        }
        return ans;
    }
};






// APPROACH 3 RECURSION

class Solution {
public:
    void spiralOrder(vector<vector<int>>& matrix, vector<int>& res, int top, int bottom, int left, int right) {
        if(top > bottom || left > right) return ;        
        for(int j=left; j<=right; ++j) res.push_back(matrix[top][j]);
        for(int i=top+1; i<=bottom; ++i) res.push_back(matrix[i][right]);
        if(top < bottom && left < right) {
            for(int j=right-1; j>left; --j) res.push_back(matrix[bottom][j]);
            for(int i=bottom; i>top; --i) res.push_back(matrix[i][left]);
        }
        spiralOrder(matrix, res, top + 1, bottom - 1, left + 1, right - 1);
    }

    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return vector<int>();        
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> res;
        spiralOrder(matrix, res, 0, m - 1, 0, n - 1);
        return res;
    }
};




