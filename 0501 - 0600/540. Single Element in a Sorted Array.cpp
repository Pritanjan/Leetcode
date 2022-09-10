class Solution {
public:
    int singleNonDuplicate(vector<int>& A) {
        int L = 0;
        int R = A.size()-1;
        while(L < R){
            int mid = L + (R-L)/2;
            if(mid % 2 == 0 and A[mid] == A[mid+1] or mid % 2 == 1 and A[mid] == A[mid-1])
                L = mid + 1;
            else
                R = mid;
        }
        return A[L];
    }
};



class Solution {
public:   
    int singleNonDuplicate(vector<int>& A) {
        int x = 0;
        int n = A.size();
        for(int i=0; i<n; i++){
            x = x ^ A[i];
        }
        return x;
    }
};

// i) xor of x with 0 always give x.   x ^ 0 = x
// ii) xor of same elements give 0.    x ^ x = 0
// iii) xor in any order give same results.
