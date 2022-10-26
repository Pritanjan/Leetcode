class Solution {
public:
    bool checkSubarraySum(vector<int>& A, int k) {
        int n = A.size() ;
        vector<int> v(n,0);
        v[0] = A[0];
        for(int i=1; i<n; i++){
            v[i] = v[i-1] + A[i];
        }
        
        unordered_map<int, int> ump;
            ump[0]++;
        
        for(int i=1; i<n; i++){
            if(ump[v[i] % k] != 0)
                return true;
            else
                ump[v[i-1] % k]++;
        }
        return false;        
    }
};



