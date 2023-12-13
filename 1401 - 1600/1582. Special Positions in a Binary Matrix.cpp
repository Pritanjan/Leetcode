// A 1 

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int ans = 0;
        int m = mat.size();
        int n = mat[0].size();
        
        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if (mat[row][col] == 0) {
                    continue;
                }                
                bool good = true;
                for(int r=0; r<m; r++) {
                    if (r != row && mat[r][col] == 1) {
                        good = false;
                        break;
                    }
                }
                for(int c=0; c<n; c++) {
                    if (c != col && mat[row][c] == 1) {
                        good = false;
                        break;
                    }
                }       
                if (good) {
                    ans++;
                }
            }
        }        
        return ans;
    }
};






// A 2 - Using Count Arrays

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<int> rowCnt(m, 0);
        vector<int> colCnt(n, 0);

        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                rowCnt[i] += mat[i][j];
                colCnt[j] += mat[i][j];
            }
        }

        int cnt = 0;
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(mat[i][j] == 1 && rowCnt[i] == 1 && colCnt[j] == 1) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};






// A 3 

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        unordered_set<int> rows, cols;

        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(mat[i][j] == 1) {
                    rows.insert(i);
                    cols.insert(j);
                }
            }
        }

        int cnt = 0;
        for(auto i : rows) {
            for(auto j : cols) {
                if(mat[i][j] == 1) {
                    bool isSpecial = true;
                    for(int k=0; k<m; ++k) {
                        if(k != i && mat[k][j] == 1) {
                            isSpecial = false;
                            break;
                        }
                    }
                    for(int k=0; k<n; ++k) {
                        if(k != j && mat[i][k] == 1) {
                            isSpecial = false;
                            break;
                        }
                    }
                    if (isSpecial) {
                        cnt++;
                    }
                }
            }
        }
        return cnt;
    }
};






// A 4 - use bitsets

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<bitset<500>> rowBits(m, 0);
        vector<bitset<500>> colBits(n, 0);

        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(mat[i][j] == 1) {
                    rowBits[i].set(j);
                    colBits[j].set(i);
                }
            }
        }

        int cnt = 0;
        for(int i=0; i<m; ++i) {
            for(int j=0; j<n; ++j) {
                if(mat[i][j] == 1 && rowBits[i].count() == 1 && colBits[j].count() == 1) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};






// A 5 

Approach 5: Using Matrix Transpose

int numSpecial(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> transpose(n, vector<int>(m, 0));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            transpose[j][i] = mat[i][j];
        }
    }

    int count = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mat[i][j] == 1 && count(mat[i].begin(), mat[i].end(), 1) == 1 &&
                count(transpose[j].begin(), transpose[j].end(), 1) == 1) {
                count++;
            }
        }
    }
    return count;
}



Approach 6: Using 2D Prefix Sum

int numSpecial(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> rowSum(m, vector<int>(n, 0));
    vector<vector<int>> colSum(m, vector<int>(n, 0));

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            rowSum[i][j] = (j > 0 ? rowSum[i][j - 1] : 0) + mat[i][j];
            colSum[i][j] = (i > 0 ? colSum[i - 1][j] : 0) + mat[i][j];
        }
    }

    int count = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mat[i][j] == 1 && rowSum[i][n - 1] - rowSum[i][j] == 1 && colSum[m - 1][j] - colSum[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}




Approach 7: Using Row and Column Arrays

int numSpecial(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<int> rowSum(m, 0);
    vector<int> colSum(n, 0);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            rowSum[i] += mat[i][j];
            colSum[j] += mat[i][j];
        }
    }

    int count = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mat[i][j] == 1 && rowSum[i] == 1 && colSum[j] == 1) {
                count++;
            }
        }
    }
    return count;
}



Approach 8: Using Set Intersection

int numSpecial(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    unordered_set<int> specialRows, specialCols;

    for (int i = 0; i < m; ++i) {
        if (count(mat[i].begin(), mat[i].end(), 1) == 1) {
            specialRows.insert(i);
        }
    }

    for (int j = 0; j < n; ++j) {
        vector<int> col;
        for (int i = 0; i < m; ++i) {
            col.push_back(mat[i][j]);
        }
        if (count(col.begin(), col.end(), 1) == 1) {
            specialCols.insert(j);
        }
    }

    int count = 0;
    for (int i : specialRows) {
        for (int j : specialCols) {
            if (mat[i][j] == 1) {
                count++;
            }
        }
    }
    return count;
}


Approach 9: Using Row and Column Flags

int numSpecial(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<bool> isSpecialRow(m, false);
    vector<bool> isSpecialCol(n, false);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mat[i][j] == 1) {
                isSpecialRow[i] = true;
                isSpecialCol[j] = true;
            }
        }
    }

    int count = 0;
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (mat[i][j] == 1 && isSpecialRow[i] && isSpecialCol[j]) {
                count++;
            }
        }
    }
    return count;
}


Approach 10: Using Count and Accumulate

int numSpecial(vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();
    vector<int> rowCount(m);
    vector<int> colCount(n);

    iota(rowCount.begin(), rowCount.end(), 0);
    iota(colCount.begin(), colCount.end(), 0);

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            rowCount[i] += mat[i][j];
            colCount[j] += mat[i][j];
        }
    }

    int count = 0;
    for (int i : rowCount) {
        for (int j : colCount) {
            count += mat[i][j] == 1;
        }
    }
    return count;
}
