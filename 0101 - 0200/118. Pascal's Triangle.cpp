// A 1

// just do it in a straightforward, each time generate a new line, first push all 1
// vector into res and then update the elements from 1 to i-1.

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;
        for(auto i=0; i<numRows; i++){
            ans.push_back(vector<int>(i+1, 1));
            for(int j=1; j<i; j++){
                ans[i][j] = ans[i-1][j-1] + ans[i-1][j];
            }
        }
        return ans;
    }
};


// OR


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> triangle(numRows);
        
        for(int i=0; i<numRows; i++) {
            triangle[i].resize(i+1);
            triangle[i][0] = 1;
            triangle[i][i] = 1;
            
            for(int j=1; j<i; j++) {
                triangle[i][j] = triangle[i-1][j-1] + triangle[i-1][j];
            }
        }
        
        return triangle;
    }
};


// OR 

// Using a Single Loop and Formula:
// It uses a single loop to generate each row of Pascal's triangle based on the formula
// C(n, k) = C(n, k-1) * (n-k+1) / k.

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i=0; i<numRows; ++i) {
            vector<int> row(i+1, 1);
            for(int j=1; j<i; ++j) {
                // row[j] = res[i-1][j-1] + res[i-1][j];            
                row[j] = row[j - 1] * (i - j + 1) / j;
            }
            res.push_back(row);
        }
        return res;
    }
};






// A 2

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        if(numRows == 0) return ret;
        ret.push_back(vector<int> (1,1));

        for(int i=1; i<numRows; i++){
            vector<int> a(i+1);
            for(int j=0; j<=i; j++){
                if(j == 0 || j == i) a[j] = 1;
                else a[j] = ret[i-1][j-1] + ret[i-1][j];
            }
            ret.push_back(a);
        }
        return ret;
    }
};


// OR


class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        if(numRows == 0) return ret;
        ret.push_back(vector<int> (1,1));

        for(int i=1; i<numRows; i++){
            vector<int> newRow(i+1, 1);
            vector<int> prevRow = ret.back();
            for(int j=1; j<i; j++) {
                newRow[j] = prevRow[j-1] + prevRow[j];
            }
            ret.push_back(newRow);
        }
        return ret;
    }
};






// A 3
