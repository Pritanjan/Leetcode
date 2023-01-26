class Solution {
public:    
    bool findRotation(vector<vector<int>>& matrix, vector<vector<int>>& target) {
        int n = matrix.size();    
        int m = matrix[0].size(); 
       
        // rotation by 0 degree
        if(matrix == target)
            return true;
        
        int deg = 3;
        while(deg--){
            // transpose of matrix
            for(int i=0; i<n; i++) {
                for(int j=0; j<i; j++) {
                    swap(matrix[i][j], matrix[j][i]);
                }
            }

            // reverse each row
            for(int i = 0; i < n; i++){
                int k = n-1;
                for(int j = 0; j < k; j++){
                    swap(matrix[i][j], matrix[i][k]);
                    k--;
                }
            }
            if(matrix == target)
                return true;
        }
        return false;
    }
};







