// APPROACH 1 


class Solution {
public:
    int diagonalSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int sum = 0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i == j || i+j == n-1 )
                    sum += matrix[i][j];
            }
        }
        return sum;
    }
};








// APPROACH 2


class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int ans = 0;

        for(int i=0; i<n; i++) {
            // Add elements from primary diagonal.
            ans += mat[i][i];
            // Addd elements from secondary diagonal.
            ans += mat[n - 1 - i][i];
        }
        
        // If n is odd, subtract the middle element as its added twice.
        if(n % 2 != 0) ans -= mat[n / 2][n / 2];

        return ans;
    }
};


// T.C. --> O(n^2) 
// S.C. --> O(1)







// APPROACH 3


class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        int n = mat.size();
        int sum = 0;
        for(int i=0; i<n; i++) {
            sum += mat[i][i]; // Add primary diagonal element
            if (i != n - i - 1) { // Check if element is not on primary diagonal
                sum += mat[i][n - i - 1]; // Add non-primary element of secondary diagonal
            }
        }
        return sum;
    }
};




