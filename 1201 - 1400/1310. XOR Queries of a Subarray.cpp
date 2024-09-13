// A 1 

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> res;
        for (auto& q : queries) {
            int xorSum = 0;
            for (int i = q[0]; i <= q[1]; i++) {
                xorSum ^= arr[i];
            }
            res.push_back(xorSum);
        }
        return res;
    }
};


