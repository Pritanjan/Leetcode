// https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

//Here we’ll use the total sum of all the 1’s and store them in a pair with a row index.
//
//We’re using 2 for loops to iterate the given matrix which gives a time complexity of n^2.
//
//After storing the pair, we’ll sort them based on the lowest sum of each row. It will take nlogn time.
//
//Then store the first k index from this sorted vector and return the final ans vector.
//
//Time complexity: O(n^2).

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
