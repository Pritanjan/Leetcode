// ROTATING 90 DEGREE CLOCKWISE
// APPROACH 1

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int R = matrix.size();
        int C = matrix[0].size();        
        for(int i=0; i<R-1; i++){
            for(int j=i+1; j<C; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        for(int i=0; i<(C/2); i++){
            for(int j=0; j<R; j++){
                swap(matrix[j][i], matrix[j][C-1-i]);
            }
        }
    }
};


// OR


class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n/2;i++) {
            for(int j=0;j<(n+1)/2;j++) {
                int temp=matrix[i][j];
                matrix[i][j]=matrix[n-j-1][i];
                matrix[n-j-1][i]=matrix[n-i-1][n-j-1];
                matrix[n-i-1][n-j-1]=matrix[j][n-i-1];
                matrix[j][n-i-1]=temp;
            }
        }
    }
};





// APPROACH 2

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) { 
        int L = 0;
        int R = matrix.size() - 1;
        while(L < R){
            for(int i=0; i<(R-L); i++){
                swap(matrix[L][L+i], matrix[L+i][R]);
                swap(matrix[L][L+i], matrix[R][R-i]);
                swap(matrix[L][L+i], matrix[R-i][L]);
            }
            L++;
            R--;
        }
        
    }
};

/*
    Input 
    1, 2, 3
    4, 5, 6
    7, 8, 9 


    for-loop 1 
    swap1               swap2               swap3
    1<->3               3<->9              9<->7

    3, 2, 1            9, 2, 1            7, 2, 1
    4, 5, 6    =>      4, 5, 6    =>      4, 5, 6
    7, 8, 9            7, 8, 3            9, 8, 3

    

    for-loop 2 
    swap1              swap2              swap3
    2<->6              6<->8              8<->4

    7, 6, 1            7, 8, 1            7, 4, 1
    4, 5, 2    =>      4, 5, 2    =>      8, 5, 2
    9, 8, 3            9, 6, 3            9, 6, 3
    

    output     
    7, 4, 1,
    8, 5, 2,
    9, 6, 3,
*/





// APPROACH 3

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        // transpose the matrix
        int n = matrix.size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<i; j++) {
                swap(matrix[i][j], matrix[j][i]);
                cout<<i<<" "<<j<<endl;
            }
        }
        
        // row reverse code below
        int k;
        for(int i = 0; i < n; i++){
            k = n-1;
            for(int j = 0; j < k; j++){
                swap(matrix[i][j], matrix[i][k]);
                k--;
            }
        }
        
//         // reverse the matrix
//         for(int i=0; i<n; i++)
//             reverse(matrix[i].begin(), matrix[i].end());
    }
};






// ROTATING 90 DEGREE ANTI-CLOCKWISE

// APPROACH 1
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // transpose
        for(int i = 0; i < n; i++){
            for(int j = 0; j < i; j++){
                swap(matrix[i][j], matrix[j][i]);
            }
        }
        
        // column reverse code below
        int k;
        for(int i = 0; i < n; i++){
            k = n-1;
            for(int j = 0; j < k; j++){
                swap(matrix[j][i], matrix[k][i]);    // chage occur at here
                k--;
            }
        }
        
    }
};


