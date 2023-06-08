// APPROACH 1 [ BRUTE FOCE ]


class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        // Iterate on all elements of the matrix one by one.
        for(auto& row : grid) {
            for(auto& element : row) {
                // If the current element is negative, we count it.
                if(element < 0) {
                    count++;
                }
            }
        }
        return count;
    }
};

// T.C. --> O(m*n)
// S.C. --> O(1)



// APPROACH 2

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
                count += row - L;   // All remaining elements in the current column are negative
                R--;
            }
            else  L++;
        }
        return count;
    }
};




// T.C. --> O(m+n)






// APPROACH 2 [ BINARY SEARCH USING STL] 

class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid[0].size();
        // Iterate on all rows of the matrix one by one.
        for(auto& row : grid) {
            // Using binary search find the index of the first negative element.
            int index = upper_bound(row.begin(), row.end(), 0, greater<int>()) - row.begin();
            // 'index' points to the first negative element,
            // which means 'n - index' is the number of all negative elements.
            count += (n - index);
        }
        return count;
    }
};



// T.C. --> O(m log n)
// For each row of the matrix we perform a binary search which will take O(log⁡n) time.
// Thus, for mmm rows, overall we will take O(m log n) time.
// S.C. --> O(1)







// APPROACH 2 [ BINARY SEARCH wirthout USING STL] 


class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int count = 0;
        int n = grid[0].size();

        // Iterate on all rows of the matrix one by one.
        for(auto& row : grid) {
            // Using binary search find the index of the first negative element.
            int index = binarySearch(row, 0, n - 1);

            // 'index' points to the first negative element,
            // which means 'n - index' is the number of all negative elements.
            count += (n - index);
        }
        return count;
    }
private:
    int binarySearch(vector<int>& row, int low, int high) {
        while(low <= high) {
            int mid = low + (high - low) / 2;

            // If the middle element is negative, search in the left half.
            if(row[mid] < 0) high = mid - 1;
            // If the middle element is non-negative, search in the right half.
            else low = mid + 1;
            
        }
        // Return the index of the first negative element.
        return low;
    }
};
