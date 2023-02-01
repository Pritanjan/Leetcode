class Solution {
public:
    int findGCD(vector<int>& A) {
        int mx = *max_element(A.begin(), A.end());
        int mi = *min_element(A.begin(), A.end());
        return gcd(mx, mi);
    }
};


