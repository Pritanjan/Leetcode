// https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

class Solution {
public:
    int countNegatives(vector<vector<int>>& matrix) {
        
        int row = matrix.size();
        int col = matrix[0].size();
        
        int L = 0;
        int R = col - 1;
        int count = 0;
        
        while(L < row   && R >=0 ){
            if(matrix[L][R] < 0 ){
                count += row - L;
                R--;
            }
            else
                L++;
        }
        return count;
    }
};
