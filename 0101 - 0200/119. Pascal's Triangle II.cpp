// A 1

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans(rowIndex+1, 0);
        ans[0] = 1;
        for(int i=1; i<=rowIndex; i++){
            for(int j=i; j>0; j--){
                ans[j] += ans[j-1];
            }
        }
        return ans;
    }
};

// n = 2
// ans(1, 0, 0)
// i = 1
// j = 1
// ans[1] = ans[1] + 1  = 0 + 1 = 1
    
    
// i = 2
// j = 2 
// ans[2] = ans[2] + 1 = 0 + 1 = 1
// j = 1
// ans[1] = ans[1] + 1 = 1 + 1 = 2
    
 




// A 2

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row(rowIndex + 1, 1);
        for(int i=1; i<=rowIndex / 2; i++) {
            row[i] = row[rowIndex - i] = (long)row[i-1] * (rowIndex - i+1) / i;
        }
        return row;
    }
};


// OR


class Solution {
public:
    vector<int> getRow(int rowIndex) {        
        vector<int> row(rowIndex + 1, 1);
        long long val = 1;
        for(int i=0; i<=rowIndex; i++) {
            // row.push_back(static_cast<int> (val));
            row[i] = static_cast<int>(val);
            val = val * (rowIndex - i)  / (i+1);
        }
        return row;
    }
};

// T.C. --> O(N)
// S.C. --> O(N)






// A 3 - Recursion

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0) return {1};
        vector<int> prevRow = getRow(rowIndex - 1);
        vector<int> row(rowIndex + 1, 1);
        for(int i=1; i<rowIndex; i++) {
            row[i] = prevRow[i-1] + prevRow[i];
        }
        return row;
    }
};






// A 4 

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> triangle;
        for(int i=0; i<=rowIndex; i++) {
            vector<int> row(i + 1, 1);
            for(int j=1; j<i; j++) {
                row[j] = triangle[i-1][j - 1] + triangle[i - 1][j];
            }
            triangle.push_back(row);
        }
        return triangle[rowIndex];
    }
};


// OR


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> triangle(rowIndex + 1);
        for(int i=0; i<=rowIndex; i++) {
            triangle[i].resize(i+1);
            triangle[i][0] = triangle[i][i] = 1;
            for(int j=1; j<i; j++) {
                triangle[i][j] = triangle[i-1][j - 1] + triangle[i - 1][j];
            }
        }
        return triangle[rowIndex];
    }
};

// T.C. --> O(N ^ 2)
// S.C. --> O(N)

