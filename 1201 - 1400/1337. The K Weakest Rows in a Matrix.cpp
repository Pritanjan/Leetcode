// A 1
// Here we’ll use the total sum of all the 1’s and store them in a pair with a row index.
// We’re using 2 for loops to iterate the given matrix which gives a time complexity of n^2.
// After storing the pair, we’ll sort them based on the lowest sum of each row. It will take nlogn time.
// Then store the first k index from this sorted vector and return the final ans vector.
// Time complexity: O(n^2).

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& matrix, int k) {
        // pair: (count of soldiers, row index)
        vector< pair<int,int> > v;
        int row = matrix.size();
        int col = matrix[0].size();        

        for(int i=0; i<row; i++){
            int count = 0;
            for(int j=0; j<col; j++){
                if(matrix[i][j] == 1) count++;
                // else break;
            }
            v.push_back(make_pair(count, i));
            // Store count and row index as a pair         
        }
        
        // Sort the pairs based on counts and row indices
        sort(v.begin(), v.end());
        vector<int> ans;
        for(int i=0; i<k; i++) {
            // Extract the row index
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
// first, counting the number of soldiers in each row, and then finding the k weakest rows
// using custom comparator with partial_sort

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<int> cnts(m); // To store the count of soldiers in each row
        
        // Step 1: Count the number of soldiers in each row
        for(int i=0; i<m; ++i) {
            cnts[i] = accumulate(mat[i].begin(), mat[i].end(), 0);
        }
        
        // Step 2: Define a custom comparator for partial_sort
        auto compare = [&cnts](int a, int b) {
            if(cnts[a] != cnts[b]) {
                return cnts[a] < cnts[b];
            }
            return a < b;
        };
        
        // Create a vector of row indices [0, 1, 2, ..., m-1]
        vector<int> idx(m);
        iota(idx.begin(), idx.end(), 0);
        
        // Use partial_sort to find the k weakest rows efficiently
        partial_sort(idx.begin(), idx.begin() + k, idx.end(), compare);
        
        // Extract the first k row indices
        return vector<int>(idx.begin(), idx.begin() + k);
    }
};






// A 4 

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int m = mat.size();
        int n = mat[0].size();
        
        vector<int> res;
        // Binary search for the weakest row
        auto tmp = [&](int idx) {
            int L = 0;
            int R = n - 1;
            while(L <= R) {
                int mid = L + (R - L) / 2;
                if(mat[idx][mid] == 1) L = mid + 1;
                else R = mid - 1;
            }
            return L; // Number of soldiers in the weakest row
        };
        
        // Create a vector of pairs (number of soldiers, row index)
        vector<pair<int, int>> cnts;
        for(int i=0; i<m; ++i) {
            int sol = tmp(i);
            cnts.push_back({sol, i});
        }
        
        // Custom comparator to sort based on soldiers and row indices
        sort(cnts.begin(), cnts.end(), [](pair<int, int>& a, pair<int, int>& b) {
            if(a.first != b.first) return a.first < b.first;
            return a.second < b.second;
        });
        
        // Extract the k weakest rows
        for(int i=0; i<k; ++i) {
            res.push_back(cnts[i].second);
        }        
        return res;
    }
};





// A 5
