// https://leetcode.com/problems/sum-of-even-numbers-after-queries/

class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& A, vector<vector<int>>& queries) {
        int sum = 0;
        for(auto i : A){
            if(i % 2 == 0)
                sum += i;
        }
        
        vector<int> ans;
        for(int i=0; i<queries.size(); i++){
            int val = queries[i][0];
            int idx = queries[i][1];
            
            if(A[idx] % 2 == 0)
                sum -= A[idx];
            A[idx] += val;
            
            if(A[idx] % 2 == 0)
                sum += A[idx];
            // ans[i] = sum;
            ans.push_back(sum);
        }
        return ans;
    }
};



// Time Complexity: O(N+Q)O(N+Q), where NN is the length of A and QQ is the number of queries.

// Space Complexity: O(Q)O(Q), though we only allocate O(1)O(1) additional space.





