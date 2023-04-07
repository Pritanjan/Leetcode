// APPROACH 1

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


