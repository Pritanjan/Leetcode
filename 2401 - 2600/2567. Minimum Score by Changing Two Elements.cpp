class Solution {
public:
    int minimizeSum(vector<int>& A) {
        int m = A.size();
        
        sort(A.begin(), A.end());
        // int p = min(A[m-1] - A[0], min(A[m-1] - A[2], min(A[m-3] - A[0], A[m-2] - A[1])))  ;
        int p = (A[m-3] - A[0]);
        int q = (A[m-2] - A[1]);
        int r = (A[m-1] - A[2]);
        
        return min(p, min(q,r));
    }
};






