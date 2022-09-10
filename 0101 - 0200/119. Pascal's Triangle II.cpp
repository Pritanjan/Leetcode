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

// ans(1,0,0)
// i = 1
// j = 1
// ans[1] = ans[1] + 1  = 0 + 1 = 1
    
    
// i = 2
// j = 2 
// ans[2] = ans[2] + 1 = 0 + 1 = 1
// j = 1
// ans[1] = ans[1] + 1 = 1 + 1 = 2
    

    
