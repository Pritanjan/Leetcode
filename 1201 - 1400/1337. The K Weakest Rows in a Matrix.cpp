// A 1
// Here we’ll use the total sum of all the 1’s and store them in a pair with a row index.
// We’re using 2 for loops to iterate the given matrix which gives a time complexity of n^2.
// After storing the pair, we’ll sort them based on the lowest sum of each row. It will take nlogn time.
// Then store the first k index from this sorted vector and return the final ans vector.
// Time complexity: O(n^2).

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& matrix, int k) {
        vector< pair<int,int> > v;
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();        
        for(int i=0; i<row; i++){
            int count = 0;
            for(int j=0; j<col; j++){
                if(matrix[i][j] == 1)
                    count++;
            }
            v.push_back(make_pair(count, i));            
        }
        sort(v.begin(), v.end());
        for(int i=0; i<k; i++){
            ans.push_back(v[i].second);
        }
        return ans;
    }
};






// A 2

class Solution {
public:
    struct RowInfo {
        int row;
        int count;
        RowInfo(int r, int c) : row(r), count(c) {}
        // Overload the less than operator for sorting
        bool operator<(const RowInfo& other) const {
            if(count != other.count) {
                return count < other.count;
            }
            return row < other.row;
        }
    };

    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();  
        vector<RowInfo> v;
        for(int i=0; i<m; ++i) {
            int count = 0;
            for(int j=0; j<n; ++j) {
                if(mat[i][j] == 1) count++;
                else break; // Since 1's appear to the left of 0's
            }
            v.push_back(RowInfo(i, count));
        }
        
        // Sort v vector based on counts and original indices
        sort(v.begin(), v.end());        
        // Extract the first k weakest rows' original indices
        vector<int> res;
        for(int i=0; i<k; ++i) {
            res.push_back(v[i].row);
        }
        return res;
    }
};






// A 3
