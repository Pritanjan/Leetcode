class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& A) {
        int n = A.size();
        vector<int> v(n);
        for(int i=0; i<n; i++){
            v[i]  = -1;
            for(int j=1; j<n; j++){
                if(A[i] < A[(i+j) % n]){
                    v[i] = A[(i+j) % n];
                    // v.push_back(A[j]);
                    break;
                }                  
            }
        }
        return v;
    }
};


