// APPROACH 1

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>> mat(m+n, vector<int>());
        vector<int> v;
        
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                mat[i+j].push_back(matrix[i][j]);
            }
        }
      
        for(int i=0; i<mat.size(); i++) {
            if(i%2 == 0) reverse(mat[i].begin(), mat[i].end());
            for(int j=0; j<mat[i].size(); j++) v.push_back(mat[i][j]);
        }
        return v;
    }
};


// 1 1     1 2     1 3
// 2 1     2 2     2 3
// 3 1     3 2     3 3

// mat = 1 2 3 4 5 6 7 8 9
//       2 4 6 8
//       8 6 4 2









class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int flag=-1;
        int m=mat.size();
        int n=mat[0].size();
        vector<int> result;
        result.resize(m*n);
        result[0] = mat[0][0];
        int i=0,j=0;
        for(int k=1;k<m*n;k++)
        {
            i+=flag;
            j-=flag;
            if(i<0)
            {
                flag=-flag;
                if(j>=0 && j<n){
                    i++;
                }
                else if(j>=n)
                {
                    i+=2;
                    j--;
                }
            }
            if(j<0)
            {
                flag=-flag;
                if(i>=0 && i<m){
                    j++;
                }
                else if(i>=m)
                {
                    j+=2;
                    i--;
                }
            }
            if(i>=m && j>=0 && j<n)
            {
                flag=-flag;
                j+=2;
                i--;
            }
            if(j>=n && i>=0 && i<m)
            {
                flag=-flag;
                i+=2;
                j--;
            }
            result[k]=mat[i][j];
        }
        return result;
    }
};
